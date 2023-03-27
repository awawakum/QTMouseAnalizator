#include "saver.h"

#include <QFile>
#include <QDebug>
#include <QDateTime>
#include <QCoreApplication>
#include <QThread>

Saver::Saver(QObject* parent)
{


}

Saver::~Saver()
{
    qDebug() << "Saver distructor";
}

void Saver::runSaving(QString data){
    qDebug() << "runSaving:" << QThread::currentThreadId();
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
    emit finished();
    this->~Saver();
}
