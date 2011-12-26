import QtQuick 1.0

Rectangle {
    id: root
    property int itemSize: 64
    property int maxBarHeight: itemSize * 2
    property bool containsMouse : false

    color: "transparent"
    height: (containsMouse) ? maxBarHeight : itemSize
    width: rootWidth
    Behavior on height {PropertyAnimation { fromduration: 200}}
    Timer {
        interval: 500; running: true; repeat: true
        onTriggered: time.text = Date().toString()
    }

    Item {
        id: positioner // Center horizzontally the bottom bar
        width: list.contentWidth
        height: parent.height
        anchors.centerIn: parent

        Rectangle {
            id: backgroundBar
            width: list.contentWidth
            height: itemSize
            anchors.bottom: parent.bottom
            color: "white"
            opacity: 0.5
            radius: 5
        }

        ListView {
            id: list
            cacheBuffer: list.model.count //FIXME Show all items
            orientation: ListView.Horizontal
            anchors.bottom: backgroundBar.bottom
            anchors.horizontalCenter: backgroundBar.Center
            width: parent.width
            model: dockbarModel
            delegate: DockbarItem {
                size: itemSize
                iconSource: "image://icons/" + model.modelData.icon
                appName: model.modelData.name
                onHasMouse: root.containsMouse = containsMouse
                onClicked: dockbarExt.removeClientFromDock(model.modelData.client);
            }
        }
    }
}
