#include "TaskRepository.h"

using todos_model_entity::Task;
using todos_model_factory::TaskFactory;
using todos_model_repository::TaskRepository;

TaskRepository::TaskRepository(const Schema &schema) :
  IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}

std::vector<TaskRepository::EntitySharedPtr> TaskRepository::FindAllByCategoryId(unsigned long categoryId)
{
  std::vector<TaskRepository::EntitySharedPtr> entities;
  std::string query = "SELECT * FROM `Task` WHERE `category_id` = '" + std::to_string(categoryId) + "' ORDER BY `title`;";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetBaseRepository().GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    EntityTraits::FieldsValuesContainer values;

    for (int i = 0, iend = sqlite3_column_count(stmt); i != iend; ++i) {
      std::string key = sqlite3_column_name(stmt, i);
      std::string value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));

      values.insert(std::make_pair(key, value));
    }

    EntitySharedPtr entity = EntityFactory::GetInstance().CreateFromFieldsValues(values);
    entities.push_back(entity);
  }

  sqlite3_finalize(stmt);

  return entities;
}


std::vector<TaskRepository::EntitySharedPtr> TaskRepository::FindAll(TaskRepository::TaskSortSettings sort, const TaskRepository::TaskFilterSettings &filters)
{
  // Prepare sorting part of SQL script

  std::string orderBy = "";

  switch (sort)
  {
  case TaskSortSettings::DUE_DATE:
    orderBy = "ORDER BY `due_date`" ;
    break;
  case TaskSortSettings::TITLE:
    orderBy = "ORDER BY `title`" ;
    break;
  case TaskSortSettings::PRIORITY:
    orderBy = "ORDER BY `priority`" ;
    break;
  default:
    orderBy = "ORDER BY `title`" ;
    break;
  }

  // Prepare filtering part of SQL script

  std::string filterBy = "";

  if (filters.IsFilterByCategory()) {
    filterBy += "INNER JOIN `Category` ON `Category`.`category_id` = `Task`.`category_id` WHERE `Category`.`name` = ?";

    if (filters.IsFilterByDueDate()) {
      filterBy += " AND ";
    }
  }

  if (filters.IsFilterByDueDate()) {
    if (!filters.IsFilterByCategory()) {
      filterBy += "WHERE ";
    }

    filterBy += " `Task`.`due_date` > '" + filters.GetDueDateLowerLimit().toString("yyyy-M-d H:m:s").toStdString() +
      "' AND `Task`.`due_date` < '" + filters.GetDueDateUpperLimit().toString("yyyy-M-d H:m:s").toStdString() + "'";
  }

  // Concat SQL script

  std::string query = "SELECT * FROM `Task` " + filterBy + " " + orderBy + ";";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetBaseRepository().GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  if (filters.IsFilterByCategory()) {
    sqlite3_bind_text(stmt, 1, filters.GetCategory().c_str(), -1, SQLITE_TRANSIENT);
  }

  std::vector<TaskRepository::EntitySharedPtr> entities;

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    EntityTraits::FieldsValuesContainer values;

    for (int i = 0, iend = sqlite3_column_count(stmt); i != iend; ++i) {
      std::string key = sqlite3_column_name(stmt, i);
      std::string value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));

      values.insert(std::make_pair(key, value));
    }

    EntitySharedPtr entity = EntityFactory::GetInstance().CreateFromFieldsValues(values);
    entities.push_back(entity);
  }

  sqlite3_finalize(stmt);

  return entities;
}
