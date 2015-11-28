#ifndef SCREENRESOLUTIONMANAGER_H
#define SCREENRESOLUTIONMANAGER_H

#include <QObject>

class ScreenResolutionManager : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
	Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
public:
	explicit ScreenResolutionManager(QObject *parent = 0);

	int height() const;
	void setHeight(int height);

	int width() const;
	void setWidth(int width);

	int getTaskTitleHeight() const;
signals:
	void heightChanged(int);
	void widthChanged(int);

private:
	int m_height;
	int m_width;
};

#endif // SCREENRESOLUTIONMANAGER_H
