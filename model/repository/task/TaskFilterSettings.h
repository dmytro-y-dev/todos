#ifndef TODOS_MODEL_REPOSITORY_TASKFILTERSETTINGS_H
#define TODOS_MODEL_REPOSITORY_TASKFILTERSETTINGS_H

#include <string>
#include <QDateTime>

namespace todos_model_repository {
  class TaskFilterSettings
  {
  private:
    std::string m_category;
    QDateTime m_dueDateLowerLimit;
    QDateTime m_dueDateUpperLimit;

    bool m_byCategory;
    bool m_byDueDate;

  public:
    TaskFilterSettings();

    bool IsFilterByCategory() const;
    bool IsFilterByDueDate() const;
    std::string GetCategory() const;
    QDateTime GetDueDateUpperLimit() const;
    QDateTime GetDueDateLowerLimit() const;

    void EnableFilterByCategory(bool byCategory = true);
    void EnableFilterByDueDate(bool byDueDate = true);
    void SetCategory(const std::string& category);
    void SetDueDateUpperLimit(const QDateTime& dueDateUpperLimit);
    void SetDueDateLowerLimit(const QDateTime& dueDateLowerLimit);
  };
}

#endif //TODOS_MODEL_REPOSITORY_TASKFILTERSETTINGS_H
