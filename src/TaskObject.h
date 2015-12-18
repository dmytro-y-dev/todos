#ifndef TASKOBJECT_H
#define TASKOBJECT_H

#include <QObject>

#include <../model/entity/task/Task.h>

using Priority = todos_model_entity::Task::Priority;
using Status   = todos_model_entity::Task::Status;

class TaskObject : public QObject
{
	Q_OBJECT
	Q_PROPERTY(unsigned long id         READ id           WRITE setId           NOTIFY idChanged)
	Q_PROPERTY(unsigned long categoryId READ categoryId   WRITE setCategoryId   NOTIFY categoryIdChanged)
	Q_PROPERTY(QString title            READ title        WRITE setTitle        NOTIFY titleChanged)
	Q_PROPERTY(QString priority         READ priority     WRITE setPriority     NOTIFY priorityChanged)
	Q_PROPERTY(QDateTime dueDate        READ dueDate      WRITE setDueDate      NOTIFY dueDateChanged)
	Q_PROPERTY(QDateTime reminderDate   READ reminderDate WRITE setReminderDate NOTIFY reminderDateChanged)
	Q_PROPERTY(QString status           READ status       WRITE setStatus       NOTIFY statusChanged)

public:
	Q_INVOKABLE TaskObject(unsigned long id, unsigned long categoryId, const QString& title, Priority priority, const QDateTime& dueDate,
						   const QDateTime& reminderDate, Status status, QObject *parent = 0);
	Q_INVOKABLE TaskObject(todos_model_entity::Task * task ,QObject * parent = 0);
	Q_INVOKABLE TaskObject(const TaskObject& other);
	Q_INVOKABLE TaskObject(QObject * parent = 0);

	TaskObject& operator=(const TaskObject &right);

	unsigned long id() const;
	void setId(unsigned long id);

	unsigned long categoryId() const;
	void setCategoryId(unsigned long categoryId);

	QString title() const;
	void setTitle(const QString &title);

	QString priority() const;
	void setPriority(const QString &priority);

	QDateTime dueDate() const;
	void setDueDate(const QDateTime &dueDate);

	QDateTime reminderDate() const;
	void setReminderDate(const QDateTime &reminderDate);

	QString status() const;
	void setStatus(const QString &status);

signals:
	void idChanged();
	void categoryIdChanged();
	void titleChanged();
	void priorityChanged();
	void dueDateChanged();
	void reminderDateChanged();
	void statusChanged();

private:
	unsigned long m_id;
	unsigned long m_categoryId;
	QString m_title;
	QString m_priority;
	QDateTime m_dueDate;
	QDateTime m_reminderDate;
	QString m_status;
};
#endif // TASKOBJECT_H
