import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

import "constants.js" as Consts

ApplicationWindow {
    visible: true

    // for mobile screen (full screen)
    /*
    width: Screen.width
    height: Screen.height
    */

    // for PC
    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    ListView {
        id: mainDashboard
        width: parent.width
        height: parent.height
        model: TestTaskModel{}
        delegate: Component { TaskDelegate {} }
    }
}
