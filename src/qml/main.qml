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
        z : 4
    }

    Dashboard{
        id: dashboard
        width: screenManager.width
        height: screenManager.height
        z : 1
    }

    Sidebar {
        id: sidebarRectangle
        width: screenManager.width
        height: screenManager.height
        z:2
    }

    LogInWindow {
        id: loginWindow
        width: screenManager.width
        height: screenManager.height
        visible: false
        z : 3
    }

    SignUpWindow {
        id: signUpWindow
        width: screenManager.width
        height: screenManager.height
        visible: false
        z : 3
    }
}
