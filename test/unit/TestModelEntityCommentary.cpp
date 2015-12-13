#include <gtest/gtest.h>

#include <string>

#include <model/entity/commentary/Commentary.h>

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
  Commentary::Content content("first");
  Commentary commentary(id, type, publishedOn, content);

  ASSERT_TRUE(commentary.GetId() == id);
  ASSERT_TRUE(commentary.GetType() == type);
  ASSERT_TRUE(commentary.GetPublishedOn() == publishedOn);
  ASSERT_TRUE(commentary.GetContent() == content);

  unsigned int newId = 2;
  commentary.SetId(newId);
  EXPECT_TRUE(commentary.GetId() == newId);

  Commentary::Type newType = Commentary::Type::TEXT;
  commentary.SetType(newType);
  EXPECT_TRUE(commentary.GetType() == newType);

  Commentary::DateTime newPublishedOn = QDateTime(QDate(2015, 12, 13), QTime(3, 59));
  commentary.SetPublishedOn(newPublishedOn);
  EXPECT_TRUE(commentary.GetPublishedOn() == newPublishedOn);

  Commentary::Content newContent("second");
  commentary.SetContent(newContent);
  EXPECT_TRUE(commentary.GetContent() == newContent);
}
