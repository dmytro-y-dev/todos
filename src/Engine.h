#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

#include "lib/qobjectlistmodel.h"
#include "lib/qquicklist.h"
#include "Task.h"
#include "SidebarItem.h"

class Engine : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QObjectListModel * taskModel    READ taskModel    NOTIFY taskModelChanged)
	Q_PROPERTY(QObjectListModel * sidebarModel READ sidebarModel NOTIFY sidebarModelChanged)
	Q_PROPERTY(QString userName READ userName NOTIFY userNameChanged)

public:
	explicit Engine(QObject *parent = 0);

	QObjectListModel *taskModel() { return m_taskList.getModel(); }
	QObjectListModel *sidebarModel() { return m_sidebarList.getModel(); }

	Q_INVOKABLE bool logIn(const QString &email, const QString &password);
	Q_INVOKABLE bool signUp(const QString &name, const QString &email, const QString &password);

	Q_INVOKABLE bool addTask(const QString &title, int priority, const QString &dueDate, const QString &commentary);
	Q_INVOKABLE bool removeTask(int index);

	QString userName() const;

signals:
	void taskModelChanged();
	void sidebarModelChanged();
	void userNameChanged();

private:
	QQuickList<Task> m_taskList;
	QQuickList<SidebarItem> m_sidebarList;

	QString m_userName;
};

#endif // ENGINE_H
