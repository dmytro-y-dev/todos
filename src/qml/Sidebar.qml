import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: sidebar

    property int maxWidth: Consts.ScreenWidth
    property int minWidth: 0

    height: Consts.ScreenHeight
    width: maxWidth
    x : -maxWidth

    state: "Hide"



    ListView {
        id: view
        anchors.fill: parent

        signal sectionClicked(string name)
        model: TestSidebarModel{id: model}
        header: Component {
            SidebarHeader {
                id: sidebarHeader
                width: sidebar.width
                height: sidebar.height / 5

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        sidebar.state = "Hide"
                    }
                }
            }
        }
        delegate: section
        section.property: "type"
        section.criteria: ViewSection.FullString
        section.delegate: sectionHeading

    }

    Component {
        id: sectionHeading
        Rectangle {
            id: sectionHeadingRectangle
            width: sidebar.width
            height: childrenRect.height
            color: "lightsteelblue"

            Text {
                text: section
                font.bold: true
                font.pixelSize: 20;
            }
            MouseArea {
                anchors.fill: parent
                onClicked: view.sectionClicked(section)
            }
        }
    }

    Component {
        id: section
        Rectangle {
            id: rect
            width: sidebar.width
            height: shown ? mainText.height : 0
            visible: shown
            property bool shown: true

            Text { id: mainText; text: name; font.pixelSize: 18 }
            Connections {
                target: rect.ListView.view
                onSectionClicked: if (rect.ListView.section === name) shown = !shown;
            }
        }
    }

    states: [
        State { name: "Show" },
        State { name: "Hide" }
    ]

    transitions: [
        Transition {
            from: "Show"
            to: "Hide"
            PropertyAnimation {
                target: sidebar;
                property: "x";
                to: -maxWidth;
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

