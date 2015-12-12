#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

#include "lib/qobjectlistmodel.h"
#include "lib/qquicklist.h"
#include "Task.h"

class Engine : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QObjectListModel * taskModel READ taskModel NOTIFY taskModelChanged)

public:
	explicit Engine(QObject *parent = 0);

	QObjectListModel *taskModel() { return m_taskList.getModel(); }

signals:
	void taskModelChanged();

private:
	QQuickList<Task> m_taskList;
};

#endif // ENGINE_H
