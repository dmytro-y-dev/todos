#include <gtest/gtest.h>

#include <model/entity/Task.h>

using todos_model_entity::Task;

class TestModelEntityTask: public ::testing::Test
{
public:
  TestModelEntityTask()
  {
  }

protected:
  virtual void SetUp()
  {
  }

  virtual void TearDown()
  {
  }
};

TEST_F(TestModelEntityTask, TaskGettersSetters)
{
  unsigned int id = 1;
  Task::String title = "task";
  Task::Priority priority = Task::Priority::LOW;
  Task::DateTime dueDate = QDateTime(QDate(2015, 12, 13), QTime(20, 14));
  Task::String commentary = "comment";
  Task::DateTime reminderDate = QDateTime(QDate(2015, 12, 14), QTime(21, 14));
  Task::Status status = Task::Status::UNCOMPLETED;
  Task task(id, title, priority, dueDate, commentary, reminderDate, status);

  ASSERT_TRUE(task.GetId() == id);
  ASSERT_TRUE(task.GetTitle() == title);
  ASSERT_TRUE(task.GetPriority() == priority);
  ASSERT_TRUE(task.GetDueDate() == dueDate);
  ASSERT_TRUE(task.GetCommentary() == commentary);
  ASSERT_TRUE(task.GetReminderDate() == reminderDate);
  ASSERT_TRUE(task.GetStatus() == status);

  unsigned int newId = 2;
  task.SetId(newId);
  EXPECT_TRUE(task.GetId() == newId);

  Task::String newTitle = "task-new-title";
  task.SetTitle(newTitle);
  EXPECT_TRUE(task.GetTitle() == newTitle);

  Task::Priority newPriority = Task::Priority::HIGH;
  task.SetPriority(newPriority);
  EXPECT_TRUE(task.GetPriority() == newPriority);

  Task::DateTime newDueDate = QDateTime(QDate(2015, 10, 13), QTime(20, 24));
  task.SetDueDate(newDueDate);
  EXPECT_TRUE(task.GetDueDate() == newDueDate);

  Task::String newCommentary = "comment-updated";
  task.SetCommentary(newCommentary);
  EXPECT_TRUE(task.GetCommentary() == newCommentary);

  Task::DateTime newReminderDate = QDateTime(QDate(2015, 9, 13), QTime(20, 14));
  task.SetReminderDate(newReminderDate);
  EXPECT_TRUE(task.GetReminderDate() == newReminderDate);

  Task::Status newStatus = Task::Status::COMPLETED;
  task.SetStatus(newStatus);
  EXPECT_TRUE(task.GetStatus() == newStatus);
}
