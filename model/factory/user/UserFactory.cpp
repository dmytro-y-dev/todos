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
    unsigned int id = std::stoi(values.at(UserTraits().GetIdFieldName()));
    std::string login = values.at("login");
    std::string password = values.at("password");
    QDateTime signedUpOn = QDateTime::fromString(QString::fromStdString(values.at("signedup_on")));

    ptrEntity.reset(new User(id, login, password, signedUpOn));
  }

  return ptrEntity;
}

UserFactory::FieldsValuesContainer UserFactory::RevertToFieldsValues(const UserFactory::Entity &entity) const
{
  FieldsValuesContainer values;

  values.insert(std::make_pair(UserTraits().GetIdFieldName(), std::to_string(entity.GetId())));
  values.insert(std::make_pair("login", entity.GetLogin()));
  values.insert(std::make_pair("password", entity.GetPassword()));
  values.insert(std::make_pair("signedup_on", entity.GetSignedUpOn().toString("yyyy-M-d H:m:s").toStdString()));

  return values;
}
