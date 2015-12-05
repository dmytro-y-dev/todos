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
        anchors.top: parent.top
        anchors.topMargin: parent.height / 4
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: parent.height / 5
    }

    Rectangle {
        id: logInButton
        width: parent.width / 2
        height: parent.height / 10
        radius: 30
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ffffff"
            }

            GradientStop {
                position: 0.751
                color: "#292b52"
            }

            GradientStop {
                position: 0.337
                color: "#4b4e96"
            }

            GradientStop {
                position: 0.957
                color: "#1f202e"
            }
        }

        Text {
            text: qsTr("Log In")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pointSize: 30
            color: "#ffffff"
        }

        anchors.top: parent.top
        anchors.topMargin: parent.height / 2
        anchors.horizontalCenter: parent.horizontalCenter

        MouseArea {
            anchors.fill: parent
            onClicked: {
                startWindow.visible = false
            }
        }
    }

    Rectangle {
        id: signUpButton
        width: parent.width / 2
        height: parent.height / 10
        radius: 30
        anchors.horizontalCenterOffset: 0
        anchors.topMargin: 507
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ffffff"
            }

            GradientStop {
                position: 0.751
                color: "#292b52"
            }

            GradientStop {
                position: 0.337
                color: "#4b4e96"
            }

            GradientStop {
                position: 0.957
                color: "#1f202e"
            }
        }

        Text {
            text: qsTr("Sing Up")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pointSize: 30
            color: "#ffffff"
        }

        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        MouseArea {
            anchors.fill: parent
            onClicked: {
                startWindow.visible = false
            }
        }
    }
}

