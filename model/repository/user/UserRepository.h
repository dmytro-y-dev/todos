#ifndef TODOS_MODEL_REPOSITORY_USERREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_USERREPOSITORY_H

#include <model/repository/IRepository.h>

#include <model/entity/user/User.h>
#include <model/traits/user/UserTraits.h>
#include <model/factory/user/UserFactory.h>

namespace todos_model_repository {
  class UserRepository: public IRepository<todos_model_entity::User, todos_model_traits::UserTraits, todos_model_factory::UserFactory>
  {
  public:
    UserRepository(const Schema& schema);

    EntitySharedPtr FindOneByLogin(const std::string& login);
  };
}

#endif //TODOS_MODEL_REPOSITORY_USERREPOSITORY_H
