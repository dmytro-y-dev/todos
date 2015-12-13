#ifndef TODOS_MODEL_ENTITY_CATEGORY_H
#define TODOS_MODEL_ENTITY_CATEGORY_H

#include <string>

namespace todos_model_entity {
  class Category
  {
  public:
    typedef std::string String;

  private:
    unsigned long m_id;
    String m_name;

  public:
    Category(unsigned long id, const String& name);

    unsigned long GetId() const;
    String GetName() const;

    void SetId(unsigned int id);
    void SetName(const String& name);
  };
}

#endif //TODOS_MODEL_ENTITY_CATEGORY_H
