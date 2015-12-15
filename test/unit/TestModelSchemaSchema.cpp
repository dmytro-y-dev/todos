#include <gtest/gtest.h>

#include <set>
#include <string>
#include <cstdio>

#include <model/schema/Schema.h>

using std::remove;
using std::set;
using std::string;
using todos_model_schema::Schema;

class TestModelSchemaSchema : public ::testing::Test
{
protected:
  Schema m_db;

public:
  TestModelSchemaSchema() : m_db(nullptr)
  {
  }

protected:
  virtual void SetUp()
  {
    remove("test-db.sqlite3");
    m_db.Open("test-db.sqlite3");
  }

  virtual void TearDown()
  {
    m_db.Close();
    remove("test-db.sqlite3");
  }
};

static int checkIfSchemaIsCreated(void *ptrTablesNames, int argc, char **argv, char **azColName)
{
  set<string>& tablesNames = *(static_cast<set<string>*>(ptrTablesNames));

  for(int i = 0; i < argc; i++){
    if (strcmp(azColName[i], "name")) {
      continue;
    }

    auto nameIterator = tablesNames.find(argv[i]);
    if (nameIterator != tablesNames.end()) {
      tablesNames.erase(nameIterator);
    }
  }

  return 0;
}

TEST_F(TestModelSchemaSchema, SchemaCreation)
{
  const char *queryGetTablesNames = "SELECT name FROM sqlite_master WHERE type='table';";
  set<string> expectedTablesNames({"Category", "User", "Task", "Commentary"});

  m_db.CreateTables();
  sqlite3_exec(m_db.GetDatabaseHandle(), queryGetTablesNames, checkIfSchemaIsCreated, &expectedTablesNames, nullptr);

  EXPECT_TRUE(expectedTablesNames.empty() == true);
}

static int checkIfSchemaIsDestroyed(void *ptrSchemaDestroyed, int argc, char **argv, char **azColName)
{
  bool& schemaDestroyed = *(static_cast<bool*>(ptrSchemaDestroyed));

  if (argc == 0) {
    schemaDestroyed = true;
  } else {
    schemaDestroyed = false;
  }

  return 0;
}

TEST_F(TestModelSchemaSchema, SchemaRemoval)
{
  const char *queryGetTablesNames = "SELECT name FROM sqlite_master WHERE type='table';";
  bool schemaDestroyed;

  m_db.DestroyTables();
  sqlite3_exec(m_db.GetDatabaseHandle(), queryGetTablesNames, checkIfSchemaIsDestroyed, &schemaDestroyed, nullptr);

  EXPECT_TRUE(schemaDestroyed == true);
}

TEST_F(TestModelSchemaSchema, SchemaCopying)
{
  Schema databaseTestCopyingConstructor(m_db);
  Schema databaseTestAssignment("");

  databaseTestAssignment = m_db;

  EXPECT_TRUE(databaseTestCopyingConstructor.GetDatabaseHandle() == m_db.GetDatabaseHandle());
  EXPECT_TRUE(databaseTestAssignment.GetDatabaseHandle() == m_db.GetDatabaseHandle());
}
