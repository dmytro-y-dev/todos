import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: dashboardHeader
    width: Consts.ScreenWidth
    height: Consts.ScreenHeight / 6

    color: "#1924d8"

    Rectangle {
        id: rectangle1
        width: dashboardHeader.width / 10
        height: width
        color: "#00000000"
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.verticalCenter: parent.verticalCenter

        Image {
            width: dashboardHeader.width / 25
            height: width

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            source: "qrc:/icons/resources/icons/align_just_icon.png"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                sidebarRectangle.state = "Show"
            }
        }
    }

    Rectangle {
        width: parent.width / 25
        height: width
        color: "#00000000"
        anchors.right: parent.right
        anchors.rightMargin: 50
        anchors.verticalCenter: parent.verticalCenter

        Image {
            anchors.fill: parent
            source: "qrc:/icons/resources/icons/zoom_icon.png"
        }
    }

    Text {
        id: text2
        color: "#f1eeee"
        text: qsTr("BEST Category")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.left: parent.left
        anchors.leftMargin: 100
        font.bold: true
        font.family: "Arial"
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 39
    }

}
