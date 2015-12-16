#include "BaseRepository.h"

#include <utility/StringConversions.h>

using todos_model_repository::BaseRepository;

BaseRepository::BaseRepository(const Schema &schema) :
  m_db(schema)
{
}

BaseRepository::Id BaseRepository::Insert(const EntityTraits::FieldsValuesContainer& values, const EntityTraits& traits)
{
  EntityTraits::FieldsNamesContainer&& fields = traits.GetFieldsNames();

  if (values.empty()) {
    return 0;
  }

  std::string valuesString = "";
  std::string fieldsString = "";

  for (auto i = fields.begin(), iend = fields.end(); i != iend; ++i) {
    fieldsString += "`" + *i + "`";

    if (traits.GetIdFieldName() == *i) {
      // Set NULL for id field

      valuesString += "NULL";
    } else {
      valuesString += "?";
    }

    if ((i + 1) != iend) {
      fieldsString += ", ";
      valuesString += ", ";
    }
  }

  std::string query = "INSERT INTO `" + std::string(traits.GetTableName()) + "` (" + fieldsString + ") VALUES (" + valuesString + "); ";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(m_db.GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  {
    int valueIndex = 1;

    for (auto i = fields.begin(), iend = fields.end(); i != iend; ++i) {
      if (traits.GetIdFieldName() == *i) {
        // Skip id field -- it is already set to NULL

        continue;
      } else {
        sqlite3_bind_text(stmt, valueIndex, values.at(*i).c_str(), -1, SQLITE_TRANSIENT);

        ++valueIndex;
      }
    }
  }

  unsigned long lastRowId;

  if (sqlite3_step(stmt) == SQLITE_DONE) {
    lastRowId = sqlite3_last_insert_rowid(m_db.GetDatabaseHandle());
  } else {
    lastRowId = 0;
  }

  sqlite3_finalize(stmt);

  return lastRowId;
}

bool BaseRepository::Update(Id id, const EntityTraits::FieldsValuesContainer& values, const EntityTraits& traits)
{
  EntityTraits::FieldsNamesContainer&& fields = traits.GetFieldsNames();

  if (values.empty()) {
    return 0;
  }

  std::string fieldsString = "";

  for (auto i = fields.begin(), iend = fields.end(); i != iend; ++i) {
    fieldsString += "`" + *i + "` = ?";

    if ((i + 1) != iend) {
      fieldsString += ", ";
    }
  }

  std::string query = "UPDATE `" + std::string(traits.GetTableName()) + "` SET " + fieldsString + " WHERE `" + traits.GetIdFieldName() + "` = '" + todos_utility::IntToString(id) + "'";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(m_db.GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  for (int i = 0, iend = fields.size(); i != iend; ++i) {
    sqlite3_bind_text(stmt, i + 1, values.at(fields[i]).c_str(), -1, SQLITE_TRANSIENT);
  }

  bool result = (sqlite3_step(stmt) == SQLITE_DONE);

  sqlite3_finalize(stmt);

  return result;
}

bool BaseRepository::Delete(BaseRepository::Id id, const EntityTraits& traits)
{
  std::string query = "DELETE FROM `" + std::string(traits.GetTableName()) + "` WHERE `" + traits.GetIdFieldName() + "` = '" + todos_utility::IntToString(id) + "'";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  bool result = (sqlite3_step(stmt) == SQLITE_DONE);

  sqlite3_finalize(stmt);

  return result;
}

BaseRepository::EntityTraits::FieldsValuesContainer BaseRepository::FindOneById(BaseRepository::Id id, const EntityTraits& traits)
{
  EntityTraits::FieldsValuesContainer values;

  std::string query = "SELECT * FROM `" + std::string(traits.GetTableName()) + "` WHERE `" + traits.GetIdFieldName() + "` = '" + todos_utility::IntToString(id) + "'";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    for (int i = 0, iend = sqlite3_column_count(stmt); i != iend; ++i) {
      std::string key = sqlite3_column_name(stmt, i);
      std::string value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));

      values.insert(std::make_pair(key, value));
    }
  }

  sqlite3_finalize(stmt);

  return values;
}

BaseRepository::Schema BaseRepository::GetSchema()
{
  return m_db;
}

void BaseRepository::SetSchema(const BaseRepository::Schema &schema)
{
  m_db = schema;
}


//while (sqlite3_step(stmt) == SQLITE_ROW) {
//}

