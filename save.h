#ifndef SAVE_H
#define SAVE_H


#include <QPushButton>
#include "history.h"
#include "saver.h"


class SaveButton : public QPushButton
{
    Q_OBJECT
public:
    SaveButton(QWidget* parent = 0 );

signals:
    void saving(QString);

public slots:
    void on_click();
    void set_data(QString);

private:
    QDateTime *now;
    QString data;
};


#endif // SAVE_H
