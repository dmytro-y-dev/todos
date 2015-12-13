import QtQuick 2.0
import QtQml.Models 2.1

import "constants.js" as Consts

Rectangle {
    id: sidebar

    height: Consts.ScreenHeight
    width: Consts.ScreenWidth

    property alias model: sidebarView.model

    state: "Hide"

    ListView {
        id: sidebarView
        anchors.fill: parent

        signal sectionClicked(string name)

        header: sidebarHeader

        delegate: section
        section.property: "type"
        section.criteria: ViewSection.FullString
        section.delegate: sectionHeading

    }

    Component {
        id: sidebarHeader
        Rectangle {
            width: sidebar.width
            height: sidebar.height / 5
            color: "#10156a"

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

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    sidebar.state = "Hide"
                }
            }
        }
    }

    Component {
        id: sectionHeading

        Rectangle {
            id: sectionHeadingRectangle
            width: sidebar.width
            height: 100
            color: Consts.MainColor

            Text {
                id: sectionText
                anchors.right: parent.right
                anchors.rightMargin: parent.width / 4.8
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 20
                anchors.verticalCenterOffset: 0
                anchors.verticalCenter: parent.verticalCenter

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft

                text: section
                font.bold: true
                color: "#ffffff"
                style: Text.Normal
                FontLoader {id: taskFont; source: "qrc:/fonts/resources/fonts/GoodDog.otf"}
                font.family: taskFont.name
                font.pixelSize: parent.height / 2.5
            }

            Image {
                id: brImage
                width: parent.width / 12
                height: parent.width / 12
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: parent.width / 24
                source: "qrc:/icons/resources/icons/br_down_icon.png"
                antialiasing: true
            }
            MouseArea {
                anchors.fill: parent
                onClicked: sidebarView.sectionClicked(section)
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

            Text {
                id: mainText;
                text: display.name;
                FontLoader {id: taskFont; source: "qrc:/fonts/resources/fonts/GoodDog.otf"}
                font.family: taskFont.name
                font.pixelSize: sidebar.height / 20
            }
            Connections {
                target: rect.ListView.view
                onSectionClicked: if (rect.ListView.section === name) shown = !shown;
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

