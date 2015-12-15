#ifndef TODOS_MODEL_REPOSITORY_IREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_IREPOSITORY_H

#include <memory>
#include <vector>

#include <model/repository/BaseRepository.h>

namespace todos_model_repository {
  template <class Entity_, class EntityTraits_, class EntityFactory_>
  class IRepository
  {
  public:
    typedef Entity_ Entity;
    typedef EntityTraits_ EntityTraits;
    typedef EntityFactory_ EntityFactory;

    typedef todos_model_schema::Schema Schema;
    typedef unsigned long Id;

    typedef std::shared_ptr<Entity> EntitySharedPtr;

  private:
    BaseRepository m_repository;

  public:
    IRepository(const Schema& schema);

    Id Insert(Entity& entity);
    bool Update(Id id, const Entity& entity);
    bool Delete(Id id);

    EntitySharedPtr FindOneById(Id id);

    EntitySharedPtr FindOneUsingSQLStatement(sqlite3_stmt* stmt);
    std::vector<EntitySharedPtr> FindAllUsingSQLStatement(sqlite3_stmt* stmt);

  protected:
    BaseRepository& GetBaseRepository();
  };
}

#include "IRepositoryImpl.h"

#endif //TODOS_MODEL_REPOSITORY_IREPOSITORY_H
