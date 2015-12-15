#include "TaskFilterSettings.h"

using todos_model_repository::TaskFilterSettings;

TaskFilterSettings::TaskFilterSettings() :
  m_byCategory(false), m_byDueDate(false)
{
}

bool TaskFilterSettings::IsFilterByCategory() const
{
  return m_byCategory;
}

bool TaskFilterSettings::IsFilterByDueDate() const
{
  return m_byDueDate;
}

std::string TaskFilterSettings::GetCategory() const
{
  return m_category;
}

QDateTime TaskFilterSettings::GetDueDateUpperLimit() const
{
  return m_dueDateUpperLimit;
}

QDateTime TaskFilterSettings::GetDueDateLowerLimit() const
{
  return m_dueDateLowerLimit;
}

void TaskFilterSettings::EnableFilterByCategory(bool byCategory)
{
  m_byCategory = byCategory;
}

void TaskFilterSettings::EnableFilterByDueDate(bool byDueDate)
{
  m_byDueDate = byDueDate;
}

void TaskFilterSettings::SetCategory(const std::string &category)
{
  m_category = category;
}

void TaskFilterSettings::SetDueDateUpperLimit(const QDateTime &dueDateUpperLimit)
{
  m_dueDateUpperLimit = dueDateUpperLimit;
}

void TaskFilterSettings::SetDueDateLowerLimit(const QDateTime &dueDateLowerLimit)
{
  m_dueDateLowerLimit = dueDateLowerLimit;
}
