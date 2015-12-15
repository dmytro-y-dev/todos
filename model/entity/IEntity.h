#ifndef TODOS_MODEL_ENTITY_IENTITY_H
#define TODOS_MODEL_ENTITY_IENTITY_H

namespace todos_model_entity {
  class IEntity
  {
  private:
    unsigned long m_id;

  public:
    IEntity(unsigned long id);
    virtual ~IEntity();

    unsigned long GetId() const;
    void SetId(unsigned int id);
  };
}

#endif //TODOS_MODEL_ENTITY_IENTITY_H
