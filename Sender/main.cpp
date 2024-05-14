#include <QGuiApplication>
#include <QtQuick>
#include "Sender.h"
#include <QQmlEngine>

int main(int argc, char** argv) {
    QGuiApplication app(argc, argv);
    QObject qobj;
    DBusSender::initialized(&qobj);
    DBusSender* object = &DBusSender::getInstance();
    qmlRegisterSingletonInstance<DBusSender>("DBusSender.UI.ThaiVD", 1, 0, "Sender", object);
    QQuickView view;
    view.setSource(QUrl("main.qml"));
    view.show();

    app.exec();
}
