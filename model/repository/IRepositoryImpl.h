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
    BaseRepository::EntityTraits::FieldsValuesContainer&& values = m_repository.FindOneById(id, EntityTraits());

    return EntityFactory::GetInstance().CreateFromFieldsValues(values);
  }

  template <class Entity, class EntityTraits, class EntityFactory>
  typename IRepository<Entity, EntityTraits, EntityFactory>::EntitySharedPtr IRepository<Entity, EntityTraits, EntityFactory>::FindOneUsingSQLStatement(sqlite3_stmt* stmt)
  {
    EntitySharedPtr entity;

    if (sqlite3_step(stmt) == SQLITE_ROW) {
      typename EntityTraits::FieldsValuesContainer values;

      for (int i = 0, iend = sqlite3_column_count(stmt); i != iend; ++i) {
        std::string key = sqlite3_column_name(stmt, i);
        std::string value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));

        values.insert(std::make_pair(key, value));
      }

      entity = EntityFactory::GetInstance().CreateFromFieldsValues(values);
    }

    return entity;
  }

  template <class Entity, class EntityTraits, class EntityFactory>
  std::vector<typename IRepository<Entity, EntityTraits, EntityFactory>::EntitySharedPtr> IRepository<Entity, EntityTraits, EntityFactory>::FindAllUsingSQLStatement(sqlite3_stmt* stmt)
  {
    std::vector<EntitySharedPtr> entities;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
      typename EntityTraits::FieldsValuesContainer values;

      for (int i = 0, iend = sqlite3_column_count(stmt); i != iend; ++i) {
        std::string key = sqlite3_column_name(stmt, i);
        std::string value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));

        values.insert(std::make_pair(key, value));
      }

      EntitySharedPtr entity = EntityFactory::GetInstance().CreateFromFieldsValues(values);
      entities.push_back(entity);
    }

    return entities;
  }

  template <class Entity, class EntityTraits, class EntityFactory>
  BaseRepository& IRepository<Entity, EntityTraits, EntityFactory>::GetBaseRepository()
  {
    return m_repository;
  }
}

#endif //TODOS_MODEL_REPOSITORY_IREPOSITORYIMPL_H
