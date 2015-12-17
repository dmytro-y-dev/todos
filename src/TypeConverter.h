#ifndef TYPECONVERTER_H
#define TYPECONVERTER_H

#include <../model/entity/task/Task.h>
#include <../model/entity/commentary/Commentary.h>
#include <../model/repository/task/TaskFilterSettings.h>
#include <../model/repository/task/TaskRepository.h>

using Priority         = todos_model_entity::Task::Priority;
using Status           = todos_model_entity::Task::Status;
using CommentaryType   = todos_model_entity::Commentary::Type;
using TaskSortSettings = todos_model_repository::TaskRepository::TaskSortSettings;

class TypeConverter
{
public:
	static QString toString(Priority priority);
	static Priority toPriority(const QString &str);

	static QString toString(Status status);
	static Status toStatus(const QString &str);

	static QString toString(CommentaryType type);
	static CommentaryType toCommentaryType(const QString &str);

	static QString toString(TaskSortSettings::Field field);
	static TaskSortSettings::Field toTaskSortField(const QString &str);
};

#endif // TYPECONVERTER_H
