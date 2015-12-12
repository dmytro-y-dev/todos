import QtQuick 2.0

import "constants.js" as Consts
import "components"

Rectangle {
    id: logInWindow

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    color: "#292b52"

    Text {
        anchors.top: parent.top
        anchors.topMargin: parent.height / 8
        anchors.horizontalCenter: parent.horizontalCenter

        text: qsTr("Log in")
        color: "#ffffff"
        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        font.pixelSize: parent.height / 5
    }

    Column {
        x: logInWindow.width / 9.6
        y: logInWindow.height / 2.42

        spacing: logInWindow.height / 80

        Text {
            text: qsTr("Email")
            color: "#ffffff"
            font.pixelSize: logInWindow.height / 32
        }

        CustomLineEdit {
            id: email

            width: logInWindow.width / 2
            height: logInWindow.height / 13
        }

        Text {
            text: qsTr("Password")
            color: "#ffffff"
            font.pixelSize: logInWindow.height / 32
        }

        CustomLineEdit {
            id: password

            width: logInWindow.width / 2
            height: logInWindow.height / 13
            hideCharacter: true
        }
    }

    TileButton {
        width: parent.width / 2
        height: parent.height / 10

        anchors.top: parent.top
        anchors.topMargin: logInWindow.height / 1.16
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: logInWindow.width / 4.8

        text: qsTr("Log in")

        onClicked: {
            logInWindow.visible = false
            // TODO
            // login(email.text, password.text)
        }
    }
}

