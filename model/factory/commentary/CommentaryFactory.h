#ifndef TODOS_MODEL_FACTORY_COMMENTARYFACTORY_H
#define TODOS_MODEL_FACTORY_COMMENTARYFACTORY_H

#include <memory>
#include <vector>
#include <utility>

#include <model/entity/Commentary/Commentary.h>
#include <model/traits/Commentary/CommentaryTraits.h>

namespace todos_model_factory {
  class CommentaryFactory
  {
  public:
    typedef todos_model_entity::Commentary Entity;
    typedef std::shared_ptr<Entity> EntitySharedPtr;
    typedef todos_model_traits::IEntityTraits::FieldsValuesContainer FieldsValuesContainer;

  private:
    std::vector<std::pair<std::string, Entity::Type> > m_commentaryTypeMapping;

  public:
    static CommentaryFactory& GetInstance()
    {
      static CommentaryFactory instance;
      return instance;
    }

    EntitySharedPtr CreateFromFieldsValues(const FieldsValuesContainer &values) const;
    FieldsValuesContainer RevertToFieldsValues(const Entity &entity) const;

  private:
    CommentaryFactory();

    CommentaryFactory(const CommentaryFactory&) = delete;
    CommentaryFactory& operator=(const CommentaryFactory&) = delete;

    std::string CommentaryTypeToString(Entity::Type type) const;
    Entity::Type StringToCommentaryType(const std::string& type) const;
  };
}

#endif //TODOS_MODEL_FACTORY_COMMENTARYFACTORY_H
