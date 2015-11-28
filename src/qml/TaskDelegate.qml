import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: mainRectangle
    x: 0
    y: 0
    width: Consts.ScreenWidth
    height: 350

    state : "HideContant"

    Rectangle {
        id: titleRectangle
        color: "#3670f7"
        width: parent.width
        height: 100

        Text {
            id: titleText
            y: 27
            height: 66
            color: "#ffffff"
            text: title
            style: Text.Normal
            anchors.right: parent.right
            anchors.rightMargin: 101
            anchors.left: parent.left
            anchors.leftMargin: 24
            anchors.verticalCenterOffset: 0
            anchors.verticalCenter: parent.verticalCenter

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

            font.family: "Verdana"
            font.bold: true
            font.pixelSize: 23
        }

        Image {
            id: brImage
            x: 362
            y: 12
            width: 50
            height: 50
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 20
            source: "qrc:/icons/br_down_icon.png"
        }

        MouseArea {

            anchors.fill: parent
            onClicked: {
                if (mainRectangle.state == "HideContant") {
                    mainRectangle.state = "ShowContant"
                } else {
                    mainRectangle.state = "HideContant"
                }
            }
        }
    }

    Rectangle {
        id: taskContant
        x: 0
        y: titleRectangle.height
        width: parent.width

        Text {
            id: priorityText
            text: qsTr("Priority")
            anchors.top: parent.top
            anchors.topMargin: 35
            anchors.left: parent.left
            anchors.leftMargin: 30
            font : titleText.font
        }

        Text {
            id: priorityValue
            text: priority
            anchors.left: parent.right
            anchors.leftMargin: -200
            anchors.verticalCenter: priorityText.verticalCenter
            font : titleText.font
        }

        Text {
            id: reminderDateText
            text: qsTr("Reminder date")
            anchors.top: parent.top
            anchors.topMargin: 100
            anchors.left: parent.left
            anchors.leftMargin: 30
            font : titleText.font
        }

        Text {
            id: reminderDateTextEdit
            text: dueDate
            anchors.verticalCenter: reminderDateText.verticalCenter
            anchors.left: parent.right
            anchors.leftMargin: -200
            font : titleText.font
        }

        Text {
            id: dueDateText
            text: qsTr("Due date")
            anchors.top: parent.top
            anchors.topMargin: 170
            anchors.left: parent.left
            anchors.leftMargin: 30
            font : titleText.font
        }

        Text {
            id: dueDateTextEdit
            text: dueDate
            anchors.verticalCenter: dueDateText.verticalCenter
            anchors.left: parent.right
            anchors.leftMargin: -200
            font : titleText.font
        }
    }
    states: [
        State {
            name: "HideContant"

            PropertyChanges {
                target: mainRectangle
                height: 100
            }

            PropertyChanges {
                target: priorityText
                anchors.leftMargin: 30
                anchors.topMargin: -67
                visible: false
            }

            PropertyChanges {
                target: dueDateTextEdit
                visible: false
            }

            PropertyChanges {
                target: reminderDateTextEdit
                visible: false
            }

            PropertyChanges {
                target: priorityValue
                visible: false
            }

            PropertyChanges {
                target: reminderDateText
                anchors.leftMargin: 30
                anchors.topMargin: -67
                visible: false
            }

            PropertyChanges {
                target: dueDateText
                anchors.leftMargin: 30
                anchors.topMargin: -67
                visible: false
            }
        },
        State {
            name: "ShowContant"
            PropertyChanges { target: brImage; rotation: 180 }
        }
    ]

    transitions: [
        Transition {
            from: "ShowContant"
            to: "HideContant"
            RotationAnimation {
                target: brImage;
                duration: 100
            }
            PropertyAnimation {
                target: mainRectangle;
                property: "height";
                to: 100;
                duration: 100
            }
        },
        Transition {
            from: "HideContant"
            to: "ShowContant"
            RotationAnimation {
                target: brImage;
                duration: 100
            }
            PropertyAnimation {
                target: mainRectangle;
                property: "height";
                to: 350;
                duration: 100
            }
        }
    ]
}
