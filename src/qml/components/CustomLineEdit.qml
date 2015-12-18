import QtQuick 2.0

import "../constants.js" as Consts

Rectangle {
    id: customLineEdit

    property bool hideCharacter: false
    property alias text: input.text
    property alias font: input.font

    width: 240
    height: 62

    color: Consts.MainColorLight
    radius: 5

    TextInput {
        id: input
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        text: qsTr("")
        color: "#ffffff"
        FontLoader {id: taskFont; source: "qrc:/fonts/resources/fonts/GoodDog.otf"}
        font.family: taskFont.name
        font.bold: true
        font.pixelSize: customLineEdit.height / 2

        clip: true

        echoMode: hideCharacter == true ? TextInput.Password : TextInput.Normal
        passwordCharacter: qsTr("●")
    }
}
