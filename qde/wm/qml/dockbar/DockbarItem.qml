 import QtQuick 1.0

Rectangle {
    id: dockbaritem

    property int mScale: (ma.containsMouse) ? 2 : 1
    property int size: 64

    signal hasMouse;

    width: size * mScale
    height: width
    color: "black"
    radius: 5
    opacity: 0.1

    anchors.bottom: parent.bottom

    MouseArea {
        id: ma
        anchors.fill: parent
        hoverEnabled: true

        onContainsMouseChanged: {dockbaritem.hasMouse();}
    }

    Behavior on width {PropertyAnimation { duration: 200}}
}
