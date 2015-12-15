#ifndef TODOS_MODEL_ENTITY_CATEGORY_H
#define TODOS_MODEL_ENTITY_CATEGORY_H

#include <string>

#include <model/entity/IEntity.h>

namespace todos_model_entity {
  class Category: public IEntity
  {
  public:
    typedef std::string String;

  private:
    String m_name;

  public:
    Category(unsigned long id, const String& name);

    String GetName() const;

    void SetName(const String& name);
  };
}

#endif //TODOS_MODEL_ENTITY_CATEGORY_H
