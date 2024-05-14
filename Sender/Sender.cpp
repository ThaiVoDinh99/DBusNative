#include "Sender.h"
#include <QDebug>

static DBusSender* instance = nullptr;

DBusSender::DBusSender(const QString& serviceName, const QString& pathObject, const QDBusConnection &connectionType, QObject* parent)
    : QDBusAbstractInterface(serviceName, pathObject, interfaceNameRegister(), connectionType, parent)
{

}

DBusSender::~DBusSender() {

}

DBusSender* DBusSender::initialized(QObject* parent) {
    if (instance == nullptr) {
        instance = new DBusSender("dbus.sender.object", "/test", QDBusConnection::sessionBus());
    }
    return instance;
} 

DBusSender& DBusSender::getInstance() {
    try {
        if (instance == nullptr) {
            throw 1;
        } else {
            return *instance;
        }
    }
    catch(int a) {
        qWarning() << "Need to initialize sender object";
    }
}

void DBusSender::changeText(QString newContent) {

    Q_UNUSED(newContent);

    if (!isValid()) {
        qWarning() << "Connect DBus Daemon fail";
        return;
    }

    QDBusPendingCall pcall = asyncCall("changeText");
    QDBusPendingCallWatcher* watcher = new QDBusPendingCallWatcher(pcall, this);

    QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this, [this](){
        qWarning() << "Trigger from sender to receiver";
    });
}
