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
    unsigned int id = todos_utility::StringToInt(values.at(CommentaryTraits().GetIdFieldName()));
    unsigned int taskId = todos_utility::StringToInt(values.at("task_id"));
    QDateTime publishedOn = todos_utility::StringToQDateTime(values.at("published_on"));
    Commentary::Type type = StringToCommentaryType(values.at("type"));
    std::string content = values.at("content");

    ptrEntity.reset(new Commentary(id, taskId, type, publishedOn, content));
  }

  return ptrEntity;
}

CommentaryFactory::FieldsValuesContainer CommentaryFactory::RevertToFieldsValues(const CommentaryFactory::Entity &entity) const
{
  FieldsValuesContainer values;

  values.insert(std::make_pair(CommentaryTraits().GetIdFieldName(), todos_utility::IntToString(entity.GetId())));
  values.insert(std::make_pair("task_id", todos_utility::IntToString(entity.GetTaskId())));
  values.insert(std::make_pair("content", entity.GetContent()));
  values.insert(std::make_pair("published_on", todos_utility::QDateTimeToString(entity.GetPublishedOn())));
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
