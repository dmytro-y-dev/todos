import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: signUpWindow

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    color: "#292b52"

    Text {
        anchors.top: parent.top
        anchors.topMargin: parent.height / 20
        anchors.horizontalCenter: parent.horizontalCenter

        text: qsTr("Sign Up")
        color: "#ffffff"
        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        font.pixelSize: parent.height / 6
    }

    Text {
        id: nicknameText

        anchors.top: parent.top
        anchors.topMargin: parent.height / 3.88
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 9.6

        text: qsTr("Nickname")
        color: "#ffffff"
        font.pixelSize: parent.height / 32
    }

    Text {
        id: emailText

        anchors.top: parent.top
        anchors.topMargin: parent.height / 2.54
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 9.6

        text: qsTr("Email")
        color: "#ffffff"
        font.pixelSize: parent.height / 32
    }

    Text {
        id: passwordText

        anchors.top: parent.top
        anchors.topMargin:parent.height / 1.86
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 9.6

        text: qsTr("Password")
        color: "#ffffff"
        font: emailText.font
    }

    Text {
        id: passwordText2

        anchors.top: parent.top
        anchors.topMargin: parent.height / 1.47
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 9.6

        text: qsTr("Confirm password")
        color: "#ffffff"
        font: emailText.font
    }

    Rectangle {
        id: nickname

        anchors.top: parent.top
        anchors.topMargin: parent.height / 3.33
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 9.6

        width: parent.width / 2
        height: parent.height / 13

        color: "#2b2e59"

        radius: parent.height / 160

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
        id: email

        anchors.top: parent.top
        anchors.topMargin: parent.height / 2.29
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 9.6

        width: parent.width / 2
        height: parent.height / 13

        color: "#2b2e59"

        radius: parent.height / 160

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
        id: password

        anchors.top: parent.top
        anchors.topMargin: parent.height / 1.7
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 9.6

        width: parent.width / 2
        height: parent.height / 13

        color: "#2b2e59"

        radius: parent.height / 160

        TextInput {
            anchors.fill: parent

            text: qsTr("")
            color: "#ffffff"
            font: emailText.font
            echoMode: TextInput.Password
            passwordCharacter: qsTr("●")
            verticalAlignment: Text.AlignVCenter

            clip: true
        }
    }

    Rectangle {
        id: password2

        anchors.top: parent.top
        anchors.topMargin: parent.height / 1.36
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 9.6

        width: parent.width / 2
        height: parent.height / 13

        color: "#2b2e59"

        radius: parent.height / 160

        TextInput {
            anchors.fill: parent

            text: qsTr("")
            color: "#ffffff"
            font: emailText.font
            echoMode: TextInput.Password
            passwordCharacter: qsTr("●")
            verticalAlignment: Text.AlignVCenter

            clip: true
        }
    }

    GradientButton {
        anchors.top: parent.top
        anchors.topMargin: parent.height / 1.16
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: parent.width / 4.8

        width: parent.width / 2
        height: parent.height / 10

        text: qsTr("Sign Up")

        MouseArea {
            anchors.fill: parent
            onClicked: { signUpWindow.visible = false }
        }
    }
}

