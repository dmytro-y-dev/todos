#include <gtest/gtest.h>

#include <string>

#include <model/entity/category/Category.h>

using std::string;
using todos_model_entity::Category;

class TestModelEntityCategory : public ::testing::Test
{
public:
  TestModelEntityCategory()
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

TEST_F(TestModelEntityCategory, CategoryGettersSetters)
{
  unsigned int id = 1, userId = 2;
  string name = "my-category";
  Category category(id, userId, name);

  ASSERT_TRUE(category.GetId() == id);
  ASSERT_TRUE(category.GetUserId() == userId);
  ASSERT_TRUE(category.GetName() == name);

  unsigned int newId = 2;
  category.SetId(newId);
  EXPECT_TRUE(category.GetId() == newId);

  unsigned int newUserId = 1;
  category.SetUserId(newUserId);
  EXPECT_TRUE(category.GetUserId() == newUserId);

  string newName = "my-category-new-name";
  category.SetName(newName);
  EXPECT_TRUE(category.GetName() == newName);
}
