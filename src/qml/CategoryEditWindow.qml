import QtQuick 2.0
import QtQml 2.2

import "constants.js" as Consts
import "components"

Rectangle {
    id: categoryEditWindow

    property alias  categoryName: name.text

    property string action: "create"

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    color: Consts.MainColor

    Text {
        anchors.top: categoryEditWindow.top
        anchors.topMargin: categoryEditWindow.height / 8
        anchors.horizontalCenter: categoryEditWindow.horizontalCenter

        text: qsTr("Category Edit")
        color: "#ffffff"
        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        font.pixelSize: categoryEditWindow.height / 15
    }

    Grid {
        anchors.horizontalCenter: parent.horizontalCenter
        y: categoryEditWindow.height / 2.42

        columns: 2

        property int lineEditWidth:  categoryEditWindow.width / 2
        property int lineEditHeight: categoryEditWindow.height / 13
        property int labelFontSize:  categoryEditWindow.height / 20

        Text {
            text: qsTr("Name")
            color: "white"
            font.pixelSize: parent.labelFontSize
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        CustomLineEdit {
            id: name

            width: parent.lineEditWidth
            height: parent.lineEditHeight

            text: taskEditWindow.taskName
        }
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: categoryEditWindow.height / 40
        anchors.right: parent.right
        anchors.rightMargin: categoryEditWindow.width / 24

        spacing: categoryEditWindow.width / 48

        TileButton {
            width: categoryEditWindow.width / 3
            height: categoryEditWindow.height / 10

            text: qsTr("Cancel")

            onClicked: {
                categoryEditWindow.visible = false
                categoryListView.showContextMenu = false
            }
        }

        TileButton {
            width: categoryEditWindow.width / 3
            height: categoryEditWindow.height / 10

            text: qsTr("OK")

            onClicked: {
                categoryEditWindow.visible = false
                if (action == "create") {
                    coreEngine.addCategory(categoryName)
                } else {
                    coreEngine.updateCategory(categoryListView.selectedTaskIndex, categoryName)
                }
                categoryListView.showContextMenu = false
            }
        }

    }
}

