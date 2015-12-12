#include "SidebarItem.h"

SidebarItem::SidebarItem(SidebarItem::SidebarItemType type, QString name, QObject *parent)
	: QObject(parent)
	, m_type(type)
	, m_name(name)
{}

SidebarItem::SidebarItem(QObject *parent)
	: QObject(parent)
{}

SidebarItem::SidebarItemType SidebarItem::type() const
{
	return m_type;
}

QString SidebarItem::typeToString() const
{
	switch (m_type) {
	case SidebarItemType::CategoryName:
		return "Categoty";
	case SidebarItemType::FilterName:
		return "Filter";
	case SidebarItemType::SortName:
		return "Sort by";
	}
	return QString();
}

void SidebarItem::setType(const SidebarItemType &type)
{
	m_type = type;
}

QString SidebarItem::name() const
{
	return m_name;
}

void SidebarItem::setName(const QString &name)
{
	m_name = name;
}
