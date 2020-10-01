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
    property string search: ""
    property var startoftext: 70
    property var startofheader: 50
    property var heightoftext:10
    property var separation: 100
    property string headercolor:"#000000"
    property string headerfont:"ariel"
    property var fontsize: 17

    Image {
        id: center_box
        source: "UI/owner/center_box.png"
        x: -5
        y: 0
        width: 1119
        height: 718
        opacity: 1



        Rectangle {
            id: table
            x: 24
            y: 171
            width: 1081
            height: 473
            color: "#f5f5f5"
            radius: 5

        }
        DropShadow {
                anchors.fill: table
                horizontalOffset: 3
                verticalOffset: 3
                radius: 8.0
                anchors.rightMargin: 0
                anchors.bottomMargin: -7
                anchors.leftMargin: 0
                anchors.topMargin: 0
                samples: 17
                color: "#80000000"
                source: table
        }
    }

    Rectangle {
        id: header
        x: 19
        y: 112
        width: 1081
        height: 42
        color: "#57608c"
        opacity: 0.2

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
            x:startofheader+1*separation
            y:heightoftext
            id: itemName_header
            text: "Requested Items"
            color:headercolor
            font.pixelSize: fontsize
        }
    }

    Item {
        id: searchrect
        x: 510
        y: 106
        opacity: 1

        TextField {
            x: -232
            y: -85

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
                itemDetails.json = rands.retrieveDataItemRequest("request_item")
                //search = text
            }
        }
    }


    JSONListModel{
        id: itemDetails
        json: rands.retrieveDataItemRequest("request_item")
    }
    /*Image {
        id: searchicon
        source: "UI/owner/searchicon.png"
        x: 202
        y: 92
        opacity: 1
        MouseArea {
            anchors.fill: parent
            onClicked: setQMLSources("suggestion.qml")
        }
    }*/

    ScrollView{
        id: request_items
    x:19
    y:169
    ScrollBar.vertical: ScrollBar {
        policy: ScrollBar.AlwaysOff
    }
    clip: true
    width: 1081
    height: 477
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
                width: 1100
                color: "#4F5D75"
                radius:5
                clip:true

                Text {
                    x:startoftext+0.1*separation
                    y:10
                    id: itemID
                    text: model.S_NO
                    color: "white"
                    font.pixelSize: fontsize
                }
                Text {
                    x:startoftext+1*separation
                    y:10
                    id: itemName
                    color: "white"
                    text: model.REQUEST_ITEM
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


