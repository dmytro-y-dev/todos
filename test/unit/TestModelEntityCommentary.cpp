#include <gtest/gtest.h>

#include <cstring>

#include <model/entity/Commentary.h>

using std::strcpy;
using std::strcmp;
using std::make_shared;
using todos_model_entity::Commentary;

class TestModelEntityCommentary: public ::testing::Test
{
public:
  TestModelEntityCommentary()
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

TEST_F(TestModelEntityCommentary, CommentaryGettersSetters)
{
  unsigned int id = 1;
  Commentary::Type type = Commentary::Type::TEXT;
  Commentary::DateTime publishedOn = QDateTime(QDate(2015, 12, 31), QTime(23, 59));

  char* firstContentPtr = new char[100];
  strncpy(firstContentPtr, "first", 6);
  Commentary::ContentPtr content = std::shared_ptr<char>(firstContentPtr);

  Commentary commentary(id, type, publishedOn, content);

  ASSERT_TRUE(commentary.GetId() == id);
  ASSERT_TRUE(commentary.GetType() == type);
  ASSERT_TRUE(commentary.GetPublishedOn() == publishedOn);
  ASSERT_TRUE(strcmp(commentary.GetContent().get(), firstContentPtr) == 0);

  unsigned int newId = 2;
  commentary.SetId(newId);
  EXPECT_TRUE(commentary.GetId() == newId);

  Commentary::Type newType = Commentary::Type::TEXT;
  commentary.SetType(newType);
  EXPECT_TRUE(commentary.GetType() == newType);

  Commentary::DateTime newPublishedOn = QDateTime(QDate(2015, 12, 13), QTime(3, 59));
  commentary.SetPublishedOn(newPublishedOn);
  EXPECT_TRUE(commentary.GetPublishedOn() == newPublishedOn);

  char* secondContentPtr = new char[100];
  strncpy(secondContentPtr, "second", 7);
  Commentary::ContentPtr newContent = std::shared_ptr<char>(secondContentPtr);

  commentary.SetContent(newContent);
  EXPECT_TRUE(strcmp(commentary.GetContent().get(), secondContentPtr) == 0);
}
