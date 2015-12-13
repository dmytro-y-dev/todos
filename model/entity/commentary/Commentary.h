#ifndef TODOS_MODEL_ENTITY_COMMENTARY_H
#define TODOS_MODEL_ENTITY_COMMENTARY_H

#include <string>
#include <memory>
#include <QDateTime>

namespace todos_model_entity {
  class Commentary
  {
  public:
    enum class Type {
      UNKNOWN = 0,

      TEXT = 1,
      IMAGE_PNG = 2
    };

    typedef QDateTime DateTime;
    typedef std::string Content;

  private:
    unsigned long m_id;
    Type m_type;
    DateTime m_publishedOn;
    Content m_content;

  public:
    Commentary(unsigned long id, Type type, const DateTime& publishedOn, const Content& content);

    unsigned long GetId() const;
    Type GetType() const;
    DateTime GetPublishedOn() const;
    Content GetContent() const;

    void SetId(unsigned int id);
    void SetType(Type type);
    void SetPublishedOn(const DateTime& publishedOn);
    void SetContent(const Content& content);
  };
}

#endif //TODOS_MODEL_ENTITY_COMMENTARY_H
