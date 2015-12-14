#ifndef TODOS_MODEL_REPOSITORY_BASEREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_BASEREPOSITORY_H

#include <vector>
#include <memory>

#include <model/schema/Schema.h>
#include <model/entity/IEntity.h>

namespace todos_model_repository {
  class BaseRepository
  {
  public:
    typedef std::weak_ptr<todos_model_entity::IEntity> EntityWeakPtr;
    typedef std::vector<EntityWeakPtr> EntityWeakPtrContainer;
    typedef std::shared_ptr<todos_model_entity::IEntity> EntitySharedPtr;
    typedef std::vector<EntitySharedPtr> EntitySharedPtrContainer;

    typedef unsigned long Id;
    typedef std::vector<Id> IdContainer;

    typedef todos_model_schema::Schema Schema;

  private:
    Schema m_db;

  public:
    BaseRepository(const Schema& schema);

    IdContainer Insert(const EntityWeakPtrContainer& entities);
    size_t Update(const EntityWeakPtrContainer& entities);
    size_t Delete(const IdContainer& ids);

    Id Insert(EntitySharedPtr entity);
    size_t Update(EntitySharedPtr entity);
    size_t Delete(Id id);

    EntitySharedPtrContainer FindAll();
    EntitySharedPtr FindOneById(Id id);

    Schema GetSchema();
    void SetSchema(const Schema& schema);
  };
}

#endif //TODOS_MODEL_REPOSITORY_BASEREPOSITORY_H
