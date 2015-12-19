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
	Q_PROPERTY(QString dashboardHeaderText READ dashboardHeaderText NOTIFY dashboardHeaderTextChanged)

public:
	explicit Engine(QObject *parent = 0);
	~Engine();

	QObjectListModel *taskModel() { return m_taskList.getModel(); }
	QObjectListModel *categoryModel() {return m_categoryList.getModel(); }
	QObjectListModel *commentaryModel () {return m_commentaryList.getModel(); }

	Q_INVOKABLE bool logIn(const QString &name, const QString &password);
	Q_INVOKABLE bool signUp(const QString &name, const QString &password);

	Q_INVOKABLE bool addTask(const QString &title, const QString &priority, const QDateTime &dueDate, const QDateTime &reminderDate, const QString &status);
	Q_INVOKABLE bool deleteTask(int index);
	Q_INVOKABLE bool updateTask(int index, const QString &newTitle, const QString &newPriority, const QDateTime &newDueDate, const QDateTime &newReminderDate);
	Q_INVOKABLE bool doneTask(int index);

	Q_INVOKABLE QString getTaskTitleByIndex(int index);
	Q_INVOKABLE QString getTaskPriorityByIndex(int index);
	Q_INVOKABLE QDateTime getTaskDueDateByIndex(int index);
	Q_INVOKABLE QDateTime getTaskReminderDateByIndex(int index);

	Q_INVOKABLE bool addCategory(const QString &name);
	Q_INVOKABLE bool deleteCategory(int categoryIndex);
	Q_INVOKABLE bool updateCategory(int categoryIndex, const QString &newName);

	Q_INVOKABLE QString getCategoryNameByIndex(int index);

	Q_INVOKABLE void enableFilterByCategoty(bool enable);
	Q_INVOKABLE void setFilterByCategoty(const QString &categoryName);
	Q_INVOKABLE void enableFilterByDueDate(bool enable);
	Q_INVOKABLE void setFilterByDueDate(const QDateTime &lowerLimit, const QDateTime &upperLimit);

	Q_INVOKABLE void setSortField(const QString &sortType);

	Q_INVOKABLE void updateCategoryList();
	Q_INVOKABLE void updateTaskList();

	Q_INVOKABLE void changeSortOrder();

	QString userName() const;
	QString dashboardHeaderText() const;

signals:
	void taskModelChanged();
	void categoryModelChanged();
	void commentaryModelChanged();
	void userNameChanged();
	void dashboardHeaderTextChanged();

private:
	void initializeTestData();

	QQuickList<TaskObject> m_taskList;
	QQuickList<CategotyObject> m_categoryList;
	QQuickList<CommentaryObject> m_commentaryList;

	QString m_userName;
	QString m_categoryName;

	unsigned long m_userId;
	unsigned long m_categoryId;
	unsigned long m_taskId;

	TaskRepository::TaskSortSettings::Field m_taskSortSettingsField;
	TaskRepository::TaskSortSettings::Order m_taskSortSettingsOrder;
	TaskRepository::TaskFilterSettings m_taskFilterSettings;

	Schema m_db;
};

#endif // ENGINE_H
