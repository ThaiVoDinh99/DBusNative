#include <QGuiApplication>
#include <QtQuick>
#include "Receiver.h"
#include <QQmlEngine>

int main(int argc, char** argv) {
    QGuiApplication app(argc, argv);
    DBusReceiver* object = new DBusReceiver();
    qmlRegisterSingletonInstance<DBusReceiver>("DBusReceiver.UI.ThaiVD", 1, 0, "Receiver", object);
    QQuickView view;
    view.setSource(QUrl("main.qml"));
    view.show();

    app.exec();
}
