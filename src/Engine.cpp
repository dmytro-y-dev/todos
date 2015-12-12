#include "Engine.h"

Engine::Engine(QObject *parent)
	: QObject(parent)
{
	auto testData = QList<Task *>()
			<< new Task("Title", 1, "10-10-2015", "Commentary", "Done")
			<< new Task("Title2", 1, "10-10-2015", "Commentary", "Done")
			<< new Task("Title3", 1, "10-10-2015", "Commentary", "Done")
			<< new Task("Title4", 1, "10-10-2015", "Commentary", "Done");
	m_taskList.append(testData);
}

