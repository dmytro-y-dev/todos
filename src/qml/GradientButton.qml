import QtQuick 2.0

Rectangle {
    id: gradientButton

    property string text: qsTr("Button")

    width: 240
    height: 80
    radius: width / 8

    gradient: Gradient {
        GradientStop { position: 0;     color: "#ffffff" }
        GradientStop { position: 0.751; color: "#292b52" }
        GradientStop { position: 0.337; color: "#4b4e96" }
        GradientStop { position: 0.957; color: "#1f202e" }
    }

    Text {
        anchors.fill: parent

        text: gradientButton.text
        font.pointSize: parent.height / 2.67
        color: "#ffffff"

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
