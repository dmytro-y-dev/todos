import QtQuick 2.0

import "../constants.js" as Consts

Rectangle {
    id: tileButton

    property string text: qsTr("Button")

    signal clicked()

    width: 240
    height: 80
    color: Consts.MainColor
    border.color: "white"
    border.width: 5

    Text {
        anchors.fill: parent

        text: tileButton.text
        font.pointSize: parent.height / 4
        color: "#ffffff"

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    MouseArea {
        anchors.fill: parent
        onClicked: { tileButton.clicked() }
    }
}
