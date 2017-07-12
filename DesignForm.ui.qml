import QtQuick 2.4

Item {
    width: 400
    height: 400

    BorderImage {
        id: borderImage
        anchors.fill: parent
        source: "qrc:/qtquickplugin/images/template_image.png"

        Flickable {
            id: flickable
            anchors.fill: parent

            Flickable {
                id: flickable1
                anchors.right: parent.right
                anchors.rightMargin: 70
                anchors.left: parent.left
                anchors.leftMargin: 50
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 50
                anchors.top: parent.top
                anchors.topMargin: 50
            }
        }
    }
}
