#include "Engine.h"

#include "../model/repository/user/UserRepository.h"

#include <QDebug>

#include <string>

using todos_model_entity::User;
using todos_model_repository::UserRepository;

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

	auto testSidebarData = QList<SidebarItem *>()
			<< new SidebarItem(SidebarItemType::CategoryName, "Category1")
			<< new SidebarItem(SidebarItemType::CategoryName, "Category2")
			<< new SidebarItem(SidebarItemType::CategoryName, "Category3")
			<< new SidebarItem(SidebarItemType::CategoryName, "Category4")
			<< new SidebarItem(SidebarItemType::CategoryName, "Category5")
			<< new SidebarItem(SidebarItemType::FilterName, "Filter1")
			<< new SidebarItem(SidebarItemType::FilterName, "Filter2")
			<< new SidebarItem(SidebarItemType::FilterName, "Filter3")
			<< new SidebarItem(SidebarItemType::FilterName, "Filter4")
			<< new SidebarItem(SidebarItemType::FilterName, "Filter5")
			<< new SidebarItem(SidebarItemType::SortName, "Sort1")
			<< new SidebarItem(SidebarItemType::SortName, "Sort2")
			<< new SidebarItem(SidebarItemType::SortName, "Sort3")
			<< new SidebarItem(SidebarItemType::SortName, "Sort4");
	m_sidebarList.append(testSidebarData);
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

	return true;
}

bool Engine::addTask(const QString &title, int priority, const QString &dueDate, const QString &commentary)
{
	//m_taskList.append(new TaskObject(title, priority, dueDate, commentary, "NotDone"));

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

QString Engine::userName() const
{
	return m_userName;
}
