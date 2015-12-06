import QtQuick 2.0

import "constants.js" as Consts

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

    Text {
        id: emailText

        x: logInWindow.width / 9.6
        y: logInWindow.height / 2.42

        text: qsTr("Email")
        color: "#ffffff"
        font.pixelSize: logInWindow.height / 32
    }

    Text {
        x: emailText.x
        y: logInWindow.height / 1.67

        text: qsTr("Password")
        color: "#ffffff"
        font: emailText.font
    }

    Rectangle {
        x: emailText.x
        y: logInWindow.height / 2.11

        width: logInWindow.width / 2
        height: logInWindow.height / 13

        color: "#2b2e59"
        radius: logInWindow / 160

        TextInput {
            anchors.fill: parent

            text: qsTr("")
            color: "#ffffff"
            font: emailText.font
            verticalAlignment: Text.AlignVCenter
            clip: true
        }
    }

    Rectangle {
        x: emailText.x
        y: logInWindow.height / 1.48

        width: logInWindow.width / 2
        height: logInWindow.height / 13

        color: "#2b2e59"
        radius: logInWindow / 160
        TextInput {
            anchors.fill: parent

            text: qsTr("")
            color: "#ffffff"
            echoMode: TextInput.Password
            passwordCharacter: qsTr("●")
            font: emailText.font
            verticalAlignment: Text.AlignVCenter
            clip: true
        }
    }

    GradientButton {
        width: parent.width / 2
        height: parent.height / 10

        anchors.top: parent.top
        anchors.topMargin: logInWindow.height / 1.16
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: logInWindow.width / 4.8

        text: qsTr("Log in")

        MouseArea {
            anchors.fill: parent
            onClicked: { logInWindow.visible = false }
        }
    }
}

