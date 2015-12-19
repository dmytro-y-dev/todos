#include "Engine.h"

#include "TypeConverter.h"

#include "../model/repository/user/UserRepository.h"
#include "../model/repository/category/CategoryRepository.h"
#include "../model/repository/task/TaskRepository.h"

#include <string>

using todos_model_entity::User;
using todos_model_repository::UserRepository;
using todos_model_entity::Category;
using todos_model_repository::CategoryRepository;
using todos_model_entity::Task;
using todos_model_repository::TaskRepository;

namespace
{
	const char* dbFileName = "todos.sqlite3";

	inline const char* to_char_ptr(const QString& str) {
		std::string stdString = str.toStdString();
		const char* result = stdString.c_str();
		return result;
	}
}

Engine::Engine(QObject *parent)
	: QObject(parent)
	, m_taskSortSettingsField(TaskRepository::TaskSortSettings::Field::TITLE)
	, m_taskSortSettingsOrder(TaskRepository::TaskSortSettings::Order::ASC)
	, m_db(nullptr)
{
	m_db.Open(dbFileName);
	m_db.CreateTables();

	initializeTestData();
}

Engine::~Engine()
{
	m_db.Close();
}

bool Engine::logIn(const QString &name, const QString &password)
{
	UserRepository repository(m_db);

	auto foundUser = repository.FindOneByLogin(name.toStdString());

	if (foundUser == nullptr || foundUser->GetPassword() != password.toStdString())
		return false;

	if (m_userName != name) {
		m_userName = name;
		userNameChanged();
	}

	m_userId = foundUser->GetId();
	updateCategoryList();
	updateTaskList();

	return true;
}

bool Engine::signUp(const QString &name, const QString &password)
{
	UserRepository repository(m_db);

	User newUser(0, to_char_ptr(name), to_char_ptr(password), QDateTime::currentDateTime());
	unsigned long insertId = repository.Insert(newUser);

	if (insertId == 0)
		return false;

	auto foundUser = repository.FindOneById(insertId);

	if(foundUser == nullptr || foundUser->GetLogin() != newUser.GetLogin())
		return false;

	if (m_userName != name) {
		m_userName = name;
		userNameChanged();
	}

	m_userId = foundUser->GetId();

	return true;
}

bool Engine::addTask(const QString &title, const QString &priority, const QDateTime &dueDate, const QDateTime &reminderDate, const QString &status)
{
	TaskRepository repository(m_db);

	Task entity(0, m_categoryId, title.toStdString() , TypeConverter::toPriority(priority), dueDate, reminderDate, TypeConverter::toStatus(status));
	unsigned long insertId = repository.Insert(entity);
	if (insertId == 0)
		return false;

	auto foundEntity = repository.FindOneById(insertId);
	if (foundEntity == nullptr)
		return false;

	m_taskList.append(new TaskObject(foundEntity.get(),0));

	emit taskModelChanged();
	return true;
}

bool Engine::deleteTask(int index)
{
	if (index < 0 || index >= m_taskList.size())
		return false;

	auto taskId = m_taskList.at(index)->id();

	TaskRepository repository(m_db);
	unsigned long deletedCount = repository.Delete(taskId);
	if (deletedCount == 0)
		return false;

	updateTaskList();
	return true;
}

bool Engine::updateTask(int index, const QString &newTitle, const QString &newPriority, const QDateTime &newDueDate, const QDateTime &newReminderDate)
{
	if (index < 0 || index >= m_taskList.size())
		return false;

	auto taskId = m_taskList.at(index)->id();

	TaskRepository repository(m_db);
	TaskRepository::EntitySharedPtr foundEntity = repository.FindOneById(taskId);
	if (foundEntity == nullptr)
		return false;

	foundEntity->SetTitle(newTitle.toStdString());
	foundEntity->SetPriority(TypeConverter::toPriority(newPriority));
	foundEntity->SetDueDate(newDueDate);
	foundEntity->SetReminderDate(newReminderDate);

	repository.Update(taskId, *foundEntity.get());

	updateTaskList();
	return true;
}

bool Engine::doneTask(int index)
{
	if (index < 0 || index >= m_taskList.size())
		return false;

	auto taskId = m_taskList.at(index)->id();

	TaskRepository repository(m_db);
	TaskRepository::EntitySharedPtr foundEntity = repository.FindOneById(taskId);
	if (foundEntity == nullptr)
		return false;

	foundEntity->SetStatus(Task::Status::COMPLETED);

	repository.Update(taskId, *foundEntity.get());

	updateTaskList();
	return true;
}

QString Engine::getTaskTitleByIndex(int index)
{
	if (index < 0 || index >= m_taskList.size())
		return QString();

	return m_taskList.at(index)->title();
}

QString Engine::getTaskPriorityByIndex(int index)
{
	if (index < 0 || index >= m_taskList.size())
		return QString();

	return m_taskList.at(index)->priority();
}

QDateTime Engine::getTaskDueDateByIndex(int index)
{
	if (index < 0 || index >= m_taskList.size())
		return QDateTime();

	return m_taskList.at(index)->dueDate();
}

QDateTime Engine::getTaskReminderDateByIndex(int index)
{
	if (index < 0 || index >= m_taskList.size())
		return QDateTime();

	return m_taskList.at(index)->reminderDate();
}

bool Engine::addCategory(const QString &name)
{
	CategoryRepository repository(m_db);

	auto foundCategory = repository.FindAll(m_userId);
	for (auto category : foundCategory) {
		if (category->GetName() == name.toStdString())
			return false;
	}

	Category newCategory(0, m_userId, name.toStdString());
	unsigned long insertId = repository.Insert(newCategory);
	if (insertId == 0)
		return false;

	auto foundEntity = repository.FindOneById(insertId);
	if (foundEntity == nullptr)
		return false;

	m_categoryList.append(new CategotyObject(foundEntity.get(), 0));

	emit categoryModelChanged();
	return true;
}

bool Engine::deleteCategory(int categoryIndex)
{
	CategoryRepository repository(m_db);

	if (categoryIndex < 0 || categoryIndex >= m_categoryList.size())
		return false;

	auto categoryId = m_categoryList.at(categoryIndex)->id();

	repository.Delete(categoryId);

	updateCategoryList();
	return true;
}

bool Engine::updateCategory(int categoryIndex, const QString &newName)
{
	CategoryRepository repository(m_db);

	if (categoryIndex < 0 || categoryIndex >= m_categoryList.size())
		return false;

	auto categoryId = m_categoryList.at(categoryIndex)->id();

	auto foundEntity = repository.FindOneById(categoryId);
	foundEntity->SetName(newName.toStdString());
	repository.Update(categoryId, *foundEntity.get());

	updateCategoryList();
	return true;
}

QString Engine::getCategoryNameByIndex(int index)
{
	if (index < 0 || index >= m_categoryList.size())
		return QString();

	return m_categoryList.at(index)->name();
}

void Engine::enableFilterByCategoty(bool enable)
{
	m_taskFilterSettings.EnableFilterByCategory(enable);
}

void Engine::setFilterByCategoty(const QString &categoryName)
{
	m_taskFilterSettings.SetCategory(categoryName.toStdString());
}

void Engine::enableFilterByDueDate(bool enable)
{
	m_taskFilterSettings.EnableFilterByCategory(enable);
}

void Engine::setFilterByDueDate(const QDateTime &firstDate, const QDateTime &lastDate)
{
	m_taskFilterSettings.SetDueDateLowerLimit(firstDate);
	m_taskFilterSettings.SetDueDateUpperLimit(lastDate);
}

void Engine::setSortField(const QString &sortField)
{
	m_taskSortSettingsField = TypeConverter::toTaskSortField(sortField);
	updateTaskList();
}

QString Engine::userName() const
{
	return m_userName;
}

void Engine::updateCategoryList()
{
	CategoryRepository repository(m_db);

	m_categoryList.clear();

	auto foundCategory = repository.FindAll(m_userId);
	for (auto category : foundCategory) {
		m_categoryList.append(new CategotyObject(category.get(), 0));
	}

	emit categoryModelChanged();
}

void Engine::updateTaskList()
{
	TaskRepository repository(m_db);

	m_taskList.clear();

	auto foundTask = repository.FindAll(m_userId,TaskRepository::TaskSortSettings(m_taskSortSettingsField, m_taskSortSettingsOrder), m_taskFilterSettings);
	for (auto category : foundTask) {
		m_taskList.append(new TaskObject(category.get(), 0));
	}

	emit taskModelChanged();
}

void Engine::initializeTestData()
{
	if (!logIn("TEST_USER","12345")) {
		signUp("TEST_USER", "12345");

	addCategory("Category1");
	addCategory("Category2");
	addCategory("Category3");
	addCategory("Category4");
	addCategory("Category5");

	m_categoryId = m_categoryList.at(0)->id();

	addTask("Task1_1", "Low",    QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Completed");
	addTask("Task2_1", "Normal", QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Uncompleted");
	addTask("Task3_1", "Low",    QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Completed");
	addTask("Task4_1", "High",   QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Uncompleted");

	m_categoryId = m_categoryList.at(1)->id();

	addTask("Task1_2", "Low",    QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Completed");
	addTask("Task2_2", "High",   QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Uncompleted");
	addTask("Task3_2", "Normal", QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Uncompleted");
	addTask("Task4_2", "Low",    QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Completed");

	m_categoryId = m_categoryList.at(2)->id();

	addTask("Task1_3", "Low",    QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Completed");
	addTask("Task2_3", "High",   QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Uncompleted");

	m_categoryId = m_categoryList.at(3)->id();

	addTask("Task1_4", "Low",    QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Completed");
	addTask("Task2_4", "High",   QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Uncompleted");

	m_categoryId = m_categoryList.at(4)->id();

	addTask("Task1_5", "Low",    QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Completed");
	addTask("Task2_5", "High",   QDateTime::currentDateTime(), QDateTime::currentDateTime(), "Uncompleted");

	}

	updateCategoryList();
	m_categoryId = m_categoryList.first()->id();
}
