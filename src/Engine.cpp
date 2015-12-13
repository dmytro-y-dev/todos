 #include "Engine.h"

using SidebarItemType = SidebarItem::SidebarItemType;

Engine::Engine(QObject *parent)
	: QObject(parent)
{
	auto testTaskData = QList<Task *>()
			<< new Task("Title", 1, "10-10-2015", "Commentary", "Done")
			<< new Task("Title2", 3, "10-12-2015", "Commentary", "Done")
			<< new Task("Title3", 1, "10-12-2015", "Commentary", "Done")
			<< new Task("Title4", 2, "10-11-2015", "Commentary", "Done");
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
}

