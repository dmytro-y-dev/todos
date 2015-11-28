import QtQuick 2.3
import QtQuick.Controls 1.2

import "constants.js" as Consts

ApplicationWindow {
    visible: true
    width: Consts.ScreenWidth
    height: Consts.ScreenHeight
    title: qsTr("TODOS")

    Label {
        text: qsTr("TODOS")
        anchors.centerIn: parent
    }
}

