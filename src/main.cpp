#include "ScreenResolutionManager.h"
#include "Engine.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Q_INIT_RESOURCE(qml);

	QQmlApplicationEngine qmlEngine;
	qmlRegisterType<ScreenResolutionManager>("TodosEngine", 1, 0, "ScreenResolutionManager");
	qmlRegisterType<TaskObject>("TodosEngine", 1, 0, "Task");
	qmlRegisterType<CategotyObject>("TodosEngine", 1, 0, "Category");
	qmlRegisterType<QObjectListModel>("TodosEngine", 1, 0, "QObjectListModel");

	Engine *coreEngine = new Engine();
	qmlEngine.rootContext()->setContextProperty("coreEngine", coreEngine);
	qmlEngine.load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));

	return app.exec();

}



