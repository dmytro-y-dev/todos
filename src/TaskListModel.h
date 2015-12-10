#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H

#include <QAbstractListModel>

struct Task{

	Task(QString newTitle, int newPriority, QString newDueDate, QString newCommentary, QString newStatus) {
		title      = newTitle;
		priority   = newPriority;
		dueDate    = newDueDate;
		commentary = newCommentary;
		status     = newStatus;
	}

	QString title;
	int priority;
	QString dueDate;
	QString commentary;
	QString status;
};

class TaskListModel : public QAbstractListModel
{
	Q_OBJECT
public:
	enum RoleNames {
		RN_Title      = Qt::UserRole,
		RN_Priority   = Qt::UserRole + 1,
		RN_DueDate    = Qt::UserRole + 2,
		RN_Commentary = Qt::UserRole + 3,
		RN_Status     = Qt::UserRole + 4
	};
	explicit TaskListModel(QObject *parent = 0);

	virtual int rowCount(const QModelIndex &parent) const override;
	virtual QVariant data(const QModelIndex &index, int role) const override;
	void insert(int index, const Task &task);
	void append(const Task &task);
	void remove(int index);
	void clear();

protected:
	virtual QHash<int, QByteArray> roleNames() const override;

private:
	QList<Task> m_data;
	QHash<int, QByteArray> m_roleNames;
};

#endif // TASKLISTMODEL_H
