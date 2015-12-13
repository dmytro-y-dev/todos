#ifndef TODOS_MODEL_ENTITY_TASK_H
#define TODOS_MODEL_ENTITY_TASK_H

#include <string>
#include <QDateTime>

namespace todos_model_entity {
  class Task
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
    unsigned long m_id;
    String m_title;
    Priority m_priority;
    DateTime m_dueDate;
    String m_commentary;
    DateTime m_reminderDate;
    Status m_status;

  public:
    Task(unsigned long id, const String& title, Priority priority, const DateTime& dueDate,
         const String& commentary, const DateTime& reminderDate, Status status);

    unsigned long GetId() const;
    String GetTitle() const;
    Priority GetPriority() const;
    DateTime GetDueDate() const;
    String GetCommentary() const;
    DateTime GetReminderDate() const;
    Status GetStatus() const;

    void SetId(unsigned int id);
    void SetTitle(const String& title);
    void SetPriority(Priority priority);
    void SetDueDate(const DateTime& dueDate);
    void SetCommentary(const String& commentary);
    void SetReminderDate(const DateTime& reminderDate);
    void SetStatus(Status status);
  };
}

#endif //TODOS_MODEL_ENTITY_TASK_H
