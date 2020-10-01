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
    Image {
        id: please_enter_the_your_complaints_suggestion
        source: "UI/customer/please_enter_the_your_complaints_suggestion.png"
        x: 248
        y: 84
        opacity: 1
    }
    Image {
        id: type_
        source: "UI/customer/type_.png"
        x: 95
        y: 157
        opacity: 1
    }
    ComboBox {
        id: suggest_type
        x: 191
        y: 142
        width: 201
        height: 48
        model: ['Employee Related', 'Product Complaints', 'Harassment', 'Other']
    }

    TextArea {
        id: suggestText
        x: 95
        y: 270
        width: 954
        height: 350
        font.pointSize: 18
        placeholderText: "Description"
        placeholderTextColor: "lightgrey"
        clip: true
        wrapMode: "WordWrap"
    }

    Image {
        id: submit_but
        source: "UI/customer/submit_but.png"
        x: 945
        y: 644
        opacity: 1

        MouseArea
        {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked:
            {
                rands.insertDatasu(suggestText.text, suggest_type.currentText)
                setQMLSources("customer_suggestion.qml")
            }
        }
    }
    Image {
        id: submit_
        source: "UI/customer/submit_.png"
        x: 961
        y: 661
        opacity: 1
    }
    Image {
        id: please_describe_
        source: "UI/customer/please_describe_.png"
        x: 95
        y: 218
        opacity: 1
    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.6600000262260437}
}
##^##*/
