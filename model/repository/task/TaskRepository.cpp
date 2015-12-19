#include "TaskRepository.h"

#include <utility/StringConversions.h>

using todos_model_entity::Task;
using todos_model_factory::TaskFactory;
using todos_model_repository::TaskRepository;
using todos_model_repository::TaskFilterSettings;

TaskRepository::TaskRepository(const Schema &schema) :
  IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}

std::vector<TaskRepository::EntitySharedPtr> TaskRepository::FindAllByCategoryId(unsigned long categoryId)
{
  std::vector<TaskRepository::EntitySharedPtr> entities;
  std::string query = "SELECT * FROM `Task` WHERE `category_id` = '" + todos_utility::IntToString(categoryId) + "' ORDER BY `title`;";

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


std::vector<TaskRepository::EntitySharedPtr> TaskRepository::FindAll(unsigned long userId, TaskSortSettings sort, const TaskFilterSettings &filters)
{
  // Prepare sorting part of SQL script

  std::string orderBy = "";

  switch (sort.GetField())
  {
  case TaskSortSettings::Field::DUE_DATE:
    orderBy = "ORDER BY `due_date`" ;
    break;
  case TaskSortSettings::Field::TITLE:
    orderBy = "ORDER BY `title`" ;
    break;
  case TaskSortSettings::Field::PRIORITY:
    orderBy = "ORDER BY `priority`" ;
    break;
  default:
    orderBy = "ORDER BY `title`" ;
    break;
  }

  switch (sort.GetOrder())
  {
  case TaskSortSettings::Order::ASC:
    orderBy += " ASC" ;
    break;
  case TaskSortSettings::Order::DESC:
    orderBy += " DESC" ;
    break;
  default:
    orderBy += " ASC" ;
    break;
  }

  // Prepare filtering part of SQL script

  std::string filterBy = "";

  if (filters.IsFilterByCategory()) {
    filterBy += "AND `Category`.`name` = ?";

    if (filters.IsFilterByDueDate()) {
      filterBy += " AND ";
    }
  }

  if (filters.IsFilterByDueDate()) {
    if (!filters.IsFilterByCategory()) {
      filterBy += "AND ";
    }

    filterBy += " `Task`.`due_date` > '" + todos_utility::QDateTimeToString(filters.GetDueDateLowerLimit()) +
      "' AND `Task`.`due_date` < '" + todos_utility::QDateTimeToString(filters.GetDueDateUpperLimit()) + "'";
  }

  // Concat SQL script

  std::string query = "SELECT * FROM `Task` INNER JOIN `Category` ON `Category`.`category_id` = `Task`.`category_id` "
      "WHERE `Category`.`user_id` = '" + todos_utility::IntToString(userId) + "' " + filterBy + " " + orderBy + ";";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetBaseRepository().GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  if (filters.IsFilterByCategory()) {
    sqlite3_bind_text(stmt, 1, filters.GetCategory().c_str(), -1, SQLITE_TRANSIENT);
  }

  std::vector<EntitySharedPtr>&& entities = FindAllUsingSQLStatement(stmt);

  sqlite3_finalize(stmt);

  return entities;
}
