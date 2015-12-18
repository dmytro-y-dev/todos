import QtQuick 2.0

import "constants.js" as Consts
import "components"

Rectangle {
    id: sortByListView

    color: Consts.MainColor

    ListView {
        id: view

        signal clearSelection()

        anchors.fill : parent

        header: TextRectangleItem{
            width: categoryListView.width
            height: categoryListView.height / 7
            color: Consts.MainColorDark
            text: "Sort by"
        }

        model: ListModel {
            id: sortModel

            ListElement { name: "Due date" }
            ListElement { name: "Priority" }
            ListElement { name: "Title"    }
        }

        delegate: Component {
            TextRectangleItem {
                id: delegate
                width: categoryListView.width
                height: categoryListView.height / 8
                text: name
                borderEnable: false

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        sidebar.sortName = name
                        sortByListView.visible = false
                    }


                }
            }
        }
    }
}
