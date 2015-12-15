#include "CategoryRepository.h"

using todos_model_entity::Category;
using todos_model_factory::CategoryFactory;
using todos_model_repository::CategoryRepository;

CategoryRepository::CategoryRepository(const Schema &schema) :
   IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}
