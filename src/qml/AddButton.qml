import QtQuick 2.0

import "constants.js" as Consts

Rectangle{
    id: addButton
    // For designer (480 x 800)
    // Replace all screenManager vaules

    //width: 100

    width: screenManager.width / 4.8

    height: width
    radius: width / 2
    gradient: Gradient {
        GradientStop {
            position: 0.039
            color: "#1543ae"
        }

        GradientStop {
            position: 0.996
            color: "#ffffff"
        }

        GradientStop {
            position: 0.258
            color: "#1752da"
        }


        GradientStop {
            position: 0.712
            color: "#6e8fda"
        }

        GradientStop {
            position: 0.882
            color: "#abc0ef"
        }
    }
    border.color: "#e7dddd"
    border.width: 3

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

