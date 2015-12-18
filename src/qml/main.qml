import QtQuick 2.3
import QtQuick.Controls 1.2

import TodosEngine 1.0

import "constants.js" as Consts

ApplicationWindow {
    id: main
    visible: true
    ScreenResolutionManager { id: screenManager }


    StartWindow{
        id: startWindow
        width: screenManager.width
        height: screenManager.height
        visible: Consts.ShowLogInWindow
        z : 4
    }

    Dashboard{
        id: dashboard
        width: screenManager.width
        height: screenManager.height
        model: coreEngine.taskModel
        z : 1
    }

    Sidebar {
        id: sidebar
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

    TaskEditWindow {
        id: taskEditWindow
        width: screenManager.width
        height: screenManager.height
        visible: false
        z : 5
    }

    CategoryListView {
        id: categoryListView
        width: screenManager.width
        height: screenManager.height
        visible: false
        model: coreEngine.categoryModel
        z : 6
    }

    CalendarView{
        id: calendarView
        width: screenManager.width
        height: screenManager.height
        visible: false
        z : 7
    }

    CategoryEditWindow {
        id: categoryEditWindow
        width: screenManager.width
        height: screenManager.height
        visible: false
        z : 7
    }
    SortByListView {
        id: sortByListView
        width: screenManager.width
        height: screenManager.height
        visible: false
        z : 8
    }

}
