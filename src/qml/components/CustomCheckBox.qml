import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "../constants.js" as Consts

CheckBox {
    id: customCheckBox

    property int size: 30
    text: "text"
    style: CheckBoxStyle {
        indicator: Rectangle {
            implicitWidth: size
            implicitHeight: size
            radius: size / 6
            border.color: control.activeFocus ? "darkblue" : "gray"
            border.width: 1
            Rectangle {
                visible: control.checked
                color: Consts.MainColorDark
                border.color: Consts.MainColorLight
                radius: 1
                anchors.margins: 4
                anchors.fill: parent
            }
        }
        label: Text {
            text: customCheckBox.text
            font.pixelSize: size
            color: "white"
        }

        spacing: size

    }
}
