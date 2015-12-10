#include "TaskListModel.h"

namespace
{
	QList<Task> testData = QList<Task>()
			<< Task("Title", 1, "10-10-2015", "Commentary", "Done")
			<< Task("Title2", 1, "10-10-2015", "Commentary", "Done")
			<< Task("Title3", 1, "10-10-2015", "Commentary", "Done")
			<< Task("Title4", 1, "10-10-2015", "Commentary", "Done");
}

TaskListModel::TaskListModel(QObject *parent)
	: QAbstractListModel(parent)
{
	// set role names
	m_roleNames[RN_Title]      = "title";
	m_roleNames[RN_Priority]   = "priority";
	m_roleNames[RN_DueDate]    = "dueDate";
	m_roleNames[RN_Commentary] = "commentary";
	m_roleNames[RN_Status]     = "status";

	// set test data
	m_data = testData;
}

int TaskListModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_data.count();
}

QVariant TaskListModel::data(const QModelIndex &index, int role) const
{
	auto row = index.row();
	if (row < 0 || row >= m_data.count()) {
		return QVariant();
	}

	const auto task = m_data.at(row);
	switch (role) {
	case RN_Title:
		return task.title;
	case RN_Priority:
		return task.priority;
	case RN_DueDate:
		return task.dueDate;
	case RN_Commentary:
		return task.commentary;
	case RN_Status:
		return task.status;
	}
	return QVariant();
}

void TaskListModel::insert(int index, const Task &task)
{
	if (index < 0 || index > m_data.count()) {
		return;
	}
	m_data.insert(index, task);
}

void TaskListModel::append(const Task &task)
{
	m_data.append(task);
}

void TaskListModel::remove(int index)
{
	if (index < 0 || index > m_data.count()) {
		return;
	}

	m_data.removeAt(index);
}

void TaskListModel::clear()
{
	m_data.clear();
}

QHash<int, QByteArray> TaskListModel::roleNames() const
{
	return m_roleNames;
}
