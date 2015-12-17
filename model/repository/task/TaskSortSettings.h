#ifndef TODOS_MODEL_REPOSITORY_TASKSORTSETTINGS_H
#define TODOS_MODEL_REPOSITORY_TASKSORTSETTINGS_H

namespace todos_model_repository {
  class TaskSortSettings
  {
  public:
    enum class Field
    {
      NONE = 0,

      DUE_DATE = 1,
      PRIORITY = 2,
      TITLE = 3
    };

    enum class Order
    {
      NONE = 0,

      ASC = 1,
      DESC = 2
    };

  private:
    Field m_field;
    Order m_order;

  public:
    TaskSortSettings(Field field, Order order);

    Order GetOrder() const;
    Field GetField() const;

    void SetOrder(Order order);
    void SetField(Field field);
  };
}

#endif //TODOS_MODEL_REPOSITORY_TASKSORTSETTINGS_H
