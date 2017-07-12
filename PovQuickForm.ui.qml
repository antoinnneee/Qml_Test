import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import Ancre 4.2
import QtGraphicalEffects 1.0

Item {
    id: item1
    width: 540
    height: 960
    property alias flickable: flickable
    property alias bg_title: bg_title
    property alias titre: titre
    property alias f_area: f_area
    property alias bplay: bplay
    property alias bstop: bstop
//    property alias fade_anim: fade_anim

//    property alias cxR: cxR
//    property alias cxL: cxL


    transform: Rotation {
        angle: 0
        origin.x: width/2
        origin.y: height/2
        axis: "0,1,0"
    }


        Image {
        id: bg_pic
        anchors.fill: parent
        source: anchor.bg

        Image {
            id: l_arrow
            source: "qrc:/icone/LARROW1"
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            height: bg_pic.width > bg_pic.height ? parent.height * 0.4 : parent.height * 0.27
            width: height
            transform: Translate { x: anchor.l_ar_x }
        }
        Image {
            id: r_arrow
            source: "qrc:/icone/RARROW1"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            height: bg_pic.width > bg_pic.height ? parent.height * 0.4 : parent.height * 0.27
            width: height
            transform: Translate { x: anchor.r_ar_x }
        }
        // here

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


    }
    GaussianBlur {
        visible: anchor.gauss
        anchors.fill: parent
        source: bg_pic
        radius: 2
        samples: 5
    }
    Button {
        id: button
        height: bg_pic.width > bg_pic.height ? bg_pic.height * 0.2 :  bg_pic.height * 0.1
        width: height
        text: qsTr("")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -width * 0.2
        anchors.left: parent.left
        anchors.leftMargin: 0
        background: BorderImage {
            id: backbut
            opacity: 0.65
            anchors.fill: parent
            source: "qrc:/icone/BACK1"
            border.left: 5; border.top: 5
            border.right: 5; border.bottom: 5
        }
    }

    property alias button: button
    signal clicked (Button button)

}
