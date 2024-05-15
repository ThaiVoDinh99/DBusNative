#include <QDBusAbstractAdaptor>
#include <QDBusAbstractInterface>
#include <QObject>


class SubInterface : public QDBusAbstractInterface {
    Q_OBJECT
public:
    explicit SubInterface(const QString& serviceName, const QString& objectPath, const char* nameInterface, const QDBusConnection& connection, QObject* parent = nullptr);
    virtual ~SubInterface();
public slots:

    void emitSignal() {

        if (!isValid()) {
            qWarning() << "Connect fail here";
            return;
        }

        QDBusPendingCall pcall = asyncCall("handleMessage");
        QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(pcall, this);

        QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this, [this](){

        });
    }
};

class Interface : public QDBusAbstractInterface {
    Q_OBJECT
public:
    explicit Interface(const QString& serviceName, const QString& objectPath, const char* nameInterface, const QDBusConnection& connection, QObject* parent = nullptr);
    virtual ~Interface();
public slots:

    void emitSignal() {

        if (!isValid()) {
            qWarning() << "Connect fail here";
            return;
        }

        QDBusPendingCall pcall = asyncCall("handleMessage");
        QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(pcall, this);

        QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this, [this](){

        });
    }
};



class Provider : public QObject {
    Q_OBJECT
public:
    Provider(QObject* parent = nullptr) : QObject(parent)
    {
    }
public slots:
    void showMessage() {
        qWarning() << "Thai Dep Trai day ......";
    }
};

class Adaptor : public QDBusAbstractAdaptor {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "thai.vo.dinh")
public:
    Adaptor(QObject* parent = nullptr) : QDBusAbstractAdaptor(parent)
    {
        setAutoRelaySignals(true);
        QDBusConnection::sessionBus().registerObject("/thaivd", "thai.vo.dinh", parent);
        QDBusConnection::sessionBus().registerService("thai.vo.dinh");
    }

public slots:
    void handleMessage() {
        Provider* object = qobject_cast<Provider*>(QObject::parent());
        object->showMessage();
    }
};
