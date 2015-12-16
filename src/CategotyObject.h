#ifndef CATEGOTYOBJECT_H
#define CATEGOTYOBJECT_H

#include <QObject>

#include <../model/entity/category/Category.h>

using todos_model_entity::Category;

class CategotyObject : public QObject
{
	Q_OBJECT
	Q_PROPERTY(unsigned long id     READ id     WRITE setId     NOTIFY idChanged)
	Q_PROPERTY(unsigned long userId READ userId WRITE setUserId NOTIFY userIdChanged)
	Q_PROPERTY(QString name         READ name   WRITE setName   NOTIFY nameChanged)

public:
	Q_INVOKABLE CategotyObject(unsigned long id, unsigned long userId, const QString &name, QObject * parent = 0);
	Q_INVOKABLE CategotyObject(Category category, QObject * parent = 0);
	Q_INVOKABLE CategotyObject(QObject * parent = 0);

	unsigned long id() const;
	void setId(unsigned long id);

	unsigned long userId() const;
	void setUserId(unsigned long userId);

	QString name() const;
	void setName(const QString &name);

signals:
	void idChanged();
	void userIdChanged();
	void nameChanged();

private:
	unsigned long m_id;
	unsigned long m_userId;
	QString m_name;
};

#endif // CATEGOTYOBJECT_H

