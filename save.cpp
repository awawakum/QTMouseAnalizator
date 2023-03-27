#include "save.h"

SaveButton::SaveButton( QWidget* parent ) : QPushButton( parent )
{

}

void SaveButton::set_data(QString string)
{
    data = string;
}

void SaveButton::on_click()
{
    qDebug() << "on_click threadID: " <<QThread::currentThreadId();

    Saver* saver = new Saver(this);
    QThread* thread = new QThread(this);

    connect(this, SIGNAL(saving(QString)), saver, SLOT(runSaving(QString)));

    connect(this, SIGNAL(destroyed()), thread, SLOT(quit()));
    connect(saver, SIGNAL(finished()), thread, SLOT(quit()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    connect(thread, &QThread::finished, this, [](){
        qDebug() << "Thread is finished!";
    });

    saver -> moveToThread(thread);
    thread->start();
    emit saving(data);
 }
