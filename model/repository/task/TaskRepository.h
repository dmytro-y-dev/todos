#ifndef TODOS_MODEL_REPOSITORY_TASKREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_TASKREPOSITORY_H

#include <model/repository/IRepository.h>

#include <model/entity/task/Task.h>
#include <model/traits/task/TaskTraits.h>
#include <model/factory/task/TaskFactory.h>

#include "TaskFilterSettings.h"
#include "TaskSortSettings.h"

namespace todos_model_repository {
  class TaskRepository: public IRepository<todos_model_entity::Task, todos_model_traits::TaskTraits, todos_model_factory::TaskFactory>
  {
  public:
    typedef todos_model_repository::TaskSortSettings TaskSortSettings;
    typedef todos_model_repository::TaskFilterSettings TaskFilterSettings;

  public:
    TaskRepository(const Schema& schema);

    std::vector<EntitySharedPtr> FindAllByCategoryId(unsigned long categoryId);
    std::vector<EntitySharedPtr> FindAll(unsigned long userId, TaskSortSettings sort, const TaskFilterSettings& filters);
  };
}

#endif //TODOS_MODEL_REPOSITORY_TASKREPOSITORY_H
