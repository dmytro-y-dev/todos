#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

#include "lib/qobjectlistmodel.h"
#include "lib/qquicklist.h"
#include "TaskObject.h"
#include "SidebarItem.h"

#include "../model/schema/Schema.h"

using todos_model_schema::Schema;

class Engine : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QObjectListModel * taskModel    READ taskModel    NOTIFY taskModelChanged)
	Q_PROPERTY(QObjectListModel * sidebarModel READ sidebarModel NOTIFY sidebarModelChanged)
	Q_PROPERTY(QString userName READ userName NOTIFY userNameChanged)

public:
	explicit Engine(QObject *parent = 0);
	~Engine();

	QObjectListModel *taskModel() { return m_taskList.getModel(); }
	QObjectListModel *sidebarModel() { return m_sidebarList.getModel(); }

	Q_INVOKABLE bool logIn(const QString &name, const QString &password);
	Q_INVOKABLE bool signUp(const QString &name, const QString &password);

	Q_INVOKABLE bool addTask(const QString &title, int priority, const QString &dueDate, const QString &commentary);
	Q_INVOKABLE bool removeTask(int index);

	QString userName() const;

signals:
	void taskModelChanged();
	void sidebarModelChanged();
	void userNameChanged();

private:
	QQuickList<TaskObject> m_taskList;
	QQuickList<SidebarItem> m_sidebarList;

	QString m_userName;

	Schema m_db;
};

#endif // ENGINE_H
