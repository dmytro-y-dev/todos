#include "CategotyObject.h"

CategotyObject::CategotyObject(unsigned long id, unsigned long userId, const QString &name, QObject *parent)
	: QObject(parent)
	, m_id(id)
	, m_userId(userId)
	, m_name(name)
{}

CategotyObject::CategotyObject(todos_model_entity::Category category, QObject *parent)
	: QObject(parent)
	, m_id(category.GetId())
	, m_userId(category.GetUserId())
	, m_name(category.GetName())
{}

CategotyObject::CategotyObject(QObject *parent)
	: QObject(parent)
{}

unsigned long CategotyObject::id() const
{
	return m_id;
}

void CategotyObject::setId(unsigned long id)
{
	if (m_id != id) {
		m_id = id;
		emit idChanged();
	}
}

unsigned long CategotyObject::userId() const
{
	return m_userId;
}

void CategotyObject::setUserId(unsigned long userId)
{
	if (m_userId != userId) {
		m_userId = userId;
		emit userIdChanged();
	}
}

QString CategotyObject::name() const
{
	return m_name;
}

void CategotyObject::setName(const QString &name)
{
	if ( m_name != name) {
		m_name = name;
		emit nameChanged();
	}
}

