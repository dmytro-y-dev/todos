import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "constants.js" as Consts
import "components"

Rectangle {
    id: calendarView

    property alias date: calendar.selectedDate

    property string editor: "none"

    signal okButtonClicked(var date)
    signal cancelButtonClicked();

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    color: Consts.MainColor

    Text {
        anchors.top: parent.top
        anchors.topMargin: parent.height / 10
        anchors.horizontalCenter: parent.horizontalCenter

        text: qsTr("Select date")
        color: "#ffffff"
        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        font.pixelSize: parent.height / 10
    }

    Calendar {
        id: calendar

        anchors.left: parent.left
        anchors.right: parent.right

        height: parent.height / 2
        anchors.verticalCenter: parent.verticalCenter

    }

    Row {
        anchors.top: parent.top
        anchors.topMargin: parent.height / 1.16
        anchors.horizontalCenter: parent.horizontalCenter

        spacing: parent.width / 48

        TileButton {
            width: calendarView.width / 3
            height: calendarView.height / 10

            text: qsTr("Cancel")

            onClicked: {
                calendarView.visible = false
                cancelButtonClicked()
            }
        }

        TileButton {
            width: calendarView.width / 3
            height: calendarView.height / 10

            text: qsTr("Ok")

            onClicked: {
                calendarView.visible = false
                okButtonClicked(date)
                if (editor == "taskEditDueDate") {
                    taskEditWindow.taskDueDate = calendar.selectedDate
                } else if (editor == "taskEditReminderDate") {
                    taskEditWindow.taskRemainderDate = calendar.selectedDate
                } else if (editor == "filterUpperLimit") {
                    sidebar.upperDueDateFilter = calendar.selectedDate
                } else if (editor == "filterLowerLimit") {
                    sidebar.lowerDueDateFilter = calendar.selectedDate
                }
            }
        }
    }
}

