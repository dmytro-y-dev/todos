#ifndef SIDEBARITEM_H
#define SIDEBARITEM_H

#include <QObject>

class SidebarItem : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString type READ typeToString               NOTIFY typeChanged)
	Q_PROPERTY(QString name READ name         WRITE setName NOTIFY nameChanged)

public:
	enum class SidebarItemType
	{
		CategoryName,
		FilterName,
		SortName
	};
	Q_INVOKABLE SidebarItem(SidebarItemType type, QString name, QObject *parent = 0);
	Q_INVOKABLE SidebarItem(QObject * parent = 0);

	SidebarItemType type() const;
	QString typeToString() const;
	void setType(const SidebarItemType &type);

	QString name() const;
	void setName(const QString &name);

signals:
	void typeChanged();
	void nameChanged();

private:
	SidebarItemType m_type;
	QString m_name;
};

#endif // SIDEBARITEM_H
