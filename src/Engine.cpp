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
	, m_db(nullptr)
{
	m_db.Open(dbFileName);
	m_db.CreateTables();
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

bool Engine::addTask(unsigned long categoryId, const QString &title, const QString &priority, const QDateTime &dueDate, const QDateTime &reminderDate, const QString &status)
{
	TaskRepository repository(m_db);

	Task entity(0, categoryId, title.toStdString() , TypeConverter::toPriority(priority), dueDate, reminderDate, TypeConverter::toStatus(status));
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

bool Engine::deleteTask(unsigned long taskId)
{
	TaskRepository repository(m_db);
	auto foundEntity = repository.FindOneById(taskId);
	ASSERT_TRUE(foundEntity != nullptr);

	unsigned long deletedCount = repository.Delete(insertId);
	ASSERT_TRUE(deletedCount == 1);

	foundEntity = repository.FindOneById(insertId);
	EXPECT_TRUE(foundEntity == nullptr);
}

bool Engine::updateTask(unsigned long taskId, const QString &newTitle, const QString &newPriority, const QDateTime &newDueDate, const QDateTime &newReminderDate, const QString &newStatus)
{

}

bool Engine::doneTask(unsigned long taskId)
{

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

bool Engine::deleteCategory(unsigned long categoryId)
{
	CategoryRepository repository(m_db);

	repository.Delete(categoryId);

	updateCategoryList();
	return true;
}

bool Engine::updateCategory(unsigned long categoryId, const QString &newName)
{
	CategoryRepository repository(m_db);

	auto foundEntity = repository.FindOneById(categoryId);
	foundEntity->SetName(newName.toStdString());
	repository.Update(categoryId, *foundEntity.get());

	updateCategoryList();
	return true;
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

	auto foundTask = repository.FindAll(m_userId);
	for (auto category : foundCategory) {
		m_categoryList.append(new CategotyObject(category.get(), 0));
	}

	emit categoryModelChanged();
}
