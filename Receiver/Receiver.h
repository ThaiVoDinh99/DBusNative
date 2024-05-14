#ifndef RECEIVER_H
#define RECEIVER_H

#include <QDBusAbstractAdaptor>
#include <QObject>
#include <QString>

class DBusReceiver : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString contentMessage READ contentMessage WRITE setContentMessage NOTIFY onContentMessageChanged FINAL)
public:
    DBusReceiver(QObject* parent = nullptr);
    ~DBusReceiver();


    QString contentMessage() const;
    void setContentMessage(const QString &newContentMessage);

signals:
    void onContentMessageChanged();
private:
    QString m_contentMessage = "ThaiVD";
};

class DBusReceiverAdapter : public QDBusAbstractAdaptor {
    Q_CLASSINFO("D-Bus Interface", "thai.vo.dinh")
    Q_OBJECT
public:
    ~DBusReceiverAdapter();

    static DBusReceiverAdapter* initialize(QObject* parent = nullptr);
    static DBusReceiverAdapter& getInstance();

    inline DBusReceiver* parent() {
        DBusReceiver* object = qobject_cast<DBusReceiver*>(QObject::parent());
        return object;
    }

public slots:
    void changeText() {
        qWarning() << "HAHAHA";
        parent()->setContentMessage("newContent");
    }
private:
    explicit DBusReceiverAdapter(QObject* parent = nullptr);
};

#endif //RECEIVER_H
