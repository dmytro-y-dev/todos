#include "IEntityTraits.h"

using todos_model_traits::IEntityTraits;

bool todos_model_traits::AreFieldsFromSameEntity(const IEntityTraits::FieldsNamesContainer &names, const IEntityTraits::FieldsValuesContainer &values)
{
  for (auto i = names.begin(), iend = names.end(); i != iend; ++i) {
    if (values.find(*i) == values.end()) {
      return false;
    }
  }

  return true;
}
