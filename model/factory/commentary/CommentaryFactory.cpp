#include "CommentaryFactory.h"

#include <utility/StringConversions.h>

using todos_model_factory::CommentaryFactory;
using todos_model_entity::Commentary;
using todos_model_traits::CommentaryTraits;
using todos_model_traits::AreFieldsFromSameEntity;

CommentaryFactory::EntitySharedPtr CommentaryFactory::CreateFromFieldsValues(const CommentaryFactory::FieldsValuesContainer &values) const
{
  EntitySharedPtr ptrEntity;

  if (AreFieldsFromSameEntity(CommentaryTraits().GetFieldsNames(), values)) {
    unsigned int id = std::stoi(values.at(CommentaryTraits().GetIdFieldName()));
    unsigned int taskId = std::stoi(values.at("task_id"));
    QDateTime publishedOn = QDateTime::fromString(QString::fromStdString(values.at("published_on")));
    Commentary::Type type = StringToCommentaryType(values.at("type"));
    std::string content = values.at("content");

    ptrEntity.reset(new Commentary(id, taskId, type, publishedOn, content));
  }

  return ptrEntity;
}

CommentaryFactory::FieldsValuesContainer CommentaryFactory::RevertToFieldsValues(const CommentaryFactory::Entity &entity) const
{
  FieldsValuesContainer values;

  values.insert(std::make_pair(CommentaryTraits().GetIdFieldName(), std::to_string(entity.GetId())));
  values.insert(std::make_pair("task_id", std::to_string(entity.GetTaskId())));
  values.insert(std::make_pair("content", entity.GetContent()));
  values.insert(std::make_pair("published_on", entity.GetPublishedOn().toString("yyyy-M-d H:m:s").toStdString()));
  values.insert(std::make_pair("type", CommentaryTypeToString(entity.GetType())));

  return values;
}

CommentaryFactory::CommentaryFactory()
{
  m_commentaryTypeMapping.push_back(std::make_pair("text", Commentary::Type::TEXT));
  m_commentaryTypeMapping.push_back(std::make_pair("image/png", Commentary::Type::IMAGE_PNG));
}

std::string CommentaryFactory::CommentaryTypeToString(Commentary::Type type) const
{
  for (auto i = m_commentaryTypeMapping.begin(), iend = m_commentaryTypeMapping.end(); i != iend; ++i) {
    if (i->second == type) {
      return i->first;
    }
  }

  return "";
}

Commentary::Type CommentaryFactory::StringToCommentaryType(const std::string &type) const
{
  for (auto i = m_commentaryTypeMapping.begin(), iend = m_commentaryTypeMapping.end(); i != iend; ++i) {
    if (i->first == type) {
      return i->second;
    }
  }

  return Commentary::Type::UNKNOWN;
}
