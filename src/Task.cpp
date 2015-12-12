#include "Task.h"

Task::Task(QString title, int priority, QString dueDate, QString commentary, QString status, QObject *parent)
	: QObject(parent)
	, m_title(title)
	, m_priority(priority)
	, m_dueDate(dueDate)
	, m_commentary(commentary)
	, m_status(status)
{}

Task::Task(QObject *parent)
	: QObject(parent)
{}

QString Task::title() const
{
	return m_title;
}

void Task::setTitle(const QString &title)
{
	m_title = title;
}

int Task::priority() const
{
	return m_priority;
}

void Task::setPriority(int priority)
{
	m_priority = priority;
}

QString Task::dueDate() const
{
	return m_dueDate;
}

void Task::setDueDate(const QString &dueDate)
{
	m_dueDate = dueDate;
}

QString Task::commentary() const
{
	return m_commentary;
}

void Task::setCommentary(const QString &commentary)
{
	m_commentary = commentary;
}

QString Task::status() const
{
	return m_status;
}

void Task::setStatus(const QString &status)
{
	m_status = status;
}

Task &Task::operator=(const Task &right) {
	if (this == &right) {
		return *this;
	}

	m_title = right.m_title;
	m_priority = right.m_priority;
	m_dueDate = right.m_dueDate;
	m_commentary = right.m_commentary;
	m_status = right.m_status;
	return *this;
}
