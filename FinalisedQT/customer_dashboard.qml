import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import "."

Item {
    width: 1116
    height: 718
    signal setQMLSources(string path)
    Image {
        id: layer_0
        source: "UI/customer/layer_0.png"
        x: 0
        y: 0
        width: 1116
        height: 718
        opacity: 1
    }
    Image {
        id: center_box
        source: "UI/customer/center_box.png"
        x: 0
        y: 0
        width: 1116
        height: 718
        opacity: 1

        Text {
            id: element
            x: 397
            y: 123
            width: 322
            height: 19
            text: qsTr("Most Popular")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 33
        }
    }

    Item {
        id: searchrect
        x: 510
        y: 106
        opacity: 1

        TextField {
            x: -247
            y: -68

            width: 610
            height: 45
            text: qsTr("")
            font.family: "Ubuntu"
            opacity: 1
            wrapMode: Text.WordWrap
            font.pixelSize: 20
            color: "black"
            layer.enabled: true
            focus: true
            placeholderText: ("Search")
            onAccepted: {
                Style.searchitem = text
                setQMLSources("customer_search.qml")
            }
        }
    }

    Image {
        id: searchicon
        source: "UI/customer/searchicon.png"
        x: 225
        y: 44
        opacity: 1
    }
    JSONListModel{
        id:mostsold
        json:pd.mostSoldItems()
    }
    Rectangle {
        width: 312
        height: 217
        radius: 20
        id: box1
        color:"#f5ea18"
        x: 39
        y: 188
        opacity: 1
        Text{
            x:0
            y:40
            clip:true
            width: 290
            height: 100
            horizontalAlignment: Text.AlignHCenter
            elide: Text.ElideRight
            font.pointSize: 24
            wrapMode: Text.WordWrap
            Component.onCompleted: {
                text=mostsold.mo[0].NAME
            }
        }
        Text{
            x:115
            y:145
            font.pointSize: 19
            Component.onCompleted: {
                text="Rs. " + mostsold.mo[0].PRICE
            }
        }
    }
    Rectangle {
        width: 312
        height: 217
        radius: 20
        color: "#f21b1b"
        id: box4
        x: 39
        y: 462
        opacity: 1
        Text{
            x:0
            y:40
            clip:true
            width: 290
            height: 100
            horizontalAlignment: Text.AlignHCenter
            elide: Text.ElideRight
            font.pointSize: 24
            wrapMode: Text.WordWrap
            Component.onCompleted: {
                text=mostsold.mo[3].NAME
            }
        }
        Text{
            x:115
            y:145
            font.pointSize: 19
            Component.onCompleted: {
                text="Rs. " + mostsold.mo[3].PRICE
            }
        }
    }
    Rectangle {
        width: 312
        height: 217
        radius: 20
        color: "#34f21b"
        id: box2
        x: 409
        y: 188
        opacity: 1
        Text{
            x:0
            y:40
            clip:true
            width: 290
            height: 100
            horizontalAlignment: Text.AlignHCenter
            elide: Text.ElideRight
            font.pointSize: 24
            wrapMode: Text.WordWrap
            Component.onCompleted: {
                text=mostsold.mo[1].NAME
            }
        }
        Text{
            x:115
            y:145
            font.pointSize: 19
            Component.onCompleted: {
                text="Rs. " + mostsold.mo[1].PRICE
            }
        }
    }
    Rectangle {
        width: 312
        height: 217
        radius: 20
        id: box5
        color: "#1bdcf2"
        x: 409
        y: 462
        opacity: 1
        Text{
            x:0
            y:40
            clip:true
            width: 290
            height: 100
            horizontalAlignment: Text.AlignHCenter
            elide: Text.ElideRight
            font.pointSize: 24
            wrapMode: Text.WordWrap
            Component.onCompleted: {
                text=mostsold.mo[4].NAME
            }
        }
        Text{
            x:115
            y:145
            font.pointSize: 19
            Component.onCompleted: {
                text="Rs. " + mostsold.mo[4].PRICE
            }
        }
    }
    Rectangle {
        width: 312
        height: 217
        radius: 20
        color: "#f21bbc"
        id: box6
        x: 780
        y: 462
        opacity: 1
        Text{
            x:0
            y:40
            clip:true
            width: 290
            height: 100
            horizontalAlignment: Text.AlignHCenter
            elide: Text.ElideRight
            font.pointSize: 24
            wrapMode: Text.WordWrap
            Component.onCompleted: {
                text=mostsold.mo[5].NAME
            }
        }
        Text{
            x:115
            y:145
            font.pointSize: 19
            Component.onCompleted: {
                text="Rs. " + mostsold.mo[5].PRICE
            }
        }
    }
    Rectangle {
        width: 312
        height: 217
        radius: 20
        color: "#1b58f2"
        id: box3
        x: 780
        y: 188
        opacity: 1
        Text{
            x:0
            y:40
            clip:true
            width: 290
            height: 100
            horizontalAlignment: Text.AlignHCenter
            elide: Text.ElideRight
            font.pointSize: 24
            wrapMode: Text.WordWrap
            Component.onCompleted: {
                text=mostsold.mo[2].NAME
            }
        }
        Text{
            x:115
            y:145
            font.pointSize: 19
            Component.onCompleted: {
                text="Rs. " + mostsold.mo[2].PRICE
            }
        }
    }
}
