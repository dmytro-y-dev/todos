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
    enum class TaskSortSettings
    {
      NONE = 0,

      DUE_DATE = 1,
      PRIORITY = 2,
      TITLE = 3
    };

    class TaskFilterSettings
    {
    private:
      std::string m_category;
      QDateTime m_dueDateLowerLimit;
      QDateTime m_dueDateUpperLimit;

      bool m_byCategory;
      bool m_byDueDate;

    public:
      TaskFilterSettings() : m_byCategory(false), m_byDueDate(false)
      {
      }

      bool IsFilterByCategory() const
      {
        return m_byCategory;
      }

      bool IsFilterByDueDate() const
      {
        return m_byDueDate;
      }

      std::string GetCategory() const
      {
        return m_category;
      }

      QDateTime GetDueDateUpperLimit() const
      {
        return m_dueDateUpperLimit;
      }

      QDateTime GetDueDateLowerLimit() const
      {
        return m_dueDateLowerLimit;
      }

      void EnableFilterByCategory(bool byCategory = true)
      {
        m_byCategory = byCategory;
      }

      void EnableFilterByDueDate(bool byDueDate = true)
      {
        m_byDueDate = byDueDate;
      }

      void SetCategory(const std::string& category)
      {
        m_category = category;
      }

      void SetDueDateUpperLimit(const QDateTime& dueDateUpperLimit)
      {
        m_dueDateUpperLimit = dueDateUpperLimit;
      }

      void SetDueDateLowerLimit(const QDateTime& dueDateLowerLimit)
      {
        m_dueDateLowerLimit = dueDateLowerLimit;
      }
    };

  public:
    TaskRepository(const Schema& schema);

    std::vector<EntitySharedPtr> FindAllByCategoryId(unsigned long categoryId);
    std::vector<EntitySharedPtr> FindAll(TaskSortSettings sort, const TaskFilterSettings& filters);
  };
}

#endif //TODOS_MODEL_REPOSITORY_TASKREPOSITORY_H
