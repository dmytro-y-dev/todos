#include <gtest/gtest.h>

#include <model/repository/Category/CategoryRepository.h>

using todos_model_entity::Category;
using todos_model_repository::CategoryRepository;
using todos_model_schema::Schema;

class TestModelRepositoryCategoryRepository: public ::testing::Test
{
protected:
  Schema m_db;

public:
  TestModelRepositoryCategoryRepository() : m_db(nullptr)
  {
  }

protected:
  virtual void SetUp()
  {
    remove("test-db-Category.sqlite3");
    m_db.Open("test-db-Category.sqlite3");
    m_db.CreateTables();
  }

  virtual void TearDown()
  {
    m_db.Close();
    remove("test-db-Category.sqlite3");
  }
};

TEST_F(TestModelRepositoryCategoryRepository, CategoryRepositoryInsertOneEntity)
{
  CategoryRepository repository(m_db);

  Category entity(0, 1, "test");
  unsigned long insertId = repository.Insert(entity);

  ASSERT_TRUE(insertId != 0);

  auto foundEntity = repository.FindOneById(insertId);

  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetName() == entity.GetName());
}

TEST_F(TestModelRepositoryCategoryRepository, CategoryRepositoryUpdateOneEntity)
{
  CategoryRepository repository(m_db);
  Category entity(0, 1, "test");
  Category updatedEntity(0, 1, "updatedlogin");

  unsigned long insertId = repository.Insert(entity);
  ASSERT_TRUE(insertId != 0);

  CategoryRepository::EntitySharedPtr foundEntity = repository.FindOneById(insertId);
  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetName() == entity.GetName());

  repository.Update(insertId, updatedEntity);

  foundEntity = repository.FindOneById(updatedEntity.GetId());
  ASSERT_TRUE(foundEntity != nullptr);
  ASSERT_TRUE(foundEntity->GetName() == updatedEntity.GetName());
}

TEST_F(TestModelRepositoryCategoryRepository, CategoryRepositoryDeleteOneEntity)
{
  CategoryRepository repository(m_db);
  Category entity(0, 1, "test");

  unsigned long insertId = repository.Insert(entity);
  ASSERT_TRUE(insertId != 0);

  CategoryRepository::EntitySharedPtr foundEntity = repository.FindOneById(insertId);
  ASSERT_TRUE(foundEntity != nullptr);

  unsigned long deletedCount = repository.Delete(insertId);
  ASSERT_TRUE(deletedCount == 1);

  foundEntity = repository.FindOneById(insertId);
  EXPECT_TRUE(foundEntity == nullptr);
}

TEST_F(TestModelRepositoryCategoryRepository, CategoryRepositoryFindAll)
{
  CategoryRepository repository(m_db);

  Category entity1(0, 1, "test2");
  Category entity2(0, 1, "test1");
  Category entity3(0, 1, "test3");

  repository.Insert(entity1);
  repository.Insert(entity2);
  repository.Insert(entity3);

  std::vector<std::shared_ptr<Category> > foundEntities = repository.FindAll(1);

  EXPECT_TRUE(foundEntities.size() == 3);
}
