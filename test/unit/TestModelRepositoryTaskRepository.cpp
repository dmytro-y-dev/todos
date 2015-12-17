#include <gtest/gtest.h>

#include <model/repository/Task/TaskRepository.h>
#include <model/repository/Category/CategoryRepository.h>

using todos_model_entity::Category;
using todos_model_entity::Task;
using todos_model_repository::TaskRepository;
using todos_model_repository::CategoryRepository;
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

  Task entity(0, 2, "task1", Task::Priority::NORMAL, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), QDateTime(QDate(2015, 12, 14), QTime(13, 12)), Task::Status::COMPLETED);
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

TEST_F(TestModelRepositoryTaskRepository, TaskRepositoryFindAll)
{
  CategoryRepository categoryRepository(m_db);
  Category category1(0, 1, "category1");
  Category category2(0, 1, "category2");

  categoryRepository.Insert(category1);
  categoryRepository.Insert(category2);

  TaskRepository repository(m_db);
  Task entity1(0, 1, "task1", Task::Priority::NORMAL, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), QDateTime(QDate(2015, 12, 14), QTime(13, 12)), Task::Status::COMPLETED);
  Task entity2(0, 1, "task3", Task::Priority::LOW, QDateTime(QDate(2013, 12, 14), QTime(12, 12)), QDateTime(QDate(2011, 12, 14), QTime(13, 12)), Task::Status::UNCOMPLETED);
  Task entity3(0, 1, "task2", Task::Priority::LOW, QDateTime(QDate(2013, 12, 14), QTime(12, 12)), QDateTime(QDate(2011, 12, 14), QTime(13, 12)), Task::Status::UNCOMPLETED);
  Task entity4(0, 2, "task4", Task::Priority::LOW, QDateTime(QDate(2016, 12, 14), QTime(12, 12)), QDateTime(QDate(2017, 12, 14), QTime(13, 12)), Task::Status::UNCOMPLETED);

  repository.Insert(entity1);
  repository.Insert(entity2);
  repository.Insert(entity3);
  repository.Insert(entity4);

  TaskRepository::TaskSortSettings sortSettings1(TaskRepository::TaskSortSettings::Field::TITLE, TaskRepository::TaskSortSettings::Order::ASC);
  TaskRepository::TaskSortSettings sortSettings1Desc(TaskRepository::TaskSortSettings::Field::TITLE, TaskRepository::TaskSortSettings::Order::DESC);
  TaskRepository::TaskSortSettings sortSettings2(TaskRepository::TaskSortSettings::Field::NONE, TaskRepository::TaskSortSettings::Order::NONE);

  TaskRepository::TaskFilterSettings filters1;
  filters1.EnableFilterByDueDate();
  filters1.SetDueDateLowerLimit(QDateTime(QDate(2012, 12, 14), QTime(12, 12)));
  filters1.SetDueDateUpperLimit(QDateTime(QDate(2014, 12, 14), QTime(12, 12)));

  std::vector<std::shared_ptr<Task> > foundEntities1 = repository.FindAll(1, sortSettings1, filters1);

  ASSERT_TRUE(foundEntities1.size() == 2);
  EXPECT_TRUE(foundEntities1[0]->GetTitle() == "task2");
  EXPECT_TRUE(foundEntities1[1]->GetTitle() == "task3");

  std::vector<std::shared_ptr<Task> > foundEntities2 = repository.FindAll(1, sortSettings1Desc, filters1);

  ASSERT_TRUE(foundEntities2.size() == 2);
  EXPECT_TRUE(foundEntities2[0]->GetTitle() == "task3");
  EXPECT_TRUE(foundEntities2[1]->GetTitle() == "task2");

  TaskRepository::TaskFilterSettings filters2;
  filters2.EnableFilterByCategory();
  filters2.SetCategory("category1");

  std::vector<std::shared_ptr<Task> > foundEntities3 = repository.FindAll(1, sortSettings1, filters2);

  EXPECT_TRUE(foundEntities3.size() == 3);

  TaskRepository::TaskFilterSettings filters3;
  filters3.EnableFilterByCategory();
  filters3.SetCategory("category1");
  filters3.EnableFilterByDueDate();
  filters3.SetDueDateLowerLimit(QDateTime(QDate(2012, 12, 14), QTime(12, 12)));
  filters3.SetDueDateUpperLimit(QDateTime(QDate(2014, 12, 14), QTime(12, 12)));

  std::vector<std::shared_ptr<Task> > foundEntities4 = repository.FindAll(1, sortSettings2, filters3);

  EXPECT_TRUE(foundEntities4.size() == 2);
}

TEST_F(TestModelRepositoryTaskRepository, TaskRepositoryFindAllByCategoryId)
{
  TaskRepository repository(m_db);
  Task entity1(0, 1, "task1", Task::Priority::NORMAL, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), QDateTime(QDate(2015, 12, 14), QTime(13, 12)), Task::Status::COMPLETED);
  Task entity2(0, 1, "task3", Task::Priority::LOW, QDateTime(QDate(2013, 12, 14), QTime(12, 12)), QDateTime(QDate(2011, 12, 14), QTime(13, 12)), Task::Status::UNCOMPLETED);
  Task entity3(0, 1, "task2", Task::Priority::LOW, QDateTime(QDate(2013, 12, 14), QTime(12, 12)), QDateTime(QDate(2011, 12, 14), QTime(13, 12)), Task::Status::UNCOMPLETED);

  repository.Insert(entity1);
  repository.Insert(entity2);
  repository.Insert(entity3);

  std::vector<std::shared_ptr<Task> >&& foundEntities = repository.FindAllByCategoryId(1);

  EXPECT_TRUE(foundEntities.size() == 3);
}
