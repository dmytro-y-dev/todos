import QtQuick 2.0

import TodosEngine 1.0

import "constants.js" as Consts
import "components"

Item {
    id: dashboard

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    property alias model: dashboardView.model
    property int selectedTaskIndex: -1
    property string headerText: coreEngine.dashboardHeaderText

    signal clearSelection()

    property bool sortByIncrease: true
    onSortByIncreaseChanged: {

    }

    state: "Default"

    states: [
        State {
            name: "Default"
            PropertyChanges { target: addButton; visible: true }
            PropertyChanges { target: taskContext; visible: false }
        },
        State {
            name: "Context"
            PropertyChanges { target: addButton; visible: false }
            PropertyChanges { target: taskContext; visible: true }
        }
    ]

    ListView {
        id: dashboardView

        anchors.fill: parent

        header: Rectangle {
            width: dashboardView.width
            height: dashboardView.height / 6

            color: Consts.MainColorDark

            Rectangle {
                id: rectangle1
                width: dashboard.width / 10
                height: width
                color: "#00000000"
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    width: dashboard.width / 25
                    height: width

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter

                    source: "qrc:/icons/resources/icons/align_just_icon.png"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: { sidebar.state = "Show" }
                }
            }

            Rectangle {
                width: parent.width / 15
                height: width
                color: "#00000000"
                anchors.right: parent.right
                anchors.rightMargin: 40
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    id: sortIcon
                    anchors.fill: parent
                    source: "qrc:/icons/resources/icons/indent_increase_icon.png"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        sortByIncrease = !sortByIncrease
                        sortIcon.source = sortByIncrease ? "qrc:/icons/resources/icons/indent_increase_icon.png" : "qrc:/icons/resources/icons/indent_decrease_icon.png"
                        coreEngine.changeSortOrder();
                    }
                }
            }

            Text {
                id: dashboardHeaderText
                color: "#f1eeee"
                text: dashboard.headerText
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.leftMargin: 100
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
                font.family: "Arial"
                font.pixelSize: 39
            }

        }

        delegate: Component {
            TaskDelegate {
                id : taskDelegate
                width: dashboard.width
                showContantHeight: dashboard.height / 2.3
                hideContantHeight: dashboard.height / 8

                onTaskClicked: {
                    dashboard.clearSelection()
                    if(dashboard.state != "Default")
                        dashboard.state = "Default"

                }

                onTaskPressedAndHold: {
                    dashboard.clearSelection()
                    selectedTaskIndex = index
                    dashboard.state = "Context"

                }
            }
        }
    }

    AddButton {
        id: addButton
        diameter: dashboard.width / 4.8

        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 20;
        anchors.right: parent.right;
        anchors.rightMargin: 20

        onClicked: {
            taskEditWindow.action = "create"
            taskEditWindow.taskName = "New task"
            taskEditWindow.taskPriority = "High"
            taskEditWindow.taskDueDate = new Date()
            taskEditWindow.taskRemainderDate = new Date()
            taskEditWindow.visible = true
        }
    }

    ContextMenu {
        id: taskContext

        width: dashboard.width
        height: dashboard.height / 8

        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 20;

        onCompleteTaskClicked: {
            coreEngine.doneTask(selectedTaskIndex)
            selectedTaskIndex = -1
            dashboard.state = "Default"
        }

        onEditTaskClicked: {
            dashboard.state = "Default"
            taskEditWindow.action = "edit"
            taskEditWindow.taskName = coreEngine.getTaskTitleByIndex(selectedTaskIndex)
            taskEditWindow.taskPriority = coreEngine.getTaskPriorityByIndex(selectedTaskIndex)
            taskEditWindow.taskDueDate = coreEngine.getTaskDueDateByIndex(selectedTaskIndex)
            taskEditWindow.taskRemainderDate = coreEngine.getTaskReminderDateByIndex(selectedTaskIndex)
            taskEditWindow.visible = true
        }

        onDeleteTaskClicked: {
            coreEngine.deleteTask(selectedTaskIndex)
            selectedTaskIndex = -1
            dashboard.state = "Default"
        }
    }

}

