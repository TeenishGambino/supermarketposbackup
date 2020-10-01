import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import "."
Item{
    Connections {
            target: insideDashboard.item
            onSetQMLSources: {
                insideDashboard.source = ""
                insideDashboard.source = path
            }
        }

        id: rootWindow
        visible: true
        width: 1366
        height: 727
        signal setQMLSource(string path)
        Material.accent: "#000000"
        //flags: Qt.Window | Qt.FramelessWindowHint
        Rectangle {
            width: 1366
            height: 727
            x: 0
            y: 0
            Loader {
                id: insideDashboard
                x: 240
                y: 0
                width: 1126
                height: 727
                source: "customer_dashboard.qml"
            }
            Connections {
                target: insideDashboard.item
                onSetQMLSources: {
                    insideDashboard.source = ""
                    insideDashboard.source = path
                }
            }
        }
        Item {
            id: sidebarContainer
            Image {
                id: sidebar
                source: "UI/customer/sidebar.png"
                x: 0
                y: 0
                width: 240
                height: 727
                opacity: 1
            }
            Image {
                id: request_rect
                source: nonhover
                x: -3
                y: 440
                opacity: 1
                MouseArea {
                    id: rect_hover
                    cursorShape: Qt.PointingHandCursor
                    anchors.fill: parent
                    hoverEnabled: true
                    //onEntered: {parent.source = hover}
                    //onExited: {parent.source = nonhover}
                    onClicked: {
                        insideDashboard.source = "customer_request.qml"
                        sugge_rect1.source = nonhover
                        inventory_rect.source = nonhover
                        request_rect.source = hover
                    }
                }
            }
            Image {
                id: request_icon
                source: "UI/customer/request_icon.png"
                x: 16
                y: 451
                opacity: 1
            }
            Image {
                id: request
                source: "UI/customer/request.png"
                x: 65
                y: 454
                opacity: 1
            }
            Image {
                id: sugge_rect1
                source: nonhover
                x: -3
                y: 384
                opacity: 1
                MouseArea {
                    id: sugge_hover
                    cursorShape: Qt.PointingHandCursor
                    anchors.fill: parent
                    onClicked: {
                        insideDashboard.source = "customer_suggestion.qml"
                        sugge_rect1.source = hover //maybe can create a function that does that//
                        inventory_rect.source = nonhover
                        request_rect.source = nonhover
                    }
                }
            }
            Image {
                id: suggestion
                source: "UI/customer/suggestion.png"
                x: 64
                y: 399
                opacity: 1
            }
            Image {
                id: suggest_icon
                source: "UI/customer/suggest_icon.png"
                x: 0
                y: 0
                opacity: 1
            }
            Image {
                id: inventory_rect
                source: hover
                x: -3
                y: 327
                opacity: 1
                MouseArea {
                    id: inventory_hover
                    cursorShape: Qt.PointingHandCursor
                    anchors.fill: parent
                    onClicked: {
                        insideDashboard.source = "customer_dashboard.qml"
                        sugge_rect1.source = nonhover
                        inventory_rect.source = hover
                        request_rect.source = nonhover
                    }
                }
            }
            Image {
                id: inventory_icon
                source: "UI/customer/inventory_icon.png"
                x: 15
                y: 337
                opacity: 1
            }
            Image {
                id: inventory
                source: "UI/customer/inventory.png"
                x: 66
                y: 344
                opacity: 1
            }
            Image {
                id: logorect
                source: "UI/customer/logorect.png"
                x: 0
                y: 0
                width: 240
                height: 100
                opacity: 1
            }
            Image {
                id: usericon
                source: "UI/customer/usericon.png"
                x: 16
                y: 111
                opacity: 1
            }
            Text {
                id: name
                x: 66
                y: 109
                opacity: 1
                font.bold: true
                text:Style.name
                width: 171
                height: 49
                horizontalAlignment: Text.AlignLeft
                elide: Text.ElideRight
                font.pointSize: 20
                wrapMode: Text.WordWrap

                color: "white"
                verticalAlignment: Text.AlignVCenter
            }
            Image {
                id: logo
                source: "UI/customer/logo.png"
                x: 35
                y: 20
                opacity: 1
            }
        }

        /*Time*/
        Item {
            x: 85
            y: 648
            Timer {
                interval: 1
                running: true
                repeat: true
                onTriggered: {
                    //sec = new Date().getSeconds()
                    mate = new Date().getMinutes()
                    hr = new Date().getHours()
                    mi = mate.toString();
                    h = hr.toString();

                    if(mi.length < 2)
                    {
                        mi = '0'+mi
                    }
                    if (h.length < 2)
                    {
                        h = '0'+h
                    }

                    time.text = h + ':' + mi // + ':' + sec.toString()
                }
            }

            Text {
                anchors.fill: parent
                id: time
                opacity: 1
                font.pixelSize: Style.dtfontsize
                font.bold: true
                color: "white"
            }
        }
        /*Date*/
        Item {
            x: 55
            y: 694

            Timer {
                interval: 1
                running: true
                repeat: true
                onTriggered: {
                    interval: 1
                    running: true
                    repeat: true

                    day = new Date().getDate()
                    month = new Date().getMonth() + 1
                    year = new Date().getFullYear()
                    d = day.toString()
                    m = month.toString()
                    yr = year.toString()
                    if (d.length < 2) {
                        d = '0' + d
                    }
                    if (m.length < 2) {
                        m = '0' + m
                    }

                    date.text = d + '/' + m + '/' + yr
                }
            }

            Text {
                id: date
                anchors.fill: parent
                opacity: 1
                font.pixelSize: Style.dtfontsize
                font.bold: true
                color: "white"
            }
        }
        Image
        {
            x: 76
            y: 544
            source:"UI/login/logout.png"

            MouseArea
            {
                width: 26
                height: 33
                cursorShape: Qt.PointingHandCursor
                onClicked:
                {
                    container.source = "login.qml"
                }
            }
        }

    }
