import QtQuick 1.0

Item {
    id: root
    property int itemSize: 64
    property int maxBarHeight: itemSize * 2
    state: "normal"

    function fullscreen(b) {
        root.state = (b) ? "fullscreen" : "normal"
    }

    states: [
        State {
            name: "fullscreen"
            PropertyChanges {
                target: root
                height: screenHeight
            }
            PropertyChanges {
                target: root
                width: screenWidth
            }
        },
        State {
            name: "normal"
            PropertyChanges {
                target: root
                height: itemSize
            }
            PropertyChanges {
                target: root
                width: (list.count * itemSize) + maxBarHeight/2
            }
        }
    ]

    Rectangle {
       id: rootBackground
       visible: (root.state == "fullscreen")
       opacity: 0.2
       color: "black"
       anchors.fill: parent
    }

    Timer {
        id: rootItemHeightAnimTimer
        interval: 200;
        running: false;
        repeat: false
        onTriggered: height = itemSize
    }

    // Dialog
    Item {
       id: dialog
       anchors.fill: parent
       visible: false
       MouseArea {
           anchors.fill: parent
           onClicked: dialog.hideDialog();
       }
       /*
       Connections {
            target: dockbarExt
            onShowAboutDialog: dialog.showDialog();
       }*/

       function showDialog() {
           console.log("SHOW DIALOG")
           root.fullscreen(true);
           dialog.visible = true

       }
       function hideDialog() {
           console.log("HIDE DIALOG")
           root.fullscreen(false);
           dialog.visible = false
       }
    }

    // Dockbar
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

            MouseArea {
                anchors.fill: parent
                onClicked: { dialog.showDialog() }
            }
        }

        ListView {
            id: list
            orientation: ListView.Horizontal
            anchors.bottom: backgroundBar.bottom
            anchors.horizontalCenter: backgroundBar.Center
            width: parent.width
            model: dockbarModel

            delegate: DockbarItem {
                size: itemSize
                iconSource: "image://icons/" + model.icon
                appName: model.appname
                onHasMouse: {
                    rootItemHeightAnimTimer.running = !containsMouse
                    if (containsMouse){
                        root.height = maxBarHeight
                    }
                }

                onClicked:{
                    if (removeItemTimer.running) return;
                    removeItemTimer.itemToRemove = model.client;
                    removeItemTimer.start();
                }
            }

            // Timer ensures that items are destroyed after that their mouse release methods are executed
            Timer {
                property variant itemToRemove: 0
                id: removeItemTimer
                interval: 10
                repeat: false
                triggeredOnStart:false

                onTriggered: {
                    if (!itemToRemove) return;
                    dockbarExt.removeClientFromDock(itemToRemove);
                    root.height = itemSize;
                    itemToRemove = 0;
                }
            }

        }
    }
}
