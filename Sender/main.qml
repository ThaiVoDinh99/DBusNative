import QtQuick
import DBusSender.UI.ThaiVD 1.0

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
        width: 100
        height: 100
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 20
        }
        Text {
            anchors.centerIn: parent
            text: "1"
            color: "black"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                Sender.changeText("ThaiVD")
            }
        }
    }
    Rectangle {
        width: 100
        height: 100
        anchors {
            verticalCenter: parent.verticalCenter
            right: parent.right
            rightMargin: 20
        }
        Text {
            anchors.centerIn: parent
            text: "2"
            color: "black"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Sender.changeText("QuocVD")
            }
        }
    }
}
