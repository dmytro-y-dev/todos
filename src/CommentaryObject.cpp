#include "CommentaryObject.h"
#include "TypeConverter.h"

using CommentaryType = todos_model_entity::Commentary::Type;

namespace {
	inline QVariant makeContent(const Content &content) {
		const char* temp = content.c_str();
		return QVariant(temp);
	}
}

CommentaryObject::CommentaryObject(unsigned long id, unsigned long taskId, CommentaryType type, const QDateTime &publishedOn, const Content &content, QObject *parent)
	: QObject(parent)
	, m_id(id)
	, m_taskId(taskId)
	, m_type(TypeConverter::toString(type))
	, m_publishedOn(publishedOn)
	, m_content(makeContent(content))
{}

CommentaryObject::CommentaryObject(todos_model_entity::Commentary *commentary, QObject *parent)
	: QObject(parent)
	, m_id(commentary->GetId())
	, m_taskId(commentary->GetTaskId())
	, m_type(TypeConverter::toString(commentary->GetType()))
	, m_publishedOn(commentary->GetPublishedOn())
	, m_content(makeContent(commentary->GetContent()))
{}

CommentaryObject::CommentaryObject(QObject *parent)
	: QObject(parent)
{}

unsigned long CommentaryObject::id() const
{
	return m_id;
}

void CommentaryObject::setId(unsigned long id)
{
	if (m_id != id) {
		m_id = id;
		emit idChanged();
	}
}

unsigned long CommentaryObject::taskId() const
{
	return m_taskId;
}

void CommentaryObject::setTaskId(unsigned long taskId)
{
	if (m_taskId != taskId) {
		m_taskId = taskId;
		emit taskIdChanged();
	}
}

QString CommentaryObject::type() const
{
	return m_type;
}

void CommentaryObject::setType(const QString &type)
{
	if (m_type != type) {
		m_type = type;
		emit typeChanged();
	}
}

QDateTime CommentaryObject::publishedOn() const
{
	return m_publishedOn;
}

void CommentaryObject::setPublishedOn(const QDateTime &publishedOn)
{
	if (m_publishedOn != publishedOn) {
		m_publishedOn = publishedOn;
		emit publishedOnChanged();
	}
}

QVariant CommentaryObject::content() const
{
	return m_content;
}

void CommentaryObject::setContent(const QVariant &content)
{
	if (m_content != content) {
		m_content = content;
		emit contentChanged();
	}
}
