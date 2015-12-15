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
  std::vector<CommentaryRepository::EntitySharedPtr> entities;
  std::string query = "SELECT * FROM `Commentary` WHERE `task_id` = '" + std::to_string(taskId) + "' ORDER BY `published_on`;";

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
