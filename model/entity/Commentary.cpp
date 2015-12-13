#include "Commentary.h"

using todos_model_entity::Commentary;

Commentary::Commentary(unsigned long id, Commentary::Type type, const Commentary::DateTime &publishedOn, Commentary::ContentPtr content):
  m_id(id), m_type(type), m_publishedOn(publishedOn), m_content(content)
{
}

unsigned long Commentary::GetId() const
{
  return m_id;
}

Commentary::Type Commentary::GetType() const
{
  return m_type;
}

Commentary::DateTime Commentary::GetPublishedOn() const
{
  return m_publishedOn;
}

Commentary::ContentPtr Commentary::GetContent() const
{
  return m_content;
}

void Commentary::SetId(unsigned int id)
{
  m_id = id;
}

void Commentary::SetType(Commentary::Type type)
{
  m_type = type;
}

void Commentary::SetPublishedOne(const Commentary::DateTime &publishedOn)
{
  m_publishedOn = publishedOn;
}

void Commentary::SetContent(Commentary::ContentPtr content)
{
  m_content = content;
}
