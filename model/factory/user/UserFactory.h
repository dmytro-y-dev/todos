#ifndef TODOS_MODEL_FACTORY_USERFACTORY_H
#define TODOS_MODEL_FACTORY_USERFACTORY_H

#include <memory>
#include <vector>

#include <model/entity/user/User.h>
#include <model/traits/user/UserTraits.h>

namespace todos_model_factory {
  class UserFactory
  {
  public:
    typedef todos_model_entity::User Entity;
    typedef std::shared_ptr<Entity> EntitySharedPtr;
    typedef todos_model_traits::IEntityTraits::FieldsValuesContainer FieldsValuesContainer;

  public:
    static UserFactory& GetInstance()
    {
      static UserFactory instance;
      return instance;
    }

    EntitySharedPtr CreateFromFieldsValues(const FieldsValuesContainer &values) const;
    FieldsValuesContainer RevertToFieldsValues(const Entity &entity) const;

  private:
    UserFactory()
    {
    }

    UserFactory(const UserFactory&) = delete;
    UserFactory& operator=(const UserFactory&) = delete;
  };
}

#endif //TODOS_MODEL_FACTORY_USERFACTORY_H
