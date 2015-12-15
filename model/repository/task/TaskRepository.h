#ifndef TODOS_MODEL_REPOSITORY_TASKREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_TASKREPOSITORY_H

#include <model/repository/IRepository.h>

#include <model/entity/task/Task.h>
#include <model/traits/task/TaskTraits.h>
#include <model/factory/task/TaskFactory.h>

namespace todos_model_repository {
  class TaskRepository: public IRepository<todos_model_entity::Task, todos_model_traits::TaskTraits, todos_model_factory::TaskFactory>
  {
  public:
    TaskRepository(const Schema& schema);
  };
}

#endif //TODOS_MODEL_REPOSITORY_TASKREPOSITORY_H
