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
    unsigned long m_userId;
    String m_name;

  public:
    Category(unsigned long id, unsigned long userId, const String& name);

    unsigned long GetUserId() const;
    String GetName() const;

    void SetUserId(unsigned long userId);
    void SetName(const String& name);
  };
}

#endif //TODOS_MODEL_ENTITY_CATEGORY_H
