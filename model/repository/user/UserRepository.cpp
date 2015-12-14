#include "UserRepository.h"

using todos_model_repository::UserRepository;

UserRepository::UserRepository(const Schema &schema) :
   IRepository(schema)
{
}
