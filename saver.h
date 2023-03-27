#ifndef SAVER_H
#define SAVER_H

#include <QObject>

class Saver : public QObject
{
    Q_OBJECT
public:
    Saver(QObject* parent = 0);
    ~Saver();
signals:
    void finished();
public slots:
    void runSaving(QString);
private:
    QDateTime *now;
    QThread *thread;
};

#endif // SAVER_H
