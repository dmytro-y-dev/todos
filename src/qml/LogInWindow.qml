import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: logInWindow
    width: Consts.ScreenWidth
    height: Consts.ScreenHeight
    color: "#292b52"
    Text {
        text: qsTr("Log in")
        color: "#ffffff"
        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        anchors.top: parent.top
        anchors.topMargin: parent.height / 8
        anchors.horizontalCenter: parent.horizontalCenter
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
        id: text2
        x: emailText.x
        y: logInWindow.height / 1.67
        text: qsTr("Password")
        color: "#ffffff"
        font: emailText.font
    }

    Rectangle {
        id: textInput1
        x: emailText.x
        y: logInWindow.height / 2.11
        width: logInWindow.width / 2
        height: logInWindow.height / 13
        color: "#2b2e59"
        radius: 5
        TextInput {
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            text: qsTr("")
            color: "#ffffff"
            clip: true
            font: emailText.font
        }
    }

    Rectangle {
        id: textInput2
        x: emailText.x
        y: logInWindow.height / 1.48
        width: logInWindow.width / 2
        height: logInWindow.height / 13
        color: "#2b2e59"
        radius: 5
        TextInput {
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            text: qsTr("")
            color: "#ffffff"
            clip: true
            echoMode: TextInput.Password
            passwordCharacter: qsTr("●")
            font: emailText.font
        }
    }

    GradientButton {
        id: logInButton
        text: qsTr("Log in")
        width: parent.width / 2
        height: parent.height / 10

        anchors.top: parent.top
        anchors.topMargin: 692
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 98

        MouseArea {
            anchors.fill: parent
            onClicked: {
                logInWindow.visible = false
            }
        }
    }
}

