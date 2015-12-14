#ifndef TODOS_MODEL_REPOSITORY_IREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_IREPOSITORY_H

#include <vector>
#include <memory>

#include <model/repository/BaseRepository.h>
#include <model/schema/Schema.h>
#include <model/entity/IEntity.h>

namespace todos_model_repository {
  template <class IEntityDerivative>
  class IRepository
  {
  public:
    typedef std::weak_ptr<IEntityDerivative> EntityWeakPtr;
    typedef std::vector<EntityWeakPtr> EntityWeakPtrContainer;
    typedef std::shared_ptr<IEntityDerivative> EntitySharedPtr;

    typedef unsigned long Id;
    typedef std::vector<Id> IdContainer;

    typedef todos_model_schema::Schema Schema;

  private:
    BaseRepository m_repository;

  public:
    IRepository(const Schema& schema);

    IdContainer Insert(const EntityWeakPtrContainer& entities);
    size_t Update(const EntityWeakPtrContainer& entities);
    size_t Delete(const IdContainer& ids);

    Id Insert(EntityWeakPtr entity);
    size_t Update(EntityWeakPtr entity);
    size_t Delete(Id id);

    virtual EntitySharedPtr FindOneById(Id id) = 0;

    Schema GetSchema();
    void SetSchema(const Schema& schema);
  };
}

#include "IRepositoryImpl.h"

#endif //TODOS_MODEL_REPOSITORY_IREPOSITORY_H
