#include "TaskQML.h"

TaskQML::TaskQML(QString title, int priority, QString dueDate, QString commentary, QString status, QObject *parent)
	: QObject(parent)
	, m_title(title)
	, m_priority(priority)
	, m_dueDate(dueDate)
	, m_commentary(commentary)
	, m_status(status)
{}

TaskQML::TaskQML(QObject *parent)
	: QObject(parent)
{}

QString TaskQML::title() const
{
	return m_title;
}

void TaskQML::setTitle(const QString &title)
{
	m_title = title;
}

int TaskQML::priority() const
{
	return m_priority;
}

void TaskQML::setPriority(int priority)
{
	m_priority = priority;
}

QString TaskQML::dueDate() const
{
	return m_dueDate;
}

void TaskQML::setDueDate(const QString &dueDate)
{
	m_dueDate = dueDate;
}

QString TaskQML::commentary() const
{
	return m_commentary;
}

void TaskQML::setCommentary(const QString &commentary)
{
	m_commentary = commentary;
}

QString TaskQML::status() const
{
	return m_status;
}

void TaskQML::setStatus(const QString &status)
{
	m_status = status;
}

TaskQML &TaskQML::operator=(const TaskQML &right) {
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
