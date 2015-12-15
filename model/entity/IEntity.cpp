#include "IEntity.h"

using todos_model_entity::IEntity;

IEntity::IEntity(unsigned long id) :
  m_id(id)
{
}

IEntity::~IEntity()
{
}

unsigned long IEntity::GetId() const
{
  return m_id;
}

void IEntity::SetId(unsigned int id)
{
  m_id = id;
}
