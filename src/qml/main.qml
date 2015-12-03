import QtQuick 2.3
import QtQuick.Controls 1.2

import com.screenmanager 1.0

ApplicationWindow {
    id: applicationWindow
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
        header: Component { TaskHeader{
                id : taskHeader
                width: applicationWindow.width
                height: applicationWindow.height / 6
            } }
        model: TestTaskModel{ id: textTaskModel }
        delegate: Component { TaskDelegate {
                id : taskDelegate
                width: applicationWindow.width
                showContantHeight: applicationWindow.height / 2.3
                hideContantHeight: applicationWindow.height / 8
            } }
    }

    Sidebar {
        id: sidebarRectangle
        maxWidth:  applicationWindow.width
        height: applicationWindow.height
        z:1
    }

    AddButton {
        id: addButton

        diameter: screenManager.width / 4.8

        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 20;
        anchors.right: parent.right;
        anchors.rightMargin: 20

        MouseArea {
            anchors.fill: parent
            onClicked: {
                textTaskModel.append({title: "NewTask" + textTaskModel.count, priority: 1, dueDate: "28-11-2015", commentaty: "My best task!!!" , status: "Not Completed"})
            }
        }
    }
}
