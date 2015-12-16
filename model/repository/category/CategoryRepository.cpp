#include "CategoryRepository.h"

#include <utility/StringConversions.h>

using todos_model_entity::Category;
using todos_model_factory::CategoryFactory;
using todos_model_repository::CategoryRepository;

CategoryRepository::CategoryRepository(const Schema &schema) :
   IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}

std::vector<CategoryRepository::EntitySharedPtr> CategoryRepository::FindAll(unsigned long userId)
{
  std::string query = "SELECT * FROM `Category` WHERE `user_id` = '" + todos_utility::IntToString(userId) + "' ORDER BY `name`;";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetBaseRepository().GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  std::vector<EntitySharedPtr>&& entities = FindAllUsingSQLStatement(stmt);

  sqlite3_finalize(stmt);

  return entities;
}
