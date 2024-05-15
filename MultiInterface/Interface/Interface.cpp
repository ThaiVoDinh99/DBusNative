#include "Interface.h"

Interface::Interface(const QString &serviceName, const QString &objectPath, const char *nameInterface, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(serviceName, objectPath, nameInterface, connection, parent)
{

}

Interface::~Interface() {

}


SubInterface::SubInterface(const QString &serviceName, const QString &objectPath, const char *nameInterface, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(serviceName, objectPath, nameInterface, connection, parent)
{

}

SubInterface::~SubInterface() {

}
