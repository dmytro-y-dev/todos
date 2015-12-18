import QtQuick 2.0

import "components"
import "constants.js" as Consts

Rectangle {
    id: categoryListView

    property alias model: view.model
    property bool showContextMenu: false
    property int selectedTaskIndex: -1

    onShowContextMenuChanged: {
        contextMenu.visible = showContextMenu
    }

    color: Consts.MainColor

    ListView {
        id: view

        signal clearSelection()

        anchors.fill : parent

        header: TextRectangleItem{
            width: categoryListView.width
            height: categoryListView.height / 7
            color: Consts.MainColorDark
            text: "Users category"
        }

        delegate: Component {
            TextRectangleItem {
                id: delegate
                width: categoryListView.width
                height: categoryListView.height / 8
                text: display.name
                borderEnable: false

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        sidebar.categoryName = parent.text
                        categoryListView.visible = false
                        view.clearSelection()
                        selectedTaskIndex = model.index
                    }
                    onPressAndHold: {
                        if (delegate.color == Consts.MainColorDark) {
                            delegate.color = Consts.MainColor
                            showContextMenu = false
                            selectedTaskIndex = -1
                        } else {
                            view.clearSelection()
                            delegate.color = Consts.MainColorDark
                            showContextMenu = true
                            selectedTaskIndex = model.index
                        }
                    }

                }
                Connections {
                    target: view
                    onClearSelection:{
                        delegate.color = Consts.MainColor
                        categoryListView.showContextMenu = false
                    }
                }
            }
        }
    }

    AddButton {
        id: addButton
        diameter: categoryListView.width / 4.8

        anchors.bottom: parent.bottom
        anchors.bottomMargin: categoryListView.width / 8
        anchors.right: parent.right
        anchors.rightMargin: categoryListView.width / 16

        onClicked: {
            categoryEditWindow.action = "create"
            categoryEditWindow.visible = true
            categoryEditWindow.categoryName = ""
        }
    }

    ContextMenu {
        id: contextMenu

        width: categoryListView.width
        height: categoryListView.height / 8

        anchors.top : addButton.top
        anchors.bottom: addButton.bottom
        showCompleteButton: false

        visible: false


        onEditTaskClicked: {
            categoryEditWindow.action = "edit"
            categoryEditWindow.visible = true
            categoryEditWindow.categoryName = coreEngine.getCategoryNameByIndex(selectedTaskIndex)
        }

        onDeleteTaskClicked: {
            coreEngine.deleteCategory(selectedTaskIndex)
            showContextMenu = false
        }
    }
}
