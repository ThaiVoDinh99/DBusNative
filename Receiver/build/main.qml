import QtQuick
import DBusReceiver.UI.ThaiVD 1.0

Rectangle {
    width: 500
    height: 300
    color: "gray"
    Text {
        anchors {
            top: parent.top
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
        }
        text: "RECEIVER"
        color: "black"
    }

    Rectangle {
        width: 200
        height: 100
        anchors.centerIn: parent
        Text {
            anchors.centerIn: parent
            text: Receiver.contentMessage
        }
    }
}
