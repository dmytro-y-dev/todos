#include "ScreenResolutionManager.h"

#include <QSize>
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

namespace
{
	const QSize cMobileResolution = QSize(480, 800); // For emulation on desktop
}

ScreenResolutionManager::ScreenResolutionManager(QObject *parent) : QObject(parent)
{

#ifdef Q_OS_WIN
	m_height = cMobileResolution.height();
	m_width  = cMobileResolution.width();
#else
	auto screen = QApplication::desktop()->screenGeometry();
	m_height = screen.height();
	m_width  = screen.width();
#endif

}

int ScreenResolutionManager::height() const
{
	return m_height;
}

void ScreenResolutionManager::setHeight(int height)
{
	if (m_height == height)
		return;

	m_height = height;
	emit heightChanged(m_height);
}

int ScreenResolutionManager::width() const
{
	return m_width;
}

void ScreenResolutionManager::setWidth(int width)
{
	if (m_width == width)
		return;

	m_width = width;
	emit widthChanged(m_width);
}

