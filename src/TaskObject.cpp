#include "TaskObject.h"

namespace
{
	const QString csLowPriority     = QString("Low");
	const QString csNormalPriority  = QString("Normal");
	const QString csHighPriority    = QString("High");
	const QString csUnknownPriority = QString("Unknown");

	const QString csCompletedStatus   = QString("Completed");
	const QString csUncompletedStatus = QString("Uncompleted");
	const QString csUnknownStatus     = QString("Unknown");


	QString toString(Priority priority) {
		switch (priority) {
		case Priority::LOW:
			return csLowPriority;
		case Priority::NORMAL:
			return csNormalPriority;
		case Priority::HIGH:
			return csHighPriority;
		default:
			return csUnknownPriority;
		}
	}

	Priority toPriority(const QString &str) {
		if (str == csLowPriority) {
			return Priority::LOW;
		} else if (str == csNormalPriority) {
			return Priority::NORMAL;
		} else if (str == csHighPriority) {
			return Priority::HIGH;
		} else {
			return Priority::UNKNOWN;
		}
	}

	QString toString(Status status) {
		switch (status) {
		case Status::COMPLETED:
			return csCompletedStatus;
		case Status::UNCOMPLETED:
			return csUncompletedStatus;
		default:
			return csUnknownStatus;
		}
	}

	Status toStatus(const QString &str) {
		if (str == csCompletedStatus) {
			return Status::COMPLETED;
		} else if (str == csUncompletedStatus) {
			return Status::UNCOMPLETED;
		} else {
			return Status::UNKNOWN;
		}
	}

}

TaskObject::TaskObject(unsigned long id, unsigned long categoryId, const QString &title, Priority priority, const QDateTime &dueDate, const QDateTime &reminderDate, Status status, QObject *parent)
	: QObject(parent)
	, m_id(id)
	, m_categoryId(categoryId)
	, m_title(title)
	, m_priority(toString(priority))
	, m_dueDate(dueDate)
	, m_reminderDate(reminderDate)
	, m_status(toString(status))
{}

TaskObject::TaskObject(QObject *parent)
	: QObject(parent)
{}

TaskObject &TaskObject::operator=(const TaskObject &right) {
	if (this == &right) {
		return *this;
	}

	m_id = right.m_id;
	m_categoryId = right.m_categoryId;
	m_title = right.m_title;
	m_priority = right.m_priority;
	m_dueDate = right.m_dueDate;
	m_reminderDate = right.m_reminderDate;
	m_status = right.m_status;
	return *this;
}

unsigned long TaskObject::id() const
{
	return m_id;
}

void TaskObject::setId(unsigned long id)
{
	if (m_id != id) {
		m_id = id;
		emit idChanged();
	}
}

unsigned long TaskObject::categoryId() const
{
	return m_categoryId;
}

void TaskObject::setCategoryId(unsigned long categoryId)
{
	if (m_categoryId != categoryId) {
		m_categoryId = categoryId;
		emit categoryIdChanged();
	}
}

QString TaskObject::title() const
{
	return m_title;
}

void TaskObject::setTitle(const QString &title)
{
	if (m_title != title) {
		m_title = title;
		emit titleChanged();
	}
}

QString TaskObject::priority() const
{
	return m_priority;
}

void TaskObject::setPriority(const QString &priority)
{
	if (m_priority != priority) {
		m_priority = priority;
		emit priorityChanged();
	}
}

QDateTime TaskObject::dueDate() const
{
	return m_dueDate;
}

void TaskObject::setDueDate(const QDateTime &dueDate)
{
	if (m_dueDate != dueDate) {
		m_dueDate = dueDate;
		emit dueDateChanged();
	}
}

QDateTime TaskObject::reminderDate() const
{
	return m_reminderDate;
}

void TaskObject::setReminderDate(const QDateTime &reminderDate)
{
	if (m_reminderDate != reminderDate) {
		m_reminderDate = reminderDate;
		emit reminderDateChanged();
	}
}

QString TaskObject::status() const
{
	return m_status;
}

void TaskObject::setStatus(const QString &status)
{
	if (m_status != status) {
		m_status = status;
		emit statusChanged();
	}
}
