#include "Schema.h"

using namespace todos_model_schema;

Schema::Schema(const char *filename) : m_db(nullptr)
{
  Open(filename);
}

Schema::~Schema()
{
  Close();
}

sqlite3 *Schema::GetDatabaseHandle() const
{
  return m_db;
}

bool Schema::IsOpened() const
{
  return (m_db != nullptr);
}

void Schema::Open(const char *filename)
{
  if (m_db != nullptr) {
    Close();
  }

  sqlite3_open(filename, &m_db);
}

void Schema::Close()
{
  sqlite3_close(m_db);

  m_db = nullptr;
}

void Schema::CreateTables()
{
  static const char* query =
    "CREATE TABLE `User`( "
    "`user_id` INT PRIMARY KEY NOT NULL, "
    "`login` VARCHAR(255) UNIQUE NOT NULL, "
    "`password` VARCHAR(255) NOT NULL, "
    "`signedup_on` DATETIME NULL "
    "); "
    "CREATE TABLE `Category`( "
    "`category_id` INT PRIMARY KEY NOT NULL, "
    "`user_id` INT NOT NULL REFERENCES `User`(`user_id`) ON UPDATE CASCADE ON DELETE CASCADE, "
    "`name` VARCHAR(255) UNIQUE NOT NULL "
    "); "
    "CREATE TABLE `Task`( "
    "`task_id` INT PRIMARY KEY NOT NULL, "
    "`category_id` INT NOT NULL REFERENCES `Category`(`category_id`) ON UPDATE CASCADE ON DELETE CASCADE, "
    "`title` VARCHAR(255) NOT NULL, "
    "`priority` INT NOT NULL, "
    "`due_date` DATETIME NULL, "
    "`reminder_date` DATETIME NULL, "
    "`completed` BOOLEAN NOT NULL "
    "); "
    "CREATE TABLE `Commentary`( "
    "`commentary_id` INT PRIMARY KEY NOT NULL, "
    "`task_id` INT NOT NULL REFERENCES `Task`(`task_id`) ON UPDATE CASCADE ON DELETE CASCADE, "
    "`published_on` DATETIME NOT NULL, "
    "`type` VARCHAR(255) NOT NULL, "
    "`content` BLOB NOT NULL "
    "); ";

  sqlite3_exec(m_db, query, nullptr, nullptr, nullptr);
}

void Schema::DestroyTables()
{
  static const char* query =
    "DROP TABLE `Commentary`; "
    "DROP TABLE `Task`; "
    "DROP TABLE `Category`; "
    "DROP TABLE `User`; ";

  sqlite3_exec(m_db, query, nullptr, nullptr, nullptr);
}
