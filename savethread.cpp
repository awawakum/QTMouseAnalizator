#include "savethread.h"

#include <QDateTime>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <QThread>

SaveThread::SaveThread(QString string)
{
    data = string;
}

SaveThread::~SaveThread()
{

}


void SaveThread::run()
{
    qDebug() << QThread::currentThreadId();
    QDateTime date = QDateTime::currentDateTime();
    date.setTimeSpec(Qt::UTC);
    QString proj_dir = QCoreApplication::applicationDirPath().replace("/", "\\");
    QString filename =  proj_dir + "\\" + date.toString("dd-MM-yyyy hh-mm-ss") + ".txt";
    qDebug() << filename;
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        file.write(data.toUtf8());
    }
    file.close();
}
