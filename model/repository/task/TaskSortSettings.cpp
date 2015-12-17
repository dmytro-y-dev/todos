#include "TaskSortSettings.h"

using todos_model_repository::TaskSortSettings;

TaskSortSettings::TaskSortSettings(TaskSortSettings::Field field, todos_model_repository::TaskSortSettings::Order order) :
  m_field(field), m_order(order)
{
}

TaskSortSettings::Order TaskSortSettings::GetOrder() const
{
  return m_order;
}

TaskSortSettings::Field TaskSortSettings::GetField() const
{
  return m_field;
}

void TaskSortSettings::SetOrder(TaskSortSettings::Order order)
{
  m_order = order;
}

void TaskSortSettings::SetField(TaskSortSettings::Field field)
{
  m_field = field;
}
