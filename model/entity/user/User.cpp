#include "User.h"

using todos_model_entity::User;

User::User(unsigned long id, const User::String &login, const User::String &password, const User::DateTime &signedUpOn) :
  IEntity(id), m_login(login), m_password(password), m_signedUpOn(signedUpOn)
{
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


