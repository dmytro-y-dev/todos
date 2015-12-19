import QtQuick 2.0
import QtQml.Models 2.1

import "components"
import "constants.js" as Consts

Rectangle {
    id: sidebar

    property var upperDueDateFilter: Date()
    property var lowerDueDateFilter: Date()
    property alias filterCategoryName: selectedCategory.text
    property alias sortName: sortByText.text

    property bool categoryFilterEnabled: false
    property bool dueDateFilterEnabled: false

    onSortNameChanged: {
        coreEngine.setSortField(sortName)
    }

    onCategoryFilterEnabledChanged: {
        coreEngine.enableFilterByCategoty(categoryFilterEnabled)
        selectedCategory.color = categoryFilterEnabled ? Consts.MainColorLight : Consts.MainColorDark
        selectedCategory.textVisible = categoryFilterEnabled
    }

    onDueDateFilterEnabledChanged: {
        coreEngine.enableFilterByDueDate(dueDateFilterEnabled)
        upperDueDateFilterText.color = dueDateFilterEnabled ? Consts.MainColorLight : Consts.MainColorDark
        lowerDueDateFilterText.color = dueDateFilterEnabled ? Consts.MainColorLight : Consts.MainColorDark
        upperDueDateFilterText.textVisible = categoryFilterEnabled
        upperDueDateFilterText.textVisible = categoryFilterEnabled
    }

    function applyFilrets() {
        if (categoryFilterEnabled) {
            if (filterCategoryName == "") {
                return false;
            } else {
                coreEngine.setFilterByCategoty(filterCategoryName);
            }
        }

        if (dueDateFilterEnabled) {
            if (upperDueDateFilterText.text == "" || lowerDueDateFilterText.text == ""){
                return false;
            } else {
                coreEngine.setFilterByDueDate(lowerDueDateFilter, upperDueDateFilter);
            }
        }

        return true;
    }

    height: Consts.ScreenHeight
    width: Consts.ScreenWidth

    state: "Hide"

    color: Consts.MainColor

    Rectangle {
        id: header
        width: sidebar.width
        height: sidebar.height / 5
        color: Consts.MainColorDark

        Text {
            anchors.left: parent.right
            anchors.leftMargin: -sidebar.width / 1.45
            anchors.verticalCenter: parent.verticalCenter

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            text: coreEngine.userName
            font.bold: true
            font.family: "Arial"
            font.pixelSize: 30
            color: "#eeecec"
        }

        Image {
            width: sidebar.width / 8
            height: width

            anchors.left: parent.right
            anchors.leftMargin: -sidebar.width / 1.04
            anchors.verticalCenter: parent.verticalCenter

            source: "qrc:/icons/resources/icons/user_icon.gif"
        }

        Image {
            width: sidebar.width / 16
            height: width

            anchors.left: parent.right
            anchors.leftMargin: -sidebar.width / 6.86
            anchors.verticalCenter: parent.verticalCenter

            source: "qrc:/icons/resources/icons/logout_icon.png"
        }
    }

    Column {
        anchors.leftMargin: 50
        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        spacing: sidebar.height / 80

        Rectangle {
            color: sidebar.color
            height: sidebar.height / 30
            width: sidebar.width / 2
        }

        CustomCheckBox {
            id: categoryFilter
            text: "Category filter"
            checked: false
            onCheckedChanged: {
                categoryFilterEnabled = checked
            }
        }

        TextRectangleItem {
            id: selectedCategory
            height: sidebar.height / 15
            width: sidebar.width / 2
            text: ""
            borderEnable: false
            color: Consts.MainColorDark

            onClicked: {
                if (categoryFilterEnabled) {
                    categoryListView.visible = true
                }
            }
        }

        Rectangle {
            color: sidebar.color
            height: sidebar.height / 30
            width: sidebar.width / 2
        }

        CustomCheckBox {
            id: duedateFilter
            text: "Due date filter"
            checked: false
            onCheckedChanged: {
                dueDateFilterEnabled = checked
            }
        }

        Row {
            spacing: sidebar.width / 24
            Text {
                text: qsTr("Lower limit")
                color: "#ffffff"
                font.pixelSize: sidebar.height / 20
            }
            TextRectangleItem {
                id: lowerDueDateFilterText
                height: sidebar.height / 15
                width: sidebar.width / 3
                borderEnable: false
                color: Consts.MainColorDark

                text: Qt.formatDate(lowerDueDateFilter, "dd.MM.yyyy")

                onClicked: {
                    if (dueDateFilterEnabled) {
                        calendarView.visible = true
                        calendarView.editor = "filterLowerLimit"
                    }
                }
            }
        }

        Row {
            spacing: sidebar.width / 24
            Text {
                text: qsTr("Upper limit")
                color: "#ffffff"
                font.pixelSize: sidebar.height / 20
            }

            TextRectangleItem {
                id: upperDueDateFilterText
                height: sidebar.height / 15
                width: sidebar.width / 3
                borderEnable: false
                color: Consts.MainColorDark

                text: Qt.formatDate(upperDueDateFilter, "dd.MM.yyyy")

                onClicked: {
                    if (dueDateFilterEnabled) {
                        calendarView.visible = true
                        calendarView.editor = "filterUpperLimit"
                    }
                }
            }
        }

        Rectangle {
            color: sidebar.color
            height: sidebar.height / 30
            width: sidebar.width / 2
        }

        Text {
            text: qsTr("Sort by")
            color: "#ffffff"
            font.pixelSize: sidebar.height / 20
        }

        TextRectangleItem {
            id: sortByText
            height: sidebar.height / 15
            width: sidebar.width / 2
            borderEnable: false
            text: "Title"
            color: Consts.MainColorLight

            onClicked: {
                sortByListView.visible = true
            }
        }
    }

    TileButton {
        width: parent.width / 2
        height: parent.height / 10

        anchors.top: parent.top
        anchors.topMargin: parent.height / 1.16
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: parent.width / 4.8

        text: qsTr("Ok")

        onClicked: {
            if (applyFilrets()) {
                coreEngine.updateTaskList()
                sidebar.state = "Hide"
            }
        }
    }



    states: [
        State { name: "Show"; PropertyChanges { target: sidebar; x: 0 } },
        State { name: "Hide"; PropertyChanges { target: sidebar; x: -sidebar.width } }
    ]

    transitions: [
        Transition {
            from: "Show"
            to: "Hide"
            PropertyAnimation {
                target: sidebar;
                property: "x";
                to: -sidebar.width;
                duration: Consts.AnimationDuration
            }
        },
        Transition {
            from: "Hide"
            to: "Show"
            PropertyAnimation {
                target: sidebar;
                property: "x";
                to: 0;
                duration: Consts.AnimationDuration
            }
        }
    ]
}

