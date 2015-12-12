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

public:
	explicit Engine(QObject *parent = 0);

	QObjectListModel *taskModel() { return m_taskList.getModel(); }
	QObjectListModel *sidebarModel() { return m_sidebarList.getModel(); }

signals:
	void taskModelChanged();
	void sidebarModelChanged();

private:
	QQuickList<Task> m_taskList;
	QQuickList<SidebarItem> m_sidebarList;
};

#endif // ENGINE_H
