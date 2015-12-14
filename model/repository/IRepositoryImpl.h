#ifndef TODOS_MODEL_REPOSITORY_IREPOSITORYIMPL_H
#define TODOS_MODEL_REPOSITORY_IREPOSITORYIMPL_H

#include <model/schema/Schema.h>

namespace todos_model_repository {

  template <class IEntityDerivative>
  IRepository<IEntityDerivative>::IRepository(const Schema& schema) : m_repository(schema)
  {
  }

  template <class IEntityDerivative>
  typename IRepository<IEntityDerivative>::IdContainer IRepository<IEntityDerivative>::Insert(const IRepository<IEntityDerivative>::EntityWeakPtrContainer& entities)
  {
    IRepository<IEntityDerivative>::IdContainer ids;

    // TODO: Implement

    return ids;
  }

  template <class IEntityDerivative>
  size_t IRepository<IEntityDerivative>::Update(const IRepository<IEntityDerivative>::EntityWeakPtrContainer& entities)
  {
    // TODO: Implement

    return 0;
  }

  template <class IEntityDerivative>
  size_t IRepository<IEntityDerivative>::Delete(const IRepository<IEntityDerivative>::IdContainer& ids)
  {
    // TODO: Implement

    return 0;
  }

  template <class IEntityDerivative>
  typename IRepository<IEntityDerivative>::Id IRepository<IEntityDerivative>::Insert(IRepository<IEntityDerivative>::EntitySharedPtr entity)
  {
    return m_repository.Insert(entity);
  }

  template <class IEntityDerivative>
  size_t IRepository<IEntityDerivative>::Update(IRepository::EntitySharedPtr entity)
  {
    // TODO: Implement

    return 0;
  }

  template <class IEntityDerivative>
  size_t IRepository<IEntityDerivative>::Delete(IRepository<IEntityDerivative>::Id id)
  {
    // TODO: Implement

    return 0;
  }

  template <class IEntityDerivative>
  typename IRepository<IEntityDerivative>::EntitySharedPtrContainer IRepository<IEntityDerivative>::FindAll()
  {
    IRepository<IEntityDerivative>::EntitySharedPtrContainer entities;

    // TODO: Implement

    return entities;
  }

  template <class IEntityDerivative>
  typename IRepository<IEntityDerivative>::EntitySharedPtr IRepository<IEntityDerivative>::FindOneById(IRepository<IEntityDerivative>::Id id)
  {
    return m_repository.FindOneById(id);
  }

  template <class IEntityDerivative>
  typename IRepository<IEntityDerivative>::Schema IRepository<IEntityDerivative>::GetSchema()
  {
    return m_repository.GetSchema();
  }

  template <class IEntityDerivative>
  void IRepository<IEntityDerivative>::SetSchema(const IRepository<IEntityDerivative>::Schema& schema)
  {
    return m_repository.SetSchema(schema);
  }
}

#endif //TODOS_MODEL_REPOSITORY_IREPOSITORYIMPL_H
