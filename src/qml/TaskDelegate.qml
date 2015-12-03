import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: mainRectangle
    x: 0
    y: 0

    property int showContantHeight: Consts.ScreenHeight / 2.3
    property int hideContantHeight: Consts.ScreenHeight / 8


    width: Consts.ScreenWidth
    height: showContantHeight

    state : "HideContant"

    Rectangle {
        id: titleRectangle
        color: Consts.MainColor
        width: parent.width
        height: hideContantHeight

        Text {
            id: titleText
            height: parent.height / 1.5
            color: "#ffffff"

            anchors.right: parent.right
            anchors.rightMargin: parent.width / 4.8
            anchors.left: parent.left
            anchors.leftMargin: parent.width / 20
            anchors.verticalCenterOffset: 0
            anchors.verticalCenter: parent.verticalCenter

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

            text: title
            style: Text.Normal
            FontLoader {id: taskFont; source: "qrc:/fonts/resources/fonts/GoodDog.otf"}
            font.family: taskFont.name
            font.bold: true
            font.pixelSize: parent.height / 2.5
        }

        Image {
            id: brImage
            width: parent.width / 12
            height: parent.width / 12
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: parent.width / 24
            source: "qrc:/icons/resources/icons/br_down_icon.png"
            antialiasing: true
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
            onPressAndHold:{
             textTaskModel.remove(model.index)
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
                height: hideContantHeight
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

            PropertyChanges {
                target: brImage;
                rotation: -180
            }

            PropertyChanges {
                target: mainRectangle
                height: showContantHeight
            }
        }
    ]

    transitions: [
        Transition {
            from: "ShowContant"
            to: "HideContant"
            RotationAnimation {
                target: brImage;
                duration: Consts.AnimationDuration
            }
            PropertyAnimation {
                target: mainRectangle;
                property: "height";
                to: hideContantHeight;
                duration: Consts.AnimationDuration
            }
        },
        Transition {
            from: "HideContant"
            to: "ShowContant"
            RotationAnimation {
                target: brImage;
                duration: Consts.AnimationDuration
            }
            PropertyAnimation {
                target: mainRectangle;
                property: "height";
                to: showContantHeight;
                duration: Consts.AnimationDuration
            }
        }
    ]
}
