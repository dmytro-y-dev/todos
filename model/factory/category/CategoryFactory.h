#ifndef TODOS_MODEL_FACTORY_CATEGORYFACTORY_H
#define TODOS_MODEL_FACTORY_CATEGORYFACTORY_H

#include <memory>
#include <vector>

#include <model/entity/Category/Category.h>
#include <model/traits/Category/CategoryTraits.h>

namespace todos_model_factory {
  class CategoryFactory
  {
  public:
    typedef todos_model_entity::Category Entity;
    typedef std::shared_ptr<Entity> EntitySharedPtr;
    typedef todos_model_traits::IEntityTraits::FieldsValuesContainer FieldsValuesContainer;

  public:
    static CategoryFactory& GetInstance()
    {
      static CategoryFactory instance;
      return instance;
    }

    EntitySharedPtr CreateFromFieldsValues(const FieldsValuesContainer &values) const;
    FieldsValuesContainer RevertToFieldsValues(const Entity &entity) const;

  private:
    CategoryFactory()
    {
    }

    CategoryFactory(const CategoryFactory&) = delete;
    CategoryFactory& operator=(const CategoryFactory&) = delete;
  };
}

#endif //TODOS_MODEL_FACTORY_CATEGORYFACTORY_H
