#include "Category.h"

using todos_model_entity::Category;

Category::Category(unsigned long id, const String& name) :
  IEntity(id), m_name(name)
{
}

Category::String Category::GetName() const
{
  return m_name;
}

void Category::SetName(const String &name)
{
  m_name = name;
}
