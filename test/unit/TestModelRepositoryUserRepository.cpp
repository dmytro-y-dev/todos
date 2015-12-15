#include <gtest/gtest.h>

#include <model/repository/user/UserRepository.h>

using todos_model_entity::User;
using todos_model_repository::UserRepository;
using todos_model_schema::Schema;

class TestModelRepositoryUserRepository : public ::testing::Test
{
protected:
  Schema m_db;

public:
  TestModelRepositoryUserRepository() : m_db(nullptr)
  {
  }

protected:
  virtual void SetUp()
  {
    remove("test-db-user.sqlite3");
    m_db.Open("test-db-user.sqlite3");
    m_db.CreateTables();
  }

  virtual void TearDown()
  {
    m_db.Close();
    remove("test-db-user.sqlite3");
  }
};

TEST_F(TestModelRepositoryUserRepository, UserRepositoryInsertOneEntity)
{
  UserRepository repository(m_db);

  User entity(0, "test", "pass", QDateTime(QDate(2015, 12, 14), QTime(12, 12)));
  unsigned long insertId = repository.Insert(entity);

  ASSERT_TRUE(insertId != 0);

  auto foundEntity = repository.FindOneById(insertId);

  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetLogin() == entity.GetLogin());
}

TEST_F(TestModelRepositoryUserRepository, UserRepositoryUpdateOneEntity)
{
  UserRepository repository(m_db);
  User entity(0, "test", "pass", QDateTime(QDate(2015, 12, 14), QTime(12, 12)));
  User updatedEntity(0, "updatedlogin", "passupdated", QDateTime(QDate(2035, 11, 4), QTime(2, 12)));

  unsigned long insertId = repository.Insert(entity);
  ASSERT_TRUE(insertId != 0);

  UserRepository::EntitySharedPtr foundEntity = repository.FindOneById(insertId);
  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetLogin() == entity.GetLogin());

  repository.Update(insertId, updatedEntity);

  foundEntity = repository.FindOneById(insertId);
  ASSERT_TRUE(foundEntity != nullptr);
  ASSERT_TRUE(foundEntity->GetLogin() == updatedEntity.GetLogin());
}

TEST_F(TestModelRepositoryUserRepository, UserRepositoryDeleteOneEntity)
{
  UserRepository repository(m_db);
  User entity(0, "test", "pass", QDateTime(QDate(2015, 12, 14), QTime(12, 12)));

  unsigned long insertId = repository.Insert(entity);
  ASSERT_TRUE(insertId != 0);

  unsigned long deletedCount = repository.Delete(insertId);
  ASSERT_TRUE(deletedCount == 1);
}
