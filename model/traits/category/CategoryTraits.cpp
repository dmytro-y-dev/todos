#include "CategoryTraits.h"

using todos_model_traits::CategoryTraits;

const char *CategoryTraits::GetIdFieldName() const
{
  return "category_id";
}

CategoryTraits::FieldsNamesContainer CategoryTraits::GetFieldsNames() const
{
  static FieldsNamesContainer fieldsNames{"category_id", "user_id", "name"};

  return fieldsNames;
}

const char* CategoryTraits::GetTableName() const
{
  return "Category";
}
