import QtQuick 2.0

Rectangle{
    id: addButton

    property int diameter: 100

    width:  diameter
    height: diameter

    radius: diameter / 2

    gradient: Gradient {
        GradientStop { position: 0.039; color: "#ffffff" }
        GradientStop { position: 0.996; color: "#ffffff" }
        GradientStop { position: 0.258; color: "#1752da" }
        GradientStop { position: 0.712; color: "#6e8fda" }
        GradientStop { position: 0.882; color: "#abc0ef" }
    }

    border.color: "#e7dddd"
    border.width: 3

    Text {
        anchors.fill: parent

        text: qsTr("+")
        font.family: "Arial"
        font.pixelSize: height
        color: "#f9f8f8"

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}

