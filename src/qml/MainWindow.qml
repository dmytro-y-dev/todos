import QtQuick 2.0

import "constants.js" as Consts

Item {
    id: mainWindow
    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    ListView {
        id: dashboard
        width: parent.width
        height: parent.height

        header: Component {
            TaskHeader {
                id : taskHeader
                width: mainWindow.width
                height: mainWindow.height / 6
            }
        }

        model: TestTaskModel { id: textTaskModel }

        delegate: Component {
            TaskDelegate {
                id : taskDelegate
                width: mainWindow.width
                showContantHeight: mainWindow.height / 2.3
                hideContantHeight: mainWindow.height / 8
            }
        }
    }

    Sidebar {
        id: sidebarRectangle
        maxWidth: mainWindow.width
        height: mainWindow.height
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

