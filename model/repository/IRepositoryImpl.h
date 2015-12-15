#ifndef TODOS_MODEL_REPOSITORY_IREPOSITORYIMPL_H
#define TODOS_MODEL_REPOSITORY_IREPOSITORYIMPL_H

namespace todos_model_repository {
  template <class Entity, class EntityTraits, class EntityFactory>
  IRepository<Entity, EntityTraits, EntityFactory>::IRepository(const Schema& schema) :
    m_repository(schema)
  {
  }

  template <class Entity, class EntityTraits, class EntityFactory>
  typename IRepository<Entity, EntityTraits, EntityFactory>::Id IRepository<Entity, EntityTraits, EntityFactory>::Insert(Entity& entity)
  {
    Id entityId = m_repository.Insert(EntityFactory::GetInstance().RevertToFieldsValues(entity), EntityTraits());
    entity.SetId(entityId);

    return entityId;
  }

  template <class Entity, class EntityTraits, class EntityFactory>
  bool IRepository<Entity, EntityTraits, EntityFactory>::Update(Id id, const Entity& entity)
  {
    return m_repository.Update(id, EntityFactory::GetInstance().RevertToFieldsValues(entity), EntityTraits());
  }

  template <class Entity, class EntityTraits, class EntityFactory>
  bool IRepository<Entity, EntityTraits, EntityFactory>::Delete(Id id)
  {
    return m_repository.Delete(id, EntityTraits());
  }

  template <class Entity, class EntityTraits, class EntityFactory>
  typename IRepository<Entity, EntityTraits, EntityFactory>::EntitySharedPtr IRepository<Entity, EntityTraits, EntityFactory>::FindOneById(Id id)
  {
    //while (sqlite3_step(stmt) == SQLITE_ROW) {
    //}

    BaseRepository::EntityTraits::FieldsValuesContainer&& values = m_repository.FindOneById(id, EntityTraits());

    return EntityFactory::GetInstance().CreateFromFieldsValues(values);
  }

  template <class Entity, class EntityTraits, class EntityFactory>
  BaseRepository& IRepository<Entity, EntityTraits, EntityFactory>::GetBaseRepository()
  {
    return m_repository;
  }
}

#endif //TODOS_MODEL_REPOSITORY_IREPOSITORYIMPL_H
