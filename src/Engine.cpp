#include "Engine.h"

#include <QDebug>

using SidebarItemType = SidebarItem::SidebarItemType;

Engine::Engine(QObject *parent)
	: QObject(parent)
{
	auto testTaskData = QList<TaskQML *>()
			<< new TaskQML("Title", 1, "10-10-2015", "Commentary", "Done")
			<< new TaskQML("Title2", 3, "10-12-2015", "Commentary", "Done")
			<< new TaskQML("Title3", 1, "10-12-2015", "Commentary", "Done")
			<< new TaskQML("Title4", 2, "10-11-2015", "Commentary", "Done");
	m_taskList.append(testTaskData);

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

	m_userName = "Current User";
}

bool Engine::logIn(const QString &email, const QString &password)
{
	// TODO logIn
	qDebug() << "User LogIn email=" << email << " password=" << password;
	return true;
}

bool Engine::signUp(const QString &name, const QString &email, const QString &password)
{
	// TODO signUp
	qDebug() << "User SignUp name=" << name << " email=" << email << " password=" << password;

	if (m_userName != name) {
		m_userName = name;
		userNameChanged();
	}

	return true;
}

bool Engine::addTask(const QString &title, int priority, const QString &dueDate, const QString &commentary)
{
	m_taskList.append(new TaskQML(title, priority, dueDate, commentary, "NotDone"));

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
