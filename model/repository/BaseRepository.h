#ifndef TODOS_MODEL_REPOSITORY_BASEREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_BASEREPOSITORY_H

#include <string>

#include <model/traits/IEntityTraits.h>
#include <model/schema/Schema.h>

namespace todos_model_repository {
  class BaseRepository
  {
  public:
    typedef unsigned long Id;
    typedef std::string String;

    typedef todos_model_traits::IEntityTraits EntityTraits;
    typedef todos_model_schema::Schema Schema;

  private:
    Schema m_db;

  public:
    BaseRepository(const Schema& schema);

    Id Insert(const EntityTraits::FieldsValuesContainer& values, const EntityTraits& traits);
    bool Update(Id id, const EntityTraits::FieldsValuesContainer& values, const EntityTraits& traits);
    bool Delete(Id id, const EntityTraits& traits);

    EntityTraits::FieldsValuesContainer FindOneById(Id id, const EntityTraits& traits);

    Schema GetSchema();
    void SetSchema(const Schema& schema);
  };
}

#endif //TODOS_MODEL_REPOSITORY_BASEREPOSITORY_H
