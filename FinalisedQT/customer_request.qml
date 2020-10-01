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
        id: center_box
        source: "UI/customer/center_box.png"
        x: 0
        y: 0
        width: 1116
        height: 718
        opacity: 1
    }
    TextArea {
        id: requestText
        x: 73
        y: 218
        width: 954
        height: 108
        font.pointSize: 18
        placeholderText: "Name of the item"
        placeholderTextColor: "lightgrey"
        clip: true
        wrapMode: "WordWrap"
    }
    Image {
        id: enter_items_you_would_like_to_see_in_the_store
        source: "UI/customer/enter_items_you_would_like_to_see_in_the_store.png"
        x: 73
        y: 130
        opacity: 1
    }
    Image {
        id: submit_but
        source: "UI/customer/submit_but.png"
        x: 931
        y: 613
        opacity: 1
        MouseArea {
            cursorShape: Qt.PointingHandCursor
            anchors.fill: parent
            onClicked: {
                rands.insertData(requestText.text)
                setQMLSources("customer_request.qml")
            }
        }
    }
    Image {
        id: submit_
        source: "UI/customer/submit_.png"
        x: 947
        y: 630
        opacity: 1
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.6600000262260437}
}
##^##*/
