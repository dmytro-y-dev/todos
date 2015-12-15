#include "Commentary.h"

using todos_model_entity::Commentary;

Commentary::Commentary(unsigned long id, unsigned long taskId, Commentary::Type type, const Commentary::DateTime &publishedOn, const Commentary::Content& content):
  IEntity(id), m_taskId(taskId), m_type(type), m_publishedOn(publishedOn), m_content(content)
{
}

unsigned long Commentary::GetTaskId() const
{
  return m_taskId;
}

Commentary::Type Commentary::GetType() const
{
  return m_type;
}

Commentary::DateTime Commentary::GetPublishedOn() const
{
  return m_publishedOn;
}

Commentary::Content Commentary::GetContent() const
{
  return m_content;
}

void Commentary::SetTaskId(unsigned long taskId)
{
  m_taskId = taskId;
}

void Commentary::SetType(Commentary::Type type)
{
  m_type = type;
}

void Commentary::SetPublishedOn(const Commentary::DateTime &publishedOn)
{
  m_publishedOn = publishedOn;
}

void Commentary::SetContent(const Commentary::Content& content)
{
  m_content = content;
}
