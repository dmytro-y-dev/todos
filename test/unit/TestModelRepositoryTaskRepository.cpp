#include <gtest/gtest.h>

#include <model/repository/Task/TaskRepository.h>

using todos_model_entity::Task;
using todos_model_repository::TaskRepository;
using todos_model_schema::Schema;

class TestModelRepositoryTaskRepository : public ::testing::Test
{
protected:
  Schema m_db;

public:
  TestModelRepositoryTaskRepository() : m_db(nullptr)
  {
  }

protected:
  virtual void SetUp()
  {
    remove("test-db-Task.sqlite3");
    m_db.Open("test-db-Task.sqlite3");
    m_db.CreateTables();
  }

  virtual void TearDown()
  {
    m_db.Close();
    remove("test-db-Task.sqlite3");
  }
};

TEST_F(TestModelRepositoryTaskRepository, TaskRepositoryInsertOneEntity)
{
  TaskRepository repository(m_db);

  Task entity(0, 1, "task1", Task::Priority::NORMAL, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), QDateTime(QDate(2015, 12, 14), QTime(13, 12)), Task::Status::COMPLETED);
  unsigned long insertId = repository.Insert(entity);

  ASSERT_TRUE(insertId != 0);

  auto foundEntity = repository.FindOneById(insertId);

  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetTitle() == entity.GetTitle());
}

TEST_F(TestModelRepositoryTaskRepository, TaskRepositoryUpdateOneEntity)
{
  TaskRepository repository(m_db);
  Task entity(0, 1, "task1", Task::Priority::NORMAL, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), QDateTime(QDate(2015, 12, 14), QTime(13, 12)), Task::Status::COMPLETED);
  Task updatedEntity(0, 1, "task2", Task::Priority::LOW, QDateTime(QDate(2013, 12, 14), QTime(12, 12)), QDateTime(QDate(2011, 12, 14), QTime(13, 12)), Task::Status::UNCOMPLETED);

  unsigned long insertId = repository.Insert(entity);
  ASSERT_TRUE(insertId != 0);

  TaskRepository::EntitySharedPtr foundEntity = repository.FindOneById(insertId);
  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetTitle() == entity.GetTitle());

  repository.Update(insertId, updatedEntity);

  foundEntity = repository.FindOneById(updatedEntity.GetId());
  ASSERT_TRUE(foundEntity != nullptr);
  ASSERT_TRUE(foundEntity->GetTitle() == updatedEntity.GetTitle());
}

TEST_F(TestModelRepositoryTaskRepository, TaskRepositoryDeleteOneEntity)
{
  TaskRepository repository(m_db);
  Task entity(0, 1, "task1", Task::Priority::NORMAL, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), QDateTime(QDate(2015, 12, 14), QTime(13, 12)), Task::Status::COMPLETED);

  unsigned long insertId = repository.Insert(entity);
  ASSERT_TRUE(insertId != 0);

  TaskRepository::EntitySharedPtr foundEntity = repository.FindOneById(insertId);
  ASSERT_TRUE(foundEntity != nullptr);

  unsigned long deletedCount = repository.Delete(insertId);
  ASSERT_TRUE(deletedCount == 1);

  foundEntity = repository.FindOneById(insertId);
  EXPECT_TRUE(foundEntity == nullptr);
}
