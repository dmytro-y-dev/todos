#ifndef TODOS_MODEL_TRAITS_COMMENTARYTRAITS_H
#define TODOS_MODEL_TRAITS_COMMENTARYTRAITS_H

#include <model/traits/IEntityTraits.h>

namespace todos_model_traits {
  class CommentaryTraits: public IEntityTraits
  {
  public:
    virtual FieldsNamesContainer GetFieldsNames() const override;
    virtual const char* GetTableName() const override;
    virtual const char *GetIdFieldName() const override;
  };
}

#endif //TODOS_MODEL_TRAITS_COMMENTARYTRAITS_H
