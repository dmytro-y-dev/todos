import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: startWindow

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    color: "#292b52"

    Text {
        text: qsTr("TODOS")
        color: "#ffffff"

        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        font.pixelSize: parent.height / 5

        anchors.top: parent.top
        anchors.topMargin: parent.height / 4
        anchors.horizontalCenter: parent.horizontalCenter
    }

    GradientButton {
        id: logInButton

        text: qsTr("Log In")

        width: parent.width / 2
        height: parent.height / 10

        anchors.top: parent.top
        anchors.topMargin: parent.height / 2
        anchors.horizontalCenter: parent.horizontalCenter

        MouseArea {
            anchors.fill: parent
            onClicked: { startWindow.visible = false }
        }
    }

    GradientButton {
        id: signUpButton

        text: qsTr("Sing Up")

        width: parent.width / 2
        height: parent.height / 10

        anchors.top: parent.top
        anchors.topMargin: parent.height / 1.6
        anchors.horizontalCenter: parent.horizontalCenter

        MouseArea {
            anchors.fill: parent
            onClicked: { startWindow.visible = false }
        }

    }
}

