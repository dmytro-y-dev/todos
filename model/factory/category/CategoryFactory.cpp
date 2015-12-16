#include "CategoryFactory.h"

#include <utility/StringConversions.h>

using todos_model_factory::CategoryFactory;
using todos_model_entity::Category;
using todos_model_traits::CategoryTraits;
using todos_model_traits::AreFieldsFromSameEntity;

CategoryFactory::EntitySharedPtr CategoryFactory::CreateFromFieldsValues(const CategoryFactory::FieldsValuesContainer &values) const
{
  EntitySharedPtr ptrEntity;

  if (AreFieldsFromSameEntity(CategoryTraits().GetFieldsNames(), values)) {
    unsigned int id = std::stoi(values.at(CategoryTraits().GetIdFieldName()));
    unsigned int userId = std::stoi(values.at("user_id"));
    std::string name = values.at("name");

    ptrEntity.reset(new Category(id, userId, name));
  }

  return ptrEntity;
}

CategoryFactory::FieldsValuesContainer CategoryFactory::RevertToFieldsValues(const CategoryFactory::Entity &entity) const
{
  FieldsValuesContainer values;

  values.insert(std::make_pair(CategoryTraits().GetIdFieldName(), std::to_string(entity.GetId())));
  values.insert(std::make_pair("user_id",std::to_string(entity.GetUserId())));
  values.insert(std::make_pair("name", entity.GetName()));

  return values;
}
