#include "CommentaryRepository.h"

using todos_model_entity::Commentary;
using todos_model_factory::CommentaryFactory;
using todos_model_repository::CommentaryRepository;

CommentaryRepository::CommentaryRepository(const Schema &schema) :
   IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}
