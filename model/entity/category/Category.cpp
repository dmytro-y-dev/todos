#include "Category.h"

using todos_model_entity::Category;

Category::Category(unsigned long id, const String& name) :
  m_id(id), m_name(name)
{
}

unsigned long Category::GetId() const
{
  return m_id;
}

Category::String Category::GetName() const
{
  return m_name;
}

void Category::SetId(unsigned int id)
{
  m_id = id;
}

void Category::SetName(const String &name)
{
  m_name = name;
}
