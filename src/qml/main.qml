import QtQuick 2.3
import QtQuick.Controls 1.2

import com.screenmanager 1.0

ApplicationWindow {
    visible: true
    ScreenResolutionManager{id: screenManager}

    width: screenManager.width
    height: screenManager.height

    ListView {
        id: mainDashboard
        width: parent.width
        height: parent.height
        model: TestTaskModel{}
        delegate: Component { TaskDelegate {} }
    }
}
