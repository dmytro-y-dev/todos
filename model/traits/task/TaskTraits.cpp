#include "TaskTraits.h"

using todos_model_traits::TaskTraits;

const char *TaskTraits::GetIdFieldName() const
{
  return "task_id";
}

TaskTraits::FieldsNamesContainer TaskTraits::GetFieldsNames() const
{
  static FieldsNamesContainer fieldsNames{"task_id", "category_id", "title", "priority", "due_date", "reminder_date", "status"};

  return fieldsNames;
}

const char* TaskTraits::GetTableName() const
{
  return "Task";
}
