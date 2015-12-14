#include "UserRepository.h"

#include <map>
#include <string>

#include <model/entity/IEntity.h>

using todos_model_repository::UserRepository;

UserRepository::UserRepository(const Schema &schema) :
   IRepository(schema)
{
}

static int readSingleRow(void *ptrEntity, int argc, char **argv, char **azColName)
{
  UserRepository::EntitySharedPtr& entity = *(static_cast<UserRepository::EntitySharedPtr*>(ptrEntity));

  std::map<std::string, std::string> pairs;
  for (int i = 0; i < argc; i++) {
    std::string key = azColName[i], value = argv[i];
    pairs.insert(std::make_pair(key, value));
  }

  static const char* requiredNames[] = {"user_id", "login", "password", "signedup_on"};
  for (int i = 0, iend = sizeof(requiredNames) / sizeof(char**); i != iend; ++i) {
    if (pairs.find(requiredNames[i]) == pairs.end()) {
      return 1;
    }
  }

  unsigned long id = stoi(pairs.find("user_id")->second);
  std::string login = pairs.find("login")->second;
  std::string password = pairs.find("password")->second;
  QDateTime signedUpOn = QDateTime::fromString(QString::fromStdString(pairs.find("signedup_on")->second));

  entity.reset(new todos_model_entity::User(id, login, password, signedUpOn));

  return 0;
}

UserRepository::EntitySharedPtr UserRepository::FindOneById(Id id)
{
  EntitySharedPtr entity;

  std::string queryGetEntityById = "SELECT * FROM `User` WHERE `user_id` = '" + std::to_string(id) + "'";
  sqlite3_exec(GetSchema().GetDatabaseHandle(), queryGetEntityById.c_str(), readSingleRow, &entity, nullptr);

  return entity;
}
