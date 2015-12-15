#ifndef TODOS_MODEL_REPOSITORY_CATEGORYREPOSITORY_H
#define TODOS_MODEL_REPOSITORY_CATEGORYREPOSITORY_H

#include <model/repository/IRepository.h>

#include <model/entity/category/Category.h>
#include <model/traits/category/CategoryTraits.h>
#include <model/factory/category/CategoryFactory.h>

namespace todos_model_repository {
  class CategoryRepository: public IRepository<todos_model_entity::Category, todos_model_traits::CategoryTraits, todos_model_factory::CategoryFactory>
  {
  public:
    CategoryRepository(const Schema& schema);

    std::vector<EntitySharedPtr> FindAll(unsigned long userId);
  };
}

#endif //TODOS_MODEL_REPOSITORY_CATEGORYREPOSITORY_H
