#ifndef TODOS_MODEL_FACTORY_TASKFACTORY_H
#define TODOS_MODEL_FACTORY_TASKFACTORY_H

#include <memory>
#include <vector>

#include <model/entity/Task/Task.h>
#include <model/traits/Task/TaskTraits.h>

namespace todos_model_factory {
  class TaskFactory
  {
  public:
    typedef todos_model_entity::Task Entity;
    typedef std::shared_ptr<Entity> EntitySharedPtr;
    typedef todos_model_traits::IEntityTraits::FieldsValuesContainer FieldsValuesContainer;

  private:
    std::vector<std::pair<std::string, Entity::Priority> > m_priorityMapping;
    std::vector<std::pair<std::string, Entity::Status> > m_statusMapping;

  public:
    static TaskFactory& GetInstance()
    {
      static TaskFactory instance;
      return instance;
    }

    EntitySharedPtr CreateFromFieldsValues(const FieldsValuesContainer &values) const;
    FieldsValuesContainer RevertToFieldsValues(const Entity &entity) const;

  private:
    TaskFactory();

    TaskFactory(const TaskFactory&) = delete;
    TaskFactory& operator=(const TaskFactory&) = delete;

    std::string PriorityToString(Entity::Priority priority) const;
    Entity::Priority StringToPriority(const std::string& priority) const;

    std::string StatusToString(Entity::Status status) const;
    Entity::Status StringToStatus(const std::string& status) const;
  };
}

#endif //TODOS_MODEL_FACTORY_TASKFACTORY_H
