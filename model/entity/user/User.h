#ifndef TODOS_MODEL_ENTITY_USER_H
#define TODOS_MODEL_ENTITY_USER_H

#include <string>
#include <QDateTime>

namespace todos_model_entity {
  class User
  {
  public:
    typedef QDateTime DateTime;
    typedef std::string String;

  private:
    unsigned long m_id;
    String m_login;
    String m_password;
    DateTime m_signedUpOn;

  public:
    User(unsigned long id, const String& login, const String& password, const DateTime& signedUpOn);

    unsigned long GetId() const;
    String GetLogin() const;
    String GetPassword() const;
    DateTime GetSignedUpOn() const;

    void SetId(unsigned int id);
    void SetLogin(const String& login);
    void SetPassword(const String& password);
    void SetSignedUpOn(const DateTime& signedUpOn);
  };
}

#endif //TODOS_MODEL_ENTITY_USER_H
