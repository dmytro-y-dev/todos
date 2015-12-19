#include "UserFactory.h"

#include <utility/StringConversions.h>

using todos_model_factory::UserFactory;
using todos_model_entity::User;
using todos_model_traits::UserTraits;
using todos_model_traits::AreFieldsFromSameEntity;

UserFactory::EntitySharedPtr UserFactory::CreateFromFieldsValues(const UserFactory::FieldsValuesContainer &values) const
{
  EntitySharedPtr ptrEntity;

  if (AreFieldsFromSameEntity(UserTraits().GetFieldsNames(), values)) {
    unsigned int id = todos_utility::StringToInt(values.at(UserTraits().GetIdFieldName()));
    std::string login = values.at("login");
    std::string password = values.at("password");
    QDateTime signedUpOn = todos_utility::StringToQDateTime(values.at("signedup_on"));

    ptrEntity.reset(new User(id, login, password, signedUpOn));
  }

  return ptrEntity;
}

UserFactory::FieldsValuesContainer UserFactory::RevertToFieldsValues(const UserFactory::Entity &entity) const
{
  FieldsValuesContainer values;

  values.insert(std::make_pair(UserTraits().GetIdFieldName(), todos_utility::IntToString(entity.GetId())));
  values.insert(std::make_pair("login", entity.GetLogin()));
  values.insert(std::make_pair("password", entity.GetPassword()));
  values.insert(std::make_pair("signedup_on", todos_utility::QDateTimeToString(entity.GetSignedUpOn())));

  return values;
}
