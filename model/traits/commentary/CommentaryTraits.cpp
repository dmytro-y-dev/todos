#include "CommentaryTraits.h"

using todos_model_traits::CommentaryTraits;

const char *CommentaryTraits::GetIdFieldName() const
{
  return "commentary_id";
}

CommentaryTraits::FieldsNamesContainer CommentaryTraits::GetFieldsNames() const
{
  static FieldsNamesContainer fieldsNames{"commentary_id", "task_id", "published_on", "type", "content"};

  return fieldsNames;
}

const char* CommentaryTraits::GetTableName() const
{
  return "Commentary";
}
