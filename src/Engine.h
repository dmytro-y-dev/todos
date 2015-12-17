#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

#include "lib/qobjectlistmodel.h"
#include "lib/qquicklist.h"
#include "TaskObject.h"
#include "CategotyObject.h"
#include "CommentaryObject.h"

#include "../model/schema/Schema.h"
#include "../model/repository/task/TaskRepository.h"
#include "../model/repository/task/TaskFilterSettings.h"

using todos_model_schema::Schema;
using todos_model_repository::TaskRepository;

class Engine : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QObjectListModel * taskModel       READ taskModel       NOTIFY taskModelChanged)
	Q_PROPERTY(QObjectListModel * categoryModel   READ categoryModel   NOTIFY categoryModelChanged)
	Q_PROPERTY(QObjectListModel * commentaryModel READ commentaryModel NOTIFY commentaryModelChanged)
	Q_PROPERTY(QString userName READ userName NOTIFY userNameChanged)

public:
	explicit Engine(QObject *parent = 0);
	~Engine();

	QObjectListModel *taskModel() { return m_taskList.getModel(); }
	QObjectListModel *categoryModel() {return m_categoryList.getModel(); }
	QObjectListModel *commentaryModel () {return m_commentaryList.getModel(); }

	Q_INVOKABLE bool logIn(const QString &name, const QString &password);
	Q_INVOKABLE bool signUp(const QString &name, const QString &password);

	Q_INVOKABLE bool addTask(unsigned long categoryId, const QString &title, const QString &priority, const QDateTime &dueDate, const QDateTime &reminderDate,const QString &status);
	Q_INVOKABLE bool deleteTask(unsigned long taskId);
	Q_INVOKABLE bool updateTask(unsigned long taskId, const QString &newTitle, const QString &newPriority, const QDateTime &newDueDate, const QDateTime &newReminderDate, const QString &newStatus);
	Q_INVOKABLE bool doneTask(unsigned long taskId);

	Q_INVOKABLE bool addCategory(const QString &name);
	Q_INVOKABLE bool deleteCategory(unsigned long categoryId);
	Q_INVOKABLE bool updateCategory(unsigned long categoryId, const QString &newName);

	Q_INVOKABLE void enableFilterByCategoty(bool enable);
	Q_INVOKABLE void setFilterByCategoty(const QString &categoryName);
	Q_INVOKABLE void enableFilterByDueDate(bool enable);
	Q_INVOKABLE void setFilterByDueDate(const QDateTime &firstDate, const QDateTime &lastDate);

	Q_INVOKABLE void setSortField(const QString &sortType);

	QString userName() const;

signals:
	void taskModelChanged();
	void categoryModelChanged();
	void commentaryModelChanged();
	void userNameChanged();

private:
	void updateCategoryList();
	void updateTaskList();

	QQuickList<TaskObject> m_taskList;
	QQuickList<CategotyObject> m_categoryList;
	QQuickList<CommentaryObject> m_commentaryList;

	QString m_userName;
	unsigned long m_userId;
	unsigned long m_categoryId;
	unsigned long m_taskId;

	TaskRepository::TaskSortSettings::Field m_taskSortSettingsField;
	TaskRepository::TaskSortSettings::Order m_taskSortSettingsOrder;
	TaskRepository::TaskFilterSettings m_taskFilterSettings;

	Schema m_db;
};

#endif // ENGINE_H
