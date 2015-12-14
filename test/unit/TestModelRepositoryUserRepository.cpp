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


TEST_F(TestModelRepositoryUserRepository, UserRepositoryInsert)
{
  UserRepository repository(m_db);

  std::shared_ptr<User> entity(new User(0, "test", "pass", QDateTime(QDate(2015, 12, 14), QTime(12, 12))));
  unsigned long insertId = repository.Insert(entity);

  ASSERT_TRUE(insertId != 0);

  auto foundEntity = repository.FindOneById(insertId);

  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetLogin() == entity->GetLogin());
}
