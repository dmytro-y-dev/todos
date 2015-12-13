import QtQuick 2.0

import "constants.js" as Consts
import "components"

Rectangle {
    id: startWindow

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    color: Consts.MainColor

    Text {
        text: qsTr("TODOS")
        color: "#ffffff"

        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        font.pixelSize: startWindow.height / 5

        anchors.top: startWindow.top
        anchors.topMargin: startWindow.height / 4
        anchors.horizontalCenter: startWindow.horizontalCenter
    }

    Column {
        anchors.top: startWindow.top
        anchors.topMargin: startWindow.height / 2
        anchors.horizontalCenter: startWindow.horizontalCenter

        spacing: startWindow.height / 80

        TileButton {
            width: startWindow.width / 2
            height: startWindow.height / 10
            text: qsTr("Log In")
            onClicked: { startWindow.visible = false; loginWindow.visible = true}
        }
        TileButton {
            width: startWindow.width / 2
            height: startWindow.height / 10
            text: qsTr("Sing Up")
            onClicked: { startWindow.visible = false; signUpWindow.visible = true}
        }
    }
}

