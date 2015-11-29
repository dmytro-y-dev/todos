import QtQuick 2.3
import QtQuick.Controls 1.2

import com.screenmanager 1.0

ApplicationWindow {
    id: applicationWindow1
    visible: true
    ScreenResolutionManager{id: screenManager}

    // For designer (480 x 800)
    // Replace all screenManager vaules
/*
    width: 480
    height: 800
*/

    width: screenManager.width
    height: screenManager.height

    ListView {
        id: mainDashboard
        width: parent.width
        height: parent.height
        model: TestTaskModel{}
        delegate: Component { TaskDelegate {} }
    }

    AddButton {
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 20;
        anchors.right: parent.right;
        anchors.rightMargin: 20
    }
}
