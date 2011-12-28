import QtQuick 1.0

Item {
    id: root
    property int itemSize: 64
    property int maxBarHeight: itemSize * 2
    height: itemSize
    width: (items * itemSize) + maxBarHeight/2

    Timer {
        id: timer
        interval: 200;
        running: false;
        repeat: false
        onTriggered: height = itemSize
    }

    Item {
        id: positioner // Center horizzontally the bottom bar
        width: (list.contentWidth < 2) ? itemSize : list.contentWidth
        height: parent.height
        anchors.centerIn: parent

        Rectangle {
            id: backgroundBar
            width: parent.width
            height: itemSize
            anchors.bottom: parent.bottom
            color: "white"
            opacity: 0.5
            radius: 5
        }

        ListView {
            id: list
            cacheBuffer: items
            orientation: ListView.Horizontal
            anchors.bottom: backgroundBar.bottom
            anchors.horizontalCenter: backgroundBar.Center
            width: parent.width
            model: dockbarModel
            delegate: DockbarItem {
                size: itemSize
                iconSource: "image://icons/" + model.modelData.icon
                appName: model.modelData.name
                onHasMouse: {
                    timer.running = !containsMouse
                    if (containsMouse){
                        root.height = maxBarHeight
                    }
                }
                onClicked: {
                    dockbarExt.removeClientFromDock(model.modelData.client);
                    root.height = itemSize
                }
            }
        }
    }
}
