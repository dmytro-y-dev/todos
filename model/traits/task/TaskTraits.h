#ifndef TODOS_MODEL_TRAITS_TASKTRAITS_H
#define TODOS_MODEL_TRAITS_TASKTRAITS_H

#include <model/traits/IEntityTraits.h>

namespace todos_model_traits {
  class TaskTraits: public IEntityTraits
  {
  public:
    virtual FieldsNamesContainer GetFieldsNames() const override;
    virtual const char* GetTableName() const override;
    virtual const char *GetIdFieldName() const override;
  };
}

#endif //TODOS_MODEL_TRAITS_TASKTRAITS_H
