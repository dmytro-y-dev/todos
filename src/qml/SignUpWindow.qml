import QtQuick 2.0

import "constants.js" as Consts
import "components"

Rectangle {
    id: signUpWindow

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    color: Consts.MainColor

    Text {
        anchors.top: signUpWindow.top
        anchors.topMargin: signUpWindow.height / 20
        anchors.horizontalCenter: signUpWindow.horizontalCenter

        text: qsTr("Sign Up")
        color: "#ffffff"
        FontLoader { id: taskFont; source: "qrc:/fonts/resources/fonts/Mona Shark.otf" }
        font.family: taskFont.name
        font.pixelSize: signUpWindow.height / 6
    }

    Column {
        anchors.top: signUpWindow.top
        anchors.topMargin: signUpWindow.height / 3.88
        anchors.left: signUpWindow.left
        anchors.leftMargin: signUpWindow.width / 9.6

        spacing: signUpWindow.height / 80

        Text {
            text: qsTr("Nickname")
            color: "#ffffff"
            font.pixelSize: signUpWindow.height / 32
        }

        CustomLineEdit {
            id: nickname

            width: signUpWindow.width / 2
            height: signUpWindow.height / 13
        }

        Text {
            text: qsTr("Email")
            color: "#ffffff"
            font.pixelSize: signUpWindow.height / 32
        }

        CustomLineEdit {
            id: email

            width: signUpWindow.width / 2
            height: signUpWindow.height / 13
        }

        Text {
            text: qsTr("Password")
            color: "#ffffff"
            font.pixelSize: signUpWindow.height / 32
        }

        CustomLineEdit {
            id: password

            width: signUpWindow.width / 2
            height: signUpWindow.height / 13
            hideCharacter: true
        }

        Text {
            text: qsTr("Confirm password")
            color: "#ffffff"
            font.pixelSize: signUpWindow.height / 32
        }

        CustomLineEdit {
            id: password2

            width: signUpWindow.width / 2
            height: signUpWindow.height / 13
            hideCharacter: true
        }
    }

    TileButton {
        anchors.top: signUpWindow.top
        anchors.topMargin: signUpWindow.height / 1.16
        anchors.horizontalCenter: signUpWindow.horizontalCenter
        anchors.horizontalCenterOffset: signUpWindow.width / 4.8

        width: signUpWindow.width / 2
        height: signUpWindow.height / 10

        text: qsTr("Sign Up")

        onClicked: {
            if (coreEngine.signUp(nickname.text, email.text, password.text)) {
                signUpWindow.visible = false
            }
        }
    }
}

