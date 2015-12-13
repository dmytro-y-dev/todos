import QtQuick 2.0

Rectangle{
    id: addButton

    property int diameter: 100

    signal clicked();

    width:  diameter
    height: diameter

    radius: diameter / 2

    color: "#1752da"
    border.color: "#e7dddd"
    border.width: 5

    Text {
        anchors.fill: parent

        text: qsTr("+")
        font.family: "Arial"
        font.pixelSize: height
        color: "#f9f8f8"

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    MouseArea {
        anchors.fill: parent
        onClicked: { addButton.clicked() }
    }
}

