import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: rectangle1
    width: Consts.ScreenWidth
    height: Consts.ScreenHeight
    color: "#292b52"
    Text {
        text: qsTr("TODOS")

        color: "#ffffff"
        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: parent.height / 5
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.visible = false
        }
    }
}

