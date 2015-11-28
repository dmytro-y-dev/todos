#include "ScreenResolutionManager.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	qmlRegisterType<ScreenResolutionManager>("com.screenmanager", 1, 0, "ScreenResolutionManager");

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

	return app.exec();

}



