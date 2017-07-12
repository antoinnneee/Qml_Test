import QtQuick 2.0

Flickable {
    id: flickable
    property int previewstate: 0
    anchors.fill: parent

    clip: true
    boundsBehavior: Flickable.DragOverBounds
    flickableDirection: Flickable.HorizontalFlick
    Flickable {
        id: f_title
        height: titre.contentHeight
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: bg_pic.width > bg_pic.height ? bg_pic.width * 0.25 : bg_pic.width * 0.20  ;

        anchors.left: parent.left
        anchors.leftMargin:  bg_pic.width > bg_pic.height ? bg_pic.width * 0.25 : bg_pic.width * 0.20  ;

        transform: Rotation {
            angle: -anchor.ang
            origin.x: width / 2
            origin.y: height / 2
            axis: "1,1,1"
        }

        Rectangle {
            id: bg_title
            opacity: 0.35
            color: "white"
            border.width: 2
            border.color: "black"
            radius: 5
            anchors.fill: parent
        }

        Text {
            id: titre
            text: anchor.titrearea
            clip: true
            anchors.fill: parent
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignJustify
            horizontalAlignment: Text.AlignJustify, Text.AlignHCenter
        }
    }


    Flickable {
        id: f_media
        height: bg_pic.width > bg_pic.height ? bg_pic.height * 0.19 :  bg_pic.height * 0.1
        anchors.right: parent.right
        anchors.rightMargin: 39
        anchors.left: parent.left
        anchors.leftMargin: 40
        anchors.top: f_title.bottom
        anchors.topMargin: 10
        rotation: anchor.ang
        Button {
            id: bplay
            height: parent.height
            width: height
            scale: 1
//                    anchors.horizontalCenterOffset: -64
            anchors.right: parent.horizontalCenter
            background: BorderImage {
                anchors.fill: parent
                source: anchor.bg_play
                border.left: 5; border.top: 5
                border.right: 5; border.bottom: 5
            }
        }

        Button {
            id: bstop
            height: parent.height
            width: height
            text: qsTr("")
            antialiasing: true
            scale: 1
//                    transformOrigin: Item.Center
//                    anchors.horizontalCenterOffset: parent.height/2
            anchors.left: parent.horizontalCenter
            background: BorderImage {
                anchors.fill: parent
                source: "qrc:/icone/STOP0"
                border.left: 5; border.top: 5
                border.right: 5; border.bottom: 5
            }
        }
    }
    Flickable {
        id: f_area
        anchors.top: f_media.bottom
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: bg_pic.width > bg_pic.height ? bg_pic.width * 0.08 : bg_pic.width * 0.04
        anchors.left: parent.left
        anchors.leftMargin: bg_pic.width > bg_pic.height ? bg_pic.width * 0.08 : bg_pic.width * 0.04
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        clip: true
        contentHeight: text_area.contentHeight + 3
        transform: Rotation {
            angle: -anchor.ang
            origin.x: width/2
            origin.y: height/2
            axis: "0,1,0"
        }
        Rectangle {
            id: bg_text
            opacity: 0.4
            color: "white"
            anchors.fill: parent
            border.width: 2
            border.color: "black"
            radius: 5
        }
        Text {
            id: text_area
            //                objectName: "textarea"
            text: anchor.textarea
//                    font.pointSize: 12
//                    fontSizeMode: Text.HorizontalFit
            textFormat: Text.AutoText
            renderType: Text.NativeRendering
//                    elide: Text.ElideNone
            anchors.right: parent.right
            anchors.rightMargin: 3
            anchors.left: parent.left
            anchors.leftMargin: 3
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            anchors.top: parent.top
            anchors.topMargin: 2
            wrapMode: Text.WordWrap
            color: "black"
        }
    }

}
