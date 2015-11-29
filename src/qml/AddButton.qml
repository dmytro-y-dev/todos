import QtQuick 2.0

import "constants.js" as Consts

Rectangle{
    width: screenManager.width / 8
    height: width
    color: Consts.MainColor
    radius: width / 2

    Text {
        color: "#f9f8f8"
        text: qsTr("+")
        font.underline: false
        font.italic: false
        font.family: "Arial"
        font.bold: false
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: height
    }
}

