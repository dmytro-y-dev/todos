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

    typedef std::string BLOBContentItem;
    typedef QDateTime DateTime;
    typedef std::shared_ptr<std::string> ContentPtr;

  private:
    unsigned long m_id;
    Type m_type;
    DateTime m_publishedOn;
    ContentPtr m_content;

  public:
    Commentary(unsigned long id, Type type, const DateTime& publishedOn, ContentPtr content);

    unsigned long GetId() const;
    Type GetType() const;
    DateTime GetPublishedOn() const;
    ContentPtr GetContent() const;

    void SetId(unsigned int id);
    void SetType(Type type);
    void SetPublishedOn(const DateTime& publishedOn);
    void SetContent(ContentPtr content);
  };
}

#endif //TODOS_MODEL_ENTITY_COMMENTARY_H