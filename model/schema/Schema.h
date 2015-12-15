#ifndef TODOS_MODEL_SCHEMA_SCHEMA_H
#define TODOS_MODEL_SCHEMA_SCHEMA_H

#include <memory>
#include <sqlite3.h>

namespace todos_model_schema {
  class Schema
  {
  public:
    typedef sqlite3* DatabaseHandle;

  private:
    typedef unsigned int CounterValue;
    typedef CounterValue* CounterPtr;

  private:
    DatabaseHandle m_db;
    CounterPtr m_referencesCounter;

  public:
    Schema(const char* filename);
    Schema(const Schema& schema);
    ~Schema();

    DatabaseHandle GetDatabaseHandle() const;

    bool IsOpened() const;

    bool Open(const char* filename);
    void Close();

    void CreateTables();
    void DestroyTables();

    Schema& operator=(const Schema& schema);
  };
}

#endif //TODOS_MODEL_SCHEMA_SCHEMA_H
