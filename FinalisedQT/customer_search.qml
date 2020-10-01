import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0
import "."

Item {
    width: 1116
    height: 718
    signal setQMLSources(string path)
    property var startoftext: 70
    property var startofheader: 50
    property var heightoftext:10
    property var fontsize:17
    property var separation: 100
    property string headercolor:"white"
    property string headerfont:"ariel"

    Image {
        id: center_box
        source: "UI/customer/center_box.png"
        x: -5
        y: 0
        width: 1119
        height: 718
        opacity: 1

        Rectangle {
            id: table
            x: 19
            y: 167
            width: 1081
            height: 486
            color: "#f5f5f5"
            radius: 5

        }
        DropShadow {
                anchors.fill: table
                horizontalOffset: 3
                verticalOffset: 3
                radius: 8.0
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                samples: 17
                color: "#80000000"
                source: table
        }
    }

    Rectangle {
        id: header
        x: 14
        y: 112
        width: 1081
        height: 42
        color: "#2d3142"
        opacity: 1


    }
    Item {
        id: doesitmatter
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill:header
        Text {
            x:startofheader
            y:heightoftext
            id: itemID_header
            text: "Item ID"
            color:headercolor
            font.pixelSize: fontsize
        }
        Text {
            x:startofheader+0.8*separation
            y:heightoftext
            id: itemName_header
            text: "Item Name"
            color:headercolor
            font.pixelSize: fontsize
        }
        Text {
            x:startofheader+3.9*separation
            y:heightoftext
            id: itemPrice_header
            text: "Price"
            color:headercolor
            font.pixelSize: fontsize
        }
        Text {
            x:startofheader+4.9*separation
            y:heightoftext
            id: itemDescription_header
            text: "Description"
            color:headercolor
            font.pixelSize: fontsize
        }
        Text{
            x:startofheader+7.3*separation
            y:heightoftext
            id: itemItemType_header
            text: "Type of Item"
            color:headercolor
            font.pixelSize: fontsize
        }
        Text{
            x:startofheader+8.7*separation
            y:heightoftext
            id: itemLocation_header
            text: "Location"
            color:headercolor
            font.pixelSize: fontsize
        }

    }

    Image {
        id: back
        source: "UI/customer//back.png"
        x: 0
        y: 8
        opacity: 1
        MouseArea{
            anchors.rightMargin: -6
            anchors.bottomMargin: -6
            anchors.leftMargin: -5
            anchors.topMargin: -6
            anchors.fill:parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {setQMLSources("customer_dashboard.qml")}

        }
    }

    Item {
        id: searchrect
        x: 510
        y: 106
        opacity: 1

        TextField {
            x: -248
            y: -67

            width: 610
            height: 45
            font.family: "Ubuntu"
            opacity: 1
            font.pixelSize: 20
            color: "black"
            text: Style.searchitem
            layer.enabled: true
            focus: true
            placeholderText: ("Search")
            onAccepted: {
                itemDetails.json = pd.retrieveData(text)
                Style.searchitem = text
            }
        }
    }

    JSONListModel{
        id: itemDetails
        json: pd.retrieveData(Style.searchitem)
    }
    Image {
        id: searchicon
        source: "UI/customer/searchicon.png"
        x: 220
        y: 51
        opacity: 1
        MouseArea {
            anchors.rightMargin: -8
            anchors.bottomMargin: 60
            anchors.leftMargin: 8
            anchors.topMargin: -60
            anchors.fill: parent
            onClicked: setQMLSources("customer_search.qml")
        }
    }
    ScrollView{
        x:14
        y:169
        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOff
        }
        clip: true
        width: 1081
        height: 494
    ListView{
        spacing: 10
        id: itemDetailModel
        model: itemDetails.model

        delegate: ItemDelegate{
            Rectangle
            {
                id:itemrectangle
                x: -11
                y:15
                height: 50
                width: 1105
                color: "#8ecae6"
                radius:2
                border.width: 0
                Text {
                    x:startoftext
                    y:10
                    id: itemID
                    text: model.S_NO
                    font.pixelSize: fontsize
                }
                Text {
                    x:startoftext+0.8*separation
                    y:10
                    id: itemName
                    text: model.NAME
                    font.pixelSize: fontsize
                }
                Text {
                    x:startoftext+3.8*separation
                    y:10
                    id: itemPrice
                    text: model.PRICE
                    font.pixelSize: fontsize
                }
                Text {
                    x:startoftext+4.8*separation
                    y:10
                    id: itemDescription
                    text: model.DESCRIPTION
                    font.pixelSize: fontsize
                }
                Text{
                    x:startoftext+7.3*separation
                    y:10
                    id: itemItemType
                    text: model.ITEM_TYPE
                    font.pixelSize: fontsize
                }
                Text{
                    x:startoftext+8.6*separation
                    y:10
                    id: itemLocation
                    text: model.LOCATION
                    font.pixelSize: fontsize
                }
            }
            DropShadow {
                    anchors.fill: itemrectangle
                    horizontalOffset: 3
                    verticalOffset: 3
                    radius: 8.0
                    anchors.rightMargin: -6
                    anchors.bottomMargin: 0
                    anchors.leftMargin: -5
                    anchors.topMargin: 0
                    samples: 17
                    color: "#80000000"
                    source: itemrectangle
            }


        }
    }
}
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}
}
##^##*/
