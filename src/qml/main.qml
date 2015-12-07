import QtQuick 2.3
import QtQuick.Controls 1.2

import com.screenmanager 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    ScreenResolutionManager { id: screenManager }

    StartWindow{
        id: startWindow
        width: screenManager.width
        height: screenManager.height
        z : 3
    }

    MainWindow {
        id: mainWindow
        width: screenManager.width
        height: screenManager.height
        z : 1
    }

    LogInWindow {
        id: loginWindow
        width: screenManager.width
        height: screenManager.height
        visible: false
        z : 2
    }

    SignUpWindow {
        id: signUpWindow
        width: screenManager.width
        height: screenManager.height
        visible: false
        z : 2
    }
}
