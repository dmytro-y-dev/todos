import QtQuick 2.0

import QtQuick 2.0

import "components"
import "constants.js" as Consts

Rectangle {
    id: sortByListView

    property bool showContextMenu: true
    property int selectedSortIndex: -1

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
