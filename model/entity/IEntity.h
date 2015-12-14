#ifndef TODOS_MODEL_ENTITY_IENTITY_H
#define TODOS_MODEL_ENTITY_IENTITY_H

#include <string>
#include <vector>
#include <map>

namespace todos_model_entity {
  class IEntity
  {
  public:
    typedef std::vector<std::string> FieldsContainer;
    typedef std::map<std::string, std::string> KeysValuesContainer;

  public:
    virtual ~IEntity();

    virtual KeysValuesContainer GetPairsRepresentation() const = 0;
    virtual FieldsContainer GetFieldsNames() const = 0;
    virtual const char* GetTableName() const = 0;
    virtual const char* GetIdFieldName() const = 0;
  };
}

#endif //TODOS_MODEL_ENTITY_IENTITY_H
