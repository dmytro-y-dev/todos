#ifndef TODOS_MODEL_REPOSITORY_USERREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_USERREPOSITORY_H

#include <model/schema/Schema.h>
#include <model/entity/user/User.h>

namespace todos_model_repository {
  class UserRepository
  {
  public:
    UserRepository(const Schema& schema);
  };
}

#endif //TODOS_MODEL_REPOSITORY_USERREPOSITORY_H
