#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

#include "lib/qobjectlistmodel.h"
#include "lib/qquicklist.h"
#include "TaskObject.h"
#include "CategotyObject.h"
#include "CommentaryObject.h"

#include "../model/schema/Schema.h"

using todos_model_schema::Schema;

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

	Q_INVOKABLE bool addTask(const QString &title, int priority, const QString &dueDate, const QString &commentary);
	Q_INVOKABLE bool removeTask(int index);

	Q_INVOKABLE bool addCategory(const QString &name);
	Q_INVOKABLE bool deleteCategory(unsigned long categoryId);
	Q_INVOKABLE bool updateCategory(unsigned long categoryId, const QString &newName);

	QString userName() const;

signals:
	void taskModelChanged();
	void categoryModelChanged();
	void commentaryModelChanged();
	void userNameChanged();

private:
	void updateCategoryList();

	QQuickList<TaskObject> m_taskList;
	QQuickList<CategotyObject> m_categoryList;
	QQuickList<CommentaryObject> m_commentaryList;

	QString m_userName;
	unsigned long m_userId;

	Schema m_db;
};

#endif // ENGINE_H
