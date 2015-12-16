#include "Engine.h"

#include "../model/repository/user/UserRepository.h"
#include "../model/repository/category/CategoryRepository.h"

#include <string>

using todos_model_entity::User;
using todos_model_repository::UserRepository;
using todos_model_entity::Category;
using todos_model_repository::CategoryRepository;

using SidebarItemType = SidebarItem::SidebarItemType;

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

bool Engine::addTask(const QString &title, int priority, const QString &dueDate, const QString &commentary)
{

	emit taskModelChanged();

	return true;
}

bool Engine::removeTask(int index)
{
	if (index < 0 || index >= m_taskList.size())
		return false;

	m_taskList.removeAt(index);

	emit taskModelChanged();

	return true;
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

	m_categoryList.append(CategotyObject(foundEntity.get()));

	emit categoryModelChanged();
}

bool Engine::deleteCategory(unsigned long categoryId)
{
	CategoryRepository repository(m_db);

	repository.Delete(categoryId);

	updateCategoryList();
}

bool Engine::updateCategory(unsigned long categoryId, const QString &newName)
{
	CategoryRepository repository(m_db);

	auto foundEntity = repository.FindOneById(categoryId);
	foundEntity->SetName(newName.toStdString());
	repository.Update(categoryId, foundEntity);

	updateCategoryList();
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
		m_categoryList.append(CategotyObject(category));
	}

	emit categoryModelChanged();
}
