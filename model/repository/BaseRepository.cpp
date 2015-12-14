#include "BaseRepository.h"

using todos_model_repository::BaseRepository;

BaseRepository::BaseRepository(const Schema &schema) :
  m_db(schema)
{
}

BaseRepository::IdContainer BaseRepository::Insert(const BaseRepository::EntityWeakPtrContainer &entities)
{
  // TODO : Implement
}

size_t BaseRepository::Update(const BaseRepository::EntityWeakPtrContainer &entities)
{
  // TODO : Implement
}

size_t BaseRepository::Delete(const BaseRepository::IdContainer &ids)
{
  // TODO : Implement
}

BaseRepository::Id BaseRepository::Insert(BaseRepository::EntityWeakPtr entity)
{
  std::shared_ptr<Entity> lockedEntity = entity.lock();

  Entity::KeysValuesContainer&& values = lockedEntity->GetPairsRepresentation();
  Entity::FieldsContainer&& fields = lockedEntity->GetFieldsNames();

  if (values.empty()) {
    return 0;
  }

  std::string valuesString = "";
  std::string fieldsString = "";

  for (auto i = fields.begin(), iend = fields.end(); i != iend; ++i) {
    fieldsString += "`" + *i + "`";

    if (lockedEntity->GetIdFieldName() == *i) { // Id field found
      valuesString += "NULL";
    } else {
      // TODO: Make correct escape routine for values

      valuesString += "'" + values[*i] + "'";
    }

    if ((i + 1) != iend) {
      fieldsString += ", ";
      valuesString += ", ";
    }
  }

  std::string query = "INSERT INTO `" + std::string(lockedEntity->GetTableName()) + "` (" + fieldsString + ") VALUES (" + valuesString + "); ";
  sqlite3_exec(m_db.GetDatabaseHandle(), query.c_str(), nullptr, nullptr, nullptr);

  // TODO: Return autoincrement value

  return 1;
}

size_t BaseRepository::Update(const BaseRepository::EntityWeakPtr entity)
{
  // TODO : Implement
}

size_t BaseRepository::Delete(BaseRepository::Id id)
{
  // TODO : Implement
}

BaseRepository::Schema BaseRepository::GetSchema()
{
  return m_db;
}

void BaseRepository::SetSchema(const BaseRepository::Schema &schema)
{
  m_db = schema;
}
