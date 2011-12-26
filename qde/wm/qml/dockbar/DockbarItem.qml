 import QtQuick 1.0

Rectangle {
    id: dockbaritem

    property int mScale: (ma.containsMouse) ? 2 : 1
    property int size: 64
    property string iconSource : ""
    property string appName : ""

    signal hasMouse(bool containsMouse);
    signal clicked;

    width: size * mScale
    height: width
    color: "transparent"
    radius: 5

    anchors.bottom: parent.bottom

    Image {
        anchors.fill: parent
        source: dockbaritem.iconSource
    }
    /*
    Text {
        color: "white"
        text: dockbaritem.appName
    }
    */
    MouseArea {
        id: ma
        anchors.fill: parent
        hoverEnabled: true
        onClicked: { dockbaritem.clicked(); }
        onContainsMouseChanged: { dockbaritem.hasMouse(ma.containsMouse); }
    }

    Behavior on width {PropertyAnimation { duration: 200}}
}
