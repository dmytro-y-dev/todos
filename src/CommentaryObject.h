#ifndef COMMENTARYOBJECT_H
#define COMMENTARYOBJECT_H

#include <QObject>
#include <QVariant>

#include <../model/entity/commentary/Commentary.h>

using CommentaryType = todos_model_entity::Commentary::Type;
using Content = todos_model_entity::Commentary::Content;

class CommentaryObject : public QObject
{
	Q_OBJECT
	Q_PROPERTY(unsigned long id      READ id          WRITE setId          NOTIFY idChanged)
	Q_PROPERTY(unsigned long taskId  READ taskId      WRITE setTaskId      NOTIFY taskIdChanged)
	Q_PROPERTY(QString type          READ type        WRITE setType        NOTIFY typeChanged)
	Q_PROPERTY(QDateTime publishedOn READ publishedOn WRITE setPublishedOn NOTIFY publishedOnChanged)
	Q_PROPERTY(QVariant content      READ content     WRITE setContent     NOTIFY contentChanged)

public:
	CommentaryObject(unsigned long id, unsigned long taskId, CommentaryType type, const QDateTime& publishedOn, const Content& content, QObject * parent = 0);
	CommentaryObject(todos_model_entity::Commentary * commentary, QObject *parent);
	CommentaryObject(QObject *parent);

	unsigned long id() const;
	void setId(unsigned long id);

	unsigned long taskId() const;
	void setTaskId(unsigned long taskId);

	QString type() const;
	void setType(const QString &type);

	QDateTime publishedOn() const;
	void setPublishedOn(const QDateTime &publishedOn);

	QVariant content() const;
	void setContent(const QVariant &content);

signals:
	void idChanged();
	void taskIdChanged();
	void typeChanged();
	void publishedOnChanged();
	void contentChanged();

private:
	unsigned long m_id;
	unsigned long m_taskId;
	QString m_type;
	QDateTime m_publishedOn;
	QVariant m_content;
};

#endif // COMMENTARYOBJECT_H
