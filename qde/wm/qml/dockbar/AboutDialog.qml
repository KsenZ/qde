import QtQuick 1.1

Item {
    id: root
    signal close();
    width: 400

    Component.onCompleted: {
       root.height = title.height + content.height + container.margins * 4
    }

    Rectangle {
        id: background
        anchors.fill: parent
        color: "black"
        opacity: 0.8
        radius: 2
    }

    Item {
        id: container
        property int margins : 5
        anchors.fill: parent

        Text {
            id: title
            width: root.width
            anchors.horizontalCenter: root.Center
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            text: "QDe"
            clip: true
            font.bold: true
            font.pixelSize: 22
        }

        Text {
            id: subtitle
            width: root.width
            anchors.horizontalCenter: root.Center
            anchors.top: title.bottom
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            text: "A Qt Desktop written during sleepless nights"
            wrapMode: Text.Wrap
            clip: true
            font.bold: true
        }

        Text {
            id: content
            width: root.width
            anchors.top: subtitle.bottom
            anchors.horizontalCenter: parent.Center
            anchors.margins: container.margins * 2
            horizontalAlignment: Text.AlignHCenter
            color: "gray"
            text: "Version 0.1 \n \n Night owl coders:\n Antonio Aloisio <gnuton@gnuton.org> \n \n Rised from Antico Deluxe ashes \n"
            wrapMode: Text.Wrap
            clip: true
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: root.close()
    }
}
