#ifndef TASK_H
#define TASK_H

#include <QObject>

class Task : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString title      READ title      WRITE setTitle      NOTIFY titleChanged)
	Q_PROPERTY(int priority       READ priority   WRITE setPriority   NOTIFY priorityChanged)
	Q_PROPERTY(QString dueDate    READ dueDate    WRITE setDueDate    NOTIFY dueDateChanged)
	Q_PROPERTY(QString commentary READ commentary WRITE setCommentary NOTIFY commentaryChanged)
	Q_PROPERTY(QString status     READ status     WRITE setStatus     NOTIFY statusChanged)

public:
	Q_INVOKABLE Task(QString title, int priority, QString dueDate, QString commentary, QString status,  QObject *parent = 0);
	Q_INVOKABLE Task(QObject * parent = 0);

	QString title() const;
	void setTitle(const QString &title);

	int priority() const;
	void setPriority(int priority);

	QString dueDate() const;
	void setDueDate(const QString &dueDate);

	QString commentary() const;
	void setCommentary(const QString &commentary);

	QString status() const;
	void setStatus(const QString &status);

	Task& operator=(const Task &right);

signals:
	void titleChanged();
	void priorityChanged();
	void dueDateChanged();
	void commentaryChanged();
	void statusChanged();

private:
	QString m_title;
	int m_priority;
	QString m_dueDate;
	QString m_commentary;
	QString m_status;
};
#endif // TASK_H
