#ifndef SAVETHREAD_H
#define SAVETHREAD_H

#include <QObject>
#include <QThread>

class SaveThread : public QThread
{
public:
    SaveThread(QString string);
    ~SaveThread();
    void run();
private:
    QString data;
};

#endif // SAVETHREAD_H
