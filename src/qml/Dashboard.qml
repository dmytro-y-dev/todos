import QtQuick 2.0

import "constants.js" as Consts

Item {
    id: dashboard
    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    ListView {
        width: parent.width
        height: parent.height

        header: Component {
            DashboardHeader {
                id : dashboardHeader
                width: dashboard.width
                height: dashboard.height / 6
            }
        }

        model: TestTaskModel { id: textTaskModel }

        delegate: Component {
            TaskDelegate {
                id : taskDelegate
                width: dashboard.width
                showContantHeight: dashboard.height / 2.3
                hideContantHeight: dashboard.height / 8
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

        MouseArea {
            anchors.fill: parent
            onClicked: {
                textTaskModel.append({title: "NewTask" + textTaskModel.count, priority: 1, dueDate: "28-11-2015", commentaty: "My best task!!!" , status: "Not Completed"})
            }
        }
    }
}

