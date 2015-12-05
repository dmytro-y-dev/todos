#ifndef TODOS_MODEL_SCHEMA_SCHEMA_H
#define TODOS_MODEL_SCHEMA_SCHEMA_H

#include <sqlite3.h>

namespace todos_model_schema {
  class Schema
  {
  private:
    sqlite3* m_db;

  public:
    Schema(const char* filename);
    ~Schema();

    sqlite3* GetDatabaseHandle() const;

    bool IsOpened() const;

    void Open(const char* filename);
    void Close();

    void CreateTables();
    void DestroyTables();

  private:
    Schema(const Schema&) = delete;
    Schema& operator=(const Schema&) = delete;
  };
}

#endif //TODOS_MODEL_SCHEMA_SCHEMA_H
