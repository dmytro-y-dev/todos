#include "CommentaryObject.h"

using CommentaryType = todos_model_entity::Commentary::Type;

namespace
{
	const QString csTextType     = QString("TextType");
	const QString csImagePNGType = QString("ImagePNGType");
	const QString csUnknownType  = QString("UnknownType");

	QString toString(CommentaryType type) {
		switch (type) {
		case CommentaryType::TEXT:
			return csTextType;
		case CommentaryType::IMAGE_PNG:
			return csImagePNGType;
		default:
			return csUnknownType;
		}
	}

	CommentaryType toType(const QString &str) {
		if (str == csTextType) {
			return CommentaryType::TEXT;
		} else if (str == csImagePNGType) {
			return CommentaryType::IMAGE_PNG;
		} else {
			return CommentaryType::UNKNOWN;
		}
	}

	inline QVariant makeContent(const Content &content) {
		const char* temp = content.c_str();
		return QVariant(temp);
	}
}

CommentaryObject::CommentaryObject(unsigned long id, unsigned long taskId, CommentaryType type, const QDateTime &publishedOn, const Content &content, QObject *parent)
	: QObject(parent)
	, m_id(id)
	, m_taskId(taskId)
	, m_type(toString(type))
	, m_publishedOn(publishedOn)
	, m_content(makeContent(content))
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
