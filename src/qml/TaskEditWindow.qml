import QtQuick 2.0

import "constants.js" as Consts
import "components"

Rectangle {
    id: taskEditWindow

    property alias taskName: name.text
    property alias taskPriority: priority.text
    property alias taskRemainderDate: remainderDate.text
    property alias taskDueDate: dueDate.text

    signal taskEdited(string name, int priority, string reainderDate, string dueDate)

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    color: Consts.MainColor

    Text {
        anchors.top: taskEditWindow.top
        anchors.topMargin: taskEditWindow.height / 8
        anchors.horizontalCenter: taskEditWindow.horizontalCenter

        text: qsTr("Task Edit")
        color: "#ffffff"
        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        font.pixelSize: taskEditWindow.height / 10
    }

    Grid {
        anchors.horizontalCenter: parent.horizontalCenter
        y: taskEditWindow.height / 2.42

        columns: 2

        spacing: taskEditWindow.height / 80

        property int lineEditWidth:  taskEditWindow.width / 2
        property int lineEditHeight: taskEditWindow.height / 13
        property int labelFontSize:  taskEditWindow.height / 30

        Text {
            text: qsTr("Name")
            color: "white"
            font.pixelSize: parent.labelFontSize
        }

        CustomLineEdit {
            id: name

            width: parent.lineEditWidth
            height: parent.lineEditHeight
        }

        Text {
            text: qsTr("Priority")
            color: "white"
            font.pixelSize: parent.labelFontSize
        }

        CustomLineEdit {
            id: priority

            width: parent.lineEditWidth
            height: parent.lineEditHeight
        }

        Text {
            text: qsTr("Reminder date")
            color: "white"
            font.pixelSize: parent.labelFontSize
        }

        CustomLineEdit {
            id: remainderDate

            width: parent.lineEditWidth
            height: parent.lineEditHeight
        }

        Text {
            text: qsTr("Due date")
            color: "white"
            font.pixelSize: parent.labelFontSize
        }

        CustomLineEdit {
            id: dueDate

            width: parent.lineEditWidth
            height: parent.lineEditHeight
        }
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: taskEditWindow.height / 40
        anchors.right: parent.right
        anchors.rightMargin: taskEditWindow.width / 24

        spacing: taskEditWindow.width / 48

        TileButton {
            width: taskEditWindow.width / 3
            height: taskEditWindow.height / 10

            text: qsTr("Cancel")

            onClicked: { taskEditWindow.visible = false }
        }

        TileButton {
            width: taskEditWindow.width / 3
            height: taskEditWindow.height / 10

            text: qsTr("OK")

            onClicked: {
                taskEditWindow.visible = false
                taskEdited(taskName, taskPriority, taskRemainderDate, taskDueDate)
            }
        }

    }
}

