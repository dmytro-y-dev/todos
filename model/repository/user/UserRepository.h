#ifndef TODOS_MODEL_REPOSITORY_USERREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_USERREPOSITORY_H

#include <model/repository/IRepository.h>
#include <model/entity/user/User.h>

namespace todos_model_repository {
  class UserRepository: public IRepository<todos_model_entity::User>
  {
  private:
    typedef todos_model_entity::User Entity;
    typedef todos_model_schema::Schema Schema;

  public:
    UserRepository(const Schema& schema);
  };
}

#endif //TODOS_MODEL_REPOSITORY_USERREPOSITORY_H
