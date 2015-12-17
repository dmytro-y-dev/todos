import QtQuick 2.0

import "components"
import "constants.js" as Consts

Rectangle {
    id: categoryListView

    property alias model: view.model

    color: Consts.MainColor

    ListView {
        id: view

        anchors.fill : parent

        header: TextRectangleItem{
            width: categoryListView.width
            height: categoryListView.height / 7
            color: Consts.MainColorDark
            text: "Users category"
        }

        delegate: Component {
            TextRectangleItem {
                width: categoryListView.width
                height: categoryListView.height / 8
                text: display.name
            }
        }
    }

    AddButton {
        id: addButton
        diameter: categoryListView.width / 4.8

        anchors.bottom: parent.bottom
        anchors.bottomMargin: categoryListView.width / 8
        anchors.right: parent.right
        anchors.rightMargin: categoryListView.width / 16

        onClicked: {
           // Add category
        }
    }
}
