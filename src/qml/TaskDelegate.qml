import QtQuick 2.0
import QtQml.Models 2.1

import "constants.js" as Consts

Rectangle {
    id: task
    x: 0
    y: 0

    property int showContantHeight: Consts.ScreenHeight / 2.3
    property int hideContantHeight: Consts.ScreenHeight / 8
    property int defaultnFontPixelSize: hideContantHeight / 4

    property bool selected: false
    property alias color: titleRectangle.color

    signal taskClicked(int index)
    signal taskPressedAndHold(int index)

    width: Consts.ScreenWidth
    height: showContantHeight

    state : "HideContant"

    onSelectedChanged: {
        color = selected ? Consts.MainColorDark : Consts.MainColor
    }

    Connections{
        target: dashboard
        onClearCelection :
        {
            selected = false
        }
    }

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
            anchors.verticalCenter: parent.verticalCenter

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

            text: display.title
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
                if (dashboard.state == "Default")
                    task.state = task.state == "HideContant" ? "ShowContant" : "HideContant"
                taskClicked(model.index)
            }
            onPressAndHold: {
                taskPressedAndHold(model.index)
                task.selected = true
            }
        }
    }

    Rectangle {
        id: taskContant

        x: 0
        y: titleRectangle.height
        width: parent.width

        property int fontSize: 1

        Grid {
            anchors.top: parent.top
            anchors.topMargin: 35
            anchors.left: parent.left
            anchors.leftMargin: 30

            columns: 2

            spacing: 10

            Text { text: qsTr("Priority");                          font.pixelSize: taskContant.fontSize }
            Text { text: display.priority;                          font.pixelSize: taskContant.fontSize }
            Text { text: qsTr("Reminder date");                     font.pixelSize: taskContant.fontSize }
            Text { text: display.reminderDate.toLocaleDateString(); font.pixelSize: taskContant.fontSize }
            Text { text: qsTr("Due date");                          font.pixelSize: taskContant.fontSize }
            Text { text: display.dueDate.toLocaleDateString();      font.pixelSize: taskContant.fontSize }
            Text { text: qsTr("Status");                            font.pixelSize: taskContant.fontSize }
            Text { text: display.status;                            font.pixelSize: taskContant.fontSize }
        }
    }
    states: [
        State {
            name: "HideContant"

            PropertyChanges { target: task; height: hideContantHeight }
            PropertyChanges { target: taskContant; fontSize: 0 }
        },
        State {
            name: "ShowContant"

            PropertyChanges { target: brImage; rotation: -180 }
            PropertyChanges { target: task;    height: showContantHeight }
            PropertyChanges { target: taskContant; fontSize: defaultnFontPixelSize }
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
                target: task;
                property: "height";
                to: hideContantHeight;
                duration: Consts.AnimationDuration
            }
            PropertyAnimation {
                target: taskContant
                property: "fontSize"
                to: 1
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
                target: task;
                property: "height";
                to: showContantHeight;
                duration: Consts.AnimationDuration
            }
            PropertyAnimation {
                target: taskContant
                property: "fontSize"
                to: defaultnFontPixelSize
                duration: Consts.AnimationDuration
            }
        }
    ]
}
