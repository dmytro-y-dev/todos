import QtQuick 2.0

import "constants.js" as Consts
import "components"

Rectangle {
    id: priorityListView

    color: Consts.MainColor

    ListView {
        id: view

        anchors.fill : parent

        header: TextRectangleItem{
            width: priorityListView.width
            height: priorityListView.height / 7
            color: Consts.MainColorDark
            text: "Priority"
        }

        model: ListModel {
            id: priorityModel

            ListElement { name: "High" }
            ListElement { name: "Normal" }
            ListElement { name: "Low"    }
        }

        delegate: Component {
            TextRectangleItem {
                id: delegate
                width: priorityListView.width
                height: priorityListView.height / 8
                text: name
                borderEnable: false

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        taskEditWindow.taskPriority = name
                        priorityListView.visible = false
                    }
                }
            }
        }
    }
}
