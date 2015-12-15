#ifndef TODOS_MODEL_ENTITY_TASK_H
#define TODOS_MODEL_ENTITY_TASK_H

#include <string>
#include <QDateTime>

#include <model/entity/IEntity.h>

namespace todos_model_entity {
  class Task: public IEntity
  {
  public:
    enum class Status {
      UNKNOWN = 0,

      COMPLETED = 1,
      UNCOMPLETED = 2
    };

    enum class Priority {
      UNKNOWN = 0,

      LOW = 1,
      NORMAL = 2,
      HIGH = 3
    };

    typedef QDateTime DateTime;
    typedef std::string String;

  private:
    unsigned long m_categoryId;
    String m_title;
    Priority m_priority;
    DateTime m_dueDate;
    DateTime m_reminderDate;
    Status m_status;

  public:
    Task(unsigned long id, unsigned long categoryId, const String& title, Priority priority, const DateTime& dueDate,
         const DateTime& reminderDate, Status status);

    unsigned long GetCategoryId() const;
    String GetTitle() const;
    Priority GetPriority() const;
    DateTime GetDueDate() const;
    DateTime GetReminderDate() const;
    Status GetStatus() const;

    void SetCategoryId(unsigned long categoryId);
    void SetTitle(const String& title);
    void SetPriority(Priority priority);
    void SetDueDate(const DateTime& dueDate);
    void SetReminderDate(const DateTime& reminderDate);
    void SetStatus(Status status);
  };
}

#endif //TODOS_MODEL_ENTITY_TASK_H
