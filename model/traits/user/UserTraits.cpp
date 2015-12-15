#include "UserTraits.h"

using todos_model_traits::UserTraits;

const char *UserTraits::GetIdFieldName() const
{
  return "user_id";
}

UserTraits::FieldsNamesContainer UserTraits::GetFieldsNames() const
{
  static FieldsNamesContainer fieldsNames{"user_id", "login", "password", "signedup_on"};

  return fieldsNames;
}

const char* UserTraits::GetTableName() const
{
  return "User";
}
