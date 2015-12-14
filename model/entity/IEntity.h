#ifndef TODOS_MODEL_ENTITY_IENTITY_H
#define TODOS_MODEL_ENTITY_IENTITY_H

#include <string>

namespace todos_model_entity {
  class IEntity
  {
  public:
    virtual ~IEntity();

    virtual std::string SQLInsertScript() const = 0;
    virtual std::string SQLUpdateScript() const = 0;
  };
}

#endif //TODOS_MODEL_ENTITY_IENTITY_H
