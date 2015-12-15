#include "UserRepository.h"

using todos_model_entity::User;
using todos_model_factory::UserFactory;
using todos_model_repository::UserRepository;

UserRepository::UserRepository(const Schema &schema) :
   IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}

UserRepository::EntitySharedPtr UserRepository::FindOneByLogin(const std::string &login)
{
  UserRepository::EntitySharedPtr entity;
  std::string query = "SELECT * FROM `User` WHERE `login` = '" + login + "';";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetBaseRepository().GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    EntityTraits::FieldsValuesContainer values;

    for (int i = 0, iend = sqlite3_column_count(stmt); i != iend; ++i) {
      std::string key = sqlite3_column_name(stmt, i);
      std::string value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));

      values.insert(std::make_pair(key, value));
    }

    entity = EntityFactory::GetInstance().CreateFromFieldsValues(values);
  }

  sqlite3_finalize(stmt);

  return entity;
}
