#include "TaskRepository.h"

using todos_model_entity::Task;
using todos_model_factory::TaskFactory;
using todos_model_repository::TaskRepository;

TaskRepository::TaskRepository(const Schema &schema) :
   IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}
