import QtQuick 2.0

Rectangle {
    id: contextMenu

    signal completeTask()
    signal editTask()
    signal deleteTask()

    width: 480
    height: 40

    Row {
        anchors.fill: parent

        MouseArea {
            height: contextMenu.height
            width: contextMenu.width / 3
            Image {
                anchors.centerIn: parent
                source: "qrc:/icons/resources/icons/checkmark_icon.png"
            }
            onClicked: { completeTask() }
        }

        MouseArea {
            height: contextMenu.height
            width: contextMenu.width / 3
            Image {
                anchors.centerIn: parent
                source: "qrc:/icons/resources/icons/pencil_icon.png"
            }
            onClicked: { editTask() }
        }

        MouseArea {
            height: contextMenu.height
            width: contextMenu.width / 3
            Image {
                anchors.centerIn: parent
                source: "qrc:/icons/resources/icons/delete_icon.png"
            }
            onClicked: { deleteTask() }
        }
    }
}

