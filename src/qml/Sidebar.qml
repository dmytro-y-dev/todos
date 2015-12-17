import QtQuick 2.0
import QtQml.Models 2.1

import "components"
import "constants.js" as Consts

Rectangle {
    id: sidebar

    height: Consts.ScreenHeight
    width: Consts.ScreenWidth

    state: "Hide"

    color: Consts.MainColor

    Rectangle {
        id: header
        width: sidebar.width
        height: sidebar.height / 5
        color: Consts.MainColorDark

        Text {
            anchors.left: parent.right
            anchors.leftMargin: -sidebar.width / 1.45
            anchors.verticalCenter: parent.verticalCenter

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            text: coreEngine.userName
            font.bold: true
            font.family: "Arial"
            font.pixelSize: 30
            color: "#eeecec"
        }

        Image {
            width: sidebar.width / 8
            height: width

            anchors.left: parent.right
            anchors.leftMargin: -sidebar.width / 1.04
            anchors.verticalCenter: parent.verticalCenter

            source: "qrc:/icons/resources/icons/user_icon.gif"
        }

        Image {
            width: sidebar.width / 16
            height: width

            anchors.left: parent.right
            anchors.leftMargin: -sidebar.width / 6.86
            anchors.verticalCenter: parent.verticalCenter

            source: "qrc:/icons/resources/icons/logout_icon.png"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                sidebar.state = "Hide"
            }
        }
    }

    Column {
        anchors.leftMargin: 50
        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        spacing: sidebar.height / 80

        Rectangle {
            color: sidebar.color
            height: sidebar.height / 30
            width: sidebar.width / 2
        }

        CustomCheckBox {
            id: categoryFilter
            text: "Category filter"
        }

        TextRectangleItem {
            id: selectedCategory
            height: sidebar.height / 15
            width: sidebar.width / 2
            text: "-"
            borderEnable: false
            color: Consts.MainColorLight
        }

        Rectangle {
            color: sidebar.color
            height: sidebar.height / 30
            width: sidebar.width / 2
        }

        CustomCheckBox {
            id: duedateFilter
            text: "Due date filter"
        }

        Row {
            spacing: sidebar.width / 24
            Text {
                text: qsTr("Upper limit")
                color: "#ffffff"
                font.pixelSize: sidebar.height / 20
            }

            TextRectangleItem {
                height: sidebar.height / 15
                width: sidebar.width / 3
                text: "-"
                borderEnable: false
                color: Consts.MainColorLight
            }
        }

        Row {
            spacing: sidebar.width / 24
            Text {
                text: qsTr("Lower limit")
                color: "#ffffff"
                font.pixelSize: sidebar.height / 20
            }
            TextRectangleItem {
                height: sidebar.height / 15
                width: sidebar.width / 3
                text: "-"
                borderEnable: false
                color: Consts.MainColorLight
            }
        }

        Rectangle {
            color: sidebar.color
            height: sidebar.height / 30
            width: sidebar.width / 2
        }

        Text {
            text: qsTr("Sort by")
            color: "#ffffff"
            font.pixelSize: sidebar.height / 20
        }

        TextRectangleItem {
            height: sidebar.height / 15
            width: sidebar.width / 2
            text: "-"
            borderEnable: false
            color: Consts.MainColorLight
        }
    }

    TileButton {
        width: parent.width / 2
        height: parent.height / 10

        anchors.top: parent.top
        anchors.topMargin: parent.height / 1.16
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: parent.width / 4.8

        text: qsTr("Ok")

        onClicked: {      }
    }



    states: [
        State { name: "Show"; PropertyChanges { target: sidebar; x: 0 } },
        State { name: "Hide"; PropertyChanges { target: sidebar; x: -sidebar.width } }
    ]

    transitions: [
        Transition {
            from: "Show"
            to: "Hide"
            PropertyAnimation {
                target: sidebar;
                property: "x";
                to: -sidebar.width;
                duration: Consts.AnimationDuration
            }
        },
        Transition {
            from: "Hide"
            to: "Show"
            PropertyAnimation {
                target: sidebar;
                property: "x";
                to: 0;
                duration: Consts.AnimationDuration
            }
        }
    ]
}

