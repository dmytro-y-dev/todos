import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: sidebarHeader
    width: Consts.ScreenWidth
    height: Consts.ScreenHeight / 5
    x: 0
    y: 0
    color: "#10156a"

    Text {
        anchors.left: parent.right
        anchors.leftMargin: -maxWidth / 1.45
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
        width: sidebarRectangle.width / 8
        height: width

        anchors.left: parent.right
        anchors.leftMargin: -sidebarRectangle.width / 1.04
        anchors.verticalCenter: parent.verticalCenter

        source: "qrc:/icons/resources/icons/user_icon.gif"
    }

    Image {
        width: sidebarRectangle.width / 16
        height: width

        anchors.left: parent.right
        anchors.leftMargin: -sidebarRectangle.width / 6.86
        anchors.verticalCenter: parent.verticalCenter

        source: "qrc:/icons/resources/icons/logout_icon.png"
    }
}

