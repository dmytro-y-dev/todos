import QtQuick 2.0

import "../constants.js" as Consts

Rectangle {
    id: customLineEdit

    property bool hideCharacter: false
    property alias text: input.text

    width: 240
    height: 62

    color: Consts.MainColorLight
    radius: 5

    TextInput {
        id: input
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter

        text: qsTr("")
        color: "#ffffff"
        font.pixelSize: customLineEdit.height / 1.5

        clip: true

        echoMode: hideCharacter == true ? TextInput.Password : TextInput.Normal
        passwordCharacter: qsTr("●")
    }
}
