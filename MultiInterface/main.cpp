#include "Interface.h"
#include <QGuiApplication>

int main(int argc, char** argv) {
    QGuiApplication app(argc, argv);

    QObject object;
    Provider* ipro = new Provider(&object);
    Adaptor* adap = new Adaptor(ipro);

    Interface* iface = new Interface("thai.vo.dinh", "/thaivd", "thai.vo.dinh", QDBusConnection::sessionBus(), nullptr);
    SubInterface* subiface = new SubInterface("thai.vo.dinh", "/thaivd", "thai.vo.dinh", QDBusConnection::sessionBus(), nullptr);

    iface->emitSignal();
    subiface->emitSignal();

    return app.exec();
}
