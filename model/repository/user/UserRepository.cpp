#include "UserRepository.h"

using todos_model_entity::User;
using todos_model_factory::UserFactory;
using todos_model_repository::UserRepository;

UserRepository::UserRepository(const Schema &schema) :
   IRepository<Entity, EntityTraits, EntityFactory>(schema)
{
}
