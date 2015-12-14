#include "User.h"

using todos_model_entity::User;

User::User(unsigned long id, const User::String &login, const User::String &password, const User::DateTime &signedUpOn) :
  m_id(id), m_login(login), m_password(password), m_signedUpOn(signedUpOn)
{
}

unsigned long User::GetId() const
{
  return m_id;
}

User::String User::GetLogin() const
{
  return m_login;
}

User::String User::GetPassword() const
{
  return m_password;
}

User::DateTime User::GetSignedUpOn() const
{
  return m_signedUpOn;
}

void User::SetId(unsigned int id)
{
  m_id = id;
}

void User::SetLogin(const User::String &login)
{
  m_login = login;
}

void User::SetPassword(const User::String &password)
{
  m_password = password;
}

void User::SetSignedUpOn(const User::DateTime &signedUpOn)
{
  m_signedUpOn = signedUpOn;
}

User::KeysValuesContainer User::GetPairsRepresentation() const
{
  KeysValuesContainer pairs;

  pairs.insert(std::make_pair("user_id", std::to_string(GetId())));
  pairs.insert(std::make_pair("login", GetLogin()));
  pairs.insert(std::make_pair("password", GetPassword()));
  pairs.insert(std::make_pair("signedup_on", GetSignedUpOn().toString("yyyy-M-d H:m:s").toStdString()));

  return pairs;
}

const char *User::GetIdFieldName() const
{
  return "user_id";
}

User::FieldsContainer User::GetFieldsNames() const
{
  static FieldsContainer fields;

  if (fields.empty()) {
    fields.push_back("user_id");
    fields.push_back("login");
    fields.push_back("password");
    fields.push_back("signedup_on");
  }

  return fields;
}

const char* User::GetTableName() const
{
  return "User";
}

