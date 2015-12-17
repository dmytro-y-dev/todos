import QtQuick 2.0
import QtQml.Models 2.1
import QtQuick.Controls 1.4

import "components"

import "constants.js" as Consts

Rectangle {
    id: sidebar

    height: Consts.ScreenHeight
    width: Consts.ScreenWidth

    //property alias model: sidebarView.model

    state: "Hide"

    Rectangle {
        id: header
        width: sidebar.width
        height: sidebar.height / 5
        color: "#10156a"

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

    /*CategoryComboBox {
        id: categoryComboBox
        width: 100
        height: 50
        //model: coreEngine.categoryModel
        MouseArea {
            anchors.fill: parent
            onClicked: {
                categoryComboBox.color = "blue"
            }
        }
    }*/

    Column {
        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Text {
            text: qsTr("Category filter")
            font.pixelSize: sidebar.height / 10
        }


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

