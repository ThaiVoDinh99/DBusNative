#ifndef SENDER_H
#define SENDER_H

#include <QDBusAbstractInterface>
#include <QObject>
#include <QString>

class DBusSender : public QDBusAbstractInterface {
    Q_OBJECT
public:
    ~DBusSender();

    // Service Name to register to DBus Daemon
    inline static const char* interfaceNameRegister() {
        return "thai.vo.dinh";
    }

    static DBusSender* initialized(QObject* parent = nullptr);
    static DBusSender& getInstance();

    Q_INVOKABLE void changeText(QString newContent);

private:
    explicit DBusSender(const QString& serviceName, const QString& pathObject, const QDBusConnection &connectionType, QObject* parent = nullptr);
};

#endif //SENDER_H
