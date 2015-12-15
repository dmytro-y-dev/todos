#include "Task.h"

using todos_model_entity::Task;

Task::Task(unsigned long id, unsigned long categoryId, const Task::String &title,
  Task::Priority priority, const Task::DateTime &dueDate,
  const Task::DateTime &reminderDate, Task::Status status) :
  IEntity(id), m_categoryId(categoryId), m_title(title), m_priority(priority),
  m_dueDate(dueDate), m_reminderDate(reminderDate), m_status(status)
{
}

unsigned long Task::GetCategoryId() const
{
  return m_categoryId;
}

Task::String Task::GetTitle() const
{
  return m_title;
}

Task::Priority Task::GetPriority() const
{
  return m_priority;
}

Task::DateTime Task::GetDueDate() const
{
  return m_dueDate;
}

Task::DateTime Task::GetReminderDate() const
{
  return m_reminderDate;
}

Task::Status Task::GetStatus() const
{
  return m_status;
}

void Task::SetCategoryId(unsigned long categoryId)
{
  m_categoryId = categoryId;
}

void Task::SetTitle(const Task::String &title)
{
  m_title = title;
}

void Task::SetPriority(Task::Priority priority)
{
  m_priority = priority;
}

void Task::SetDueDate(const Task::DateTime &dueDate)
{
  m_dueDate = dueDate;
}

void Task::SetReminderDate(const Task::DateTime &reminderDate)
{
  m_reminderDate = reminderDate;
}

void Task::SetStatus(Task::Status status)
{
  m_status = status;
}
