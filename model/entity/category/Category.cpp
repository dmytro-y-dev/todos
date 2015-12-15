#include "Category.h"

using todos_model_entity::Category;

Category::Category(unsigned long id, unsigned long userId, const String& name) :
  IEntity(id), m_userId(userId), m_name(name)
{
}

unsigned long Category::GetUserId() const
{
  return m_userId;
}

Category::String Category::GetName() const
{
  return m_name;
}

void Category::SetUserId(unsigned long userId)
{
  m_userId = userId;
}

void Category::SetName(const String &name)
{
  m_name = name;
}
