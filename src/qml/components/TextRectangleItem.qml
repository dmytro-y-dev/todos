import QtQuick 2.0

import "../constants.js" as Consts

Rectangle {
    id: namedRectangle

    property alias text: rectangleText.text
    property bool borderEnable: true
    property alias textVisible: rectangleText.visible
    signal clicked()

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight / 8
    color: Consts.MainColor
    border.width: borderEnable ? height / 20 : 0
    border.color: "white"

    Text {
        id: rectangleText
        height: parent.height / 1.5
        color: "#ffffff"

        anchors.fill: parent

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        text: "Some text"
        style: Text.Normal
        FontLoader {id: taskFont; source: "qrc:/fonts/resources/fonts/GoodDog.otf"}
        font.family: taskFont.name
        font.bold: true
        font.pixelSize: parent.height / 2
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            namedRectangle.clicked()
        }
    }
}
