#ifndef TODOS_MODEL_ENTITY_CATEGORY_H
#define TODOS_MODEL_ENTITY_CATEGORY_H

#include <string>

namespace todos_model_enity {
  class Category
  {
  private:
    unsigned long m_id;
    std::string m_name;

  public:
    Category(unsigned long id, std::string name) :
      m_id(id), m_name(name)
    {
    }

    unsigned long GetId() const
    {
      return m_id;
    }

    std::string GetName() const
    {
      return m_name;
    }

    void SetId(unsigned int id)
    {
      m_id = id;
    }

    void SetName(const std::string& name)
    {
      m_name = name;
    }
  };
}

#endif //TODOS_MODEL_ENTITY_CATEGORY_H
