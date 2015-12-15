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
  std::string query = "SELECT * FROM `User` WHERE `login` = '" + login + "';";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetBaseRepository().GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  UserRepository::EntitySharedPtr entity = FindOneUsingSQLStatement(stmt);

  sqlite3_finalize(stmt);

  return entity;
}
