import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: sidebarRectangle
    // For designer (480 x 800)
    // Replace all applicationWindow vaules
/*
    property int maxWidth: 480
    property int minWidth: 0

    height: 800
    width: minWidth
*/
    property int maxWidth: applicationWindow.width
    property int minWidth: 0

    height: applicationWindow.height
    width: minWidth

    state: "Hide"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.state = "Hide"
        }
    }

    Rectangle {
        id: sidebarHeader
        width: parent.width
        height: 160
        x: 0
        y: 0
        color: "#10156a"
        anchors.leftMargin: 0
        anchors.topMargin: 45

        Text {
            anchors.left: parent.right
            anchors.leftMargin: -330
            anchors.verticalCenter: parent.verticalCenter

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            text: qsTr("USER_NAME")
            font.bold: true
            font.family: "Arial"
            font.pixelSize: 30
            color: "#eeecec"
        }

        Image {
            width: 100
            height: 100

            anchors.left: parent.right
            anchors.leftMargin: -460
            anchors.verticalCenter: parent.verticalCenter

            source: "qrc:/icons/resources/icons/user_icon.gif"
        }

        Image {
            width: 50
            height: 50

            anchors.left: parent.right
            anchors.leftMargin: -70
            anchors.verticalCenter: parent.verticalCenter

            source: "qrc:/icons/resources/icons/logout_icon.png"
        }
    }

    states: [
        State {
            name: "Show"
            PropertyChanges {
                target: sidebarRectangle
                width: maxWidth
            }
        },
        State {
            name: "Hide"
            PropertyChanges {
                target: sidebarRectangle
                width: minWidth
            }
        }
    ]

    transitions: [
        Transition {
            from: "Show"
            to: "Hide"
            PropertyAnimation {
                target: sidebarRectangle;
                property: "width";
                to: minWidth;
                duration: Consts.AnimationDuration
            }
        },
        Transition {
            from: "Hide"
            to: "Show"
            PropertyAnimation {
                target: sidebarRectangle;
                property: "width";
                to: maxWidth;
                duration: Consts.AnimationDuration
            }
        }
    ]
}

