import QtQuick 2.0

Rectangle {
    id: button

    property string text: qsTr("Ok")

    width: 240
    height: 80
    radius: 30

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#ffffff"
        }

        GradientStop {
            position: 0.751
            color: "#292b52"
        }

        GradientStop {
            position: 0.337
            color: "#4b4e96"
        }

        GradientStop {
            position: 0.957
            color: "#1f202e"
        }
    }

    Text {
        text: button.text
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        font.pointSize: 30
        color: "#ffffff"
    }

    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter

}
