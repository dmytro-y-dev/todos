#ifndef TODOS_MODEL_TRAITS_IENTITYTRAITS_H
#define TODOS_MODEL_TRAITS_IENTITYTRAITS_H

#include <string>
#include <map>
#include <vector>

namespace todos_model_traits {
  class IEntityTraits
  {
  public:
    typedef std::vector<std::string> FieldsNamesContainer;
    typedef std::map<std::string, std::string> FieldsValuesContainer;

  public:
    virtual FieldsNamesContainer GetFieldsNames() const = 0;
    virtual const char* GetTableName() const = 0;
    virtual const char *GetIdFieldName() const = 0;
  };

  bool AreFieldsFromSameEntity(const IEntityTraits::FieldsNamesContainer& names, const IEntityTraits::FieldsValuesContainer& values);
}

#endif //TODOS_MODEL_TRAITS_IENTITYTRAITS_H
