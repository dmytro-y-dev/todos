#ifndef TODOS_MODEL_REPOSITORY_COMMENTARYREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_COMMENTARYREPOSITORY_H

#include <model/repository/IRepository.h>

#include <model/entity/commentary/Commentary.h>
#include <model/traits/commentary/CommentaryTraits.h>
#include <model/factory/commentary/CommentaryFactory.h>

namespace todos_model_repository {
  class CommentaryRepository: public IRepository<todos_model_entity::Commentary, todos_model_traits::CommentaryTraits, todos_model_factory::CommentaryFactory>
  {
  public:
    CommentaryRepository(const Schema& schema);

    std::vector<EntitySharedPtr> FindAll(unsigned long taskId);
  };
}

#endif //TODOS_MODEL_REPOSITORY_COMMENTARYREPOSITORY_H
