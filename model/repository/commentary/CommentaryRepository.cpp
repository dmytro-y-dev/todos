#include "CommentaryRepository.h"

using todos_model_entity::Commentary;
using todos_model_factory::CommentaryFactory;
using todos_model_repository::CommentaryRepository;

CommentaryRepository::CommentaryRepository(const Schema &schema) :
   IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}

std::vector<CommentaryRepository::EntitySharedPtr> CommentaryRepository::FindAll(unsigned long taskId)
{
  std::string query = "SELECT * FROM `Commentary` WHERE `task_id` = '" + std::to_string(taskId) + "' ORDER BY `published_on`;";

  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(GetBaseRepository().GetSchema().GetDatabaseHandle(), query.c_str(), -1, &stmt, NULL);

  std::vector<EntitySharedPtr>&& entities = FindAllUsingSQLStatement(stmt);

  sqlite3_finalize(stmt);

  return entities;
}
