#include "BaseRepository.h"

using todos_model_repository::BaseRepository;

BaseRepository::BaseRepository(const Schema &schema) :
  m_db(schema)
{
}

BaseRepository::IdContainer BaseRepository::Insert(const BaseRepository::EntityWeakPtrContainer &entities)
{

}

size_t BaseRepository::Update(const BaseRepository::EntityWeakPtrContainer &entities)
{

}

size_t BaseRepository::Delete(const BaseRepository::IdContainer &ids)
{

}

BaseRepository::Id BaseRepository::Insert(BaseRepository::EntitySharedPtr entity)
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

  sqlite3_exec(m_db.GetDatabaseHandle(), query, nullptr, nullptr, nullptr);
}

size_t BaseRepository::Update(const BaseRepository::EntitySharedPtr entity)
{

}

size_t BaseRepository::Delete(BaseRepository::Id id)
{

}

BaseRepository::EntitySharedPtrContainer BaseRepository::FindAll()
{

}

BaseRepository::EntitySharedPtr BaseRepository::FindOneById(BaseRepository::Id id)
{

}

BaseRepository::Schema BaseRepository::GetSchema()
{

}

void BaseRepository::SetSchema(const BaseRepository::Schema &schema)
{

}
