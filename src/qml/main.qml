import QtQuick 2.3
import QtQuick.Controls 1.2

import com.screenmanager 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    ScreenResolutionManager { id: screenManager }

    MainWindow {
        id: mainWindow
        width: screenManager.width
        height: screenManager.height
    }
}
