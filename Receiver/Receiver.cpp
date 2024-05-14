#include "Receiver.h"
#include <QDBusConnection>
#include <QDebug>

static DBusReceiverAdapter* instance = nullptr;

DBusReceiverAdapter::DBusReceiverAdapter(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    setAutoRelaySignals(true);
    QDBusConnection::sessionBus().registerObject("/test", "thai.vo.dinh", parent);
    QDBusConnection::sessionBus().registerService("dbus.sender.object");
}

DBusReceiverAdapter::~DBusReceiverAdapter() {

}

DBusReceiverAdapter* DBusReceiverAdapter::initialize(QObject* parent) {
    if (instance == nullptr) {
        instance = new DBusReceiverAdapter(parent);
    }
    return instance;
}

DBusReceiverAdapter& DBusReceiverAdapter::getInstance() {
    try {
        if (instance == nullptr) {
            throw 1;
        } else {
            return *instance;
        }
    }
    catch (int a) {
        qWarning() << "Need to nitialize DBusReceiverAdapter instance";
    }
}

// ====================================================

DBusReceiver::DBusReceiver(QObject *parent)
    : QObject(parent)
{
    DBusReceiverAdapter::initialize(this);
}

DBusReceiver::~DBusReceiver() {

}

QString DBusReceiver::contentMessage() const
{
    return m_contentMessage;
}

void DBusReceiver::setContentMessage(const QString &newContentMessage)
{
    if (m_contentMessage == newContentMessage)
        return;
    m_contentMessage = newContentMessage;
    emit onContentMessageChanged();
}
