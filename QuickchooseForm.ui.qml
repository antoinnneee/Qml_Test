import QtQuick 2.7
import QtQuick.Controls 2.1
import Ancre 4.2

Item {
    id: item1
    width: 400
    height: 650


//    property alias myModel: myModel
    property alias listView1 : listView1

    Rectangle {
        id: bgrect
        color: "#605b58"
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#3d3835";
            }
            GradientStop {
                position: 0.45;
                color: "#53463f";
            }
            GradientStop {
                position: 0.55;
                color: "#4b3d36";
            }
            GradientStop {
                position: 1.00;
                color: "#3d3835";
            }
        }
        opacity: 1
        anchors.fill: parent
    }

//    property alias itclick: itclick
//    signal clicked (MouseArea itclick)


    ListView {
        id: listView1
        highlightRangeMode: ListView.ApplyRange
        anchors.right: parent.right
        anchors.rightMargin: bgrect.width * 0.2
        anchors.left: parent.left
        anchors.leftMargin: bgrect.width * 0.2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: bgrect.height * 0.1
        anchors.top: parent.top
        anchors.topMargin: bgrect.height * 0.1
        clip: true
        model: myModel
        delegate: Rectangle {
            width: parent.width
            height: listView1.height / 6.15
            color: "#cc4582b5"
            gradient: Gradient {
                GradientStop {
                    position: 0.00;
                    color: "#add8e6";
                }
                GradientStop {
                    position: 0.39;
                    color: "#d6eee9";
                }
                GradientStop {
                    position: 0.60;
                    color: "#d6eef9";
                }
                GradientStop {
                    position: 1.00;
                    color: "#ffffff";
                }
            }
            border.width: 1
            border.color: "black"
            radius: 10

//                property int index: val
            Text {
                text: modelData
                property int index: listView1.count
                clip: true
                anchors.fill: parent
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                font.pointSize: 14
                renderType: Text.QtRendering
                fontSizeMode: Text.Fit
                font.family: "MS Shell Dlg 2"
                font.bold: true
                verticalAlignment: Text.AlignJustify, Text.AlignVCenter
                horizontalAlignment: Text.AlignJustify, Text.AlignHCenter
                Rectangle {
                    MouseArea {
                        id: maItem
                        anchors.fill: parent
//                            color: "transparent"
                        onClicked: {
                           anchor.itemclick(index);
                        }
                    }
                    width: listView1.width
                    height: listView1.height / 6.15
                    opacity: 0
                    border.width: 1
                    border.color: "black"
                    radius: 10

                }
                Rectangle {
                    width: listView1.width
                    height: listView1.height / 6.15
                    opacity: 1
                    color: "transparent"
                    border.width: 1
                    border.color: "black"
                    radius: 10
                }
            }

        }
    }
//    ProgressBar {
//        id: progressBar
//        rotation: 90

//        //        anchors.left: parent.top
//        anchors.right: parent.right
//        anchors.rightMargin: parent.width * 0.1
//        anchors.verticalCenter: parent.verticalCenter

//        anchors.left: parent.left
//        anchors.leftMargin: parent.width * 0.7
//        width: parent.height
//        height: parent.height
////        anchors.top: parent.top
////        anchors.topMargin: bgrect.height * 0.1

////        anchors.bottom: parent.bottom
////        anchors.bottomMargin: bgrect.height * 0.1

////        anchors.top: parent.top

//        value: 0.5
//    }
}
