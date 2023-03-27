#ifndef MYDATETIMEEDIT_H
#define MYDATETIMEEDIT_H

#include <QDateTimeEdit>

class MyDateTimeEdit : public QDateTimeEdit
{
    Q_OBJECT
public:
    MyDateTimeEdit(QDateTime, QWidget* parent = 0);
public slots:
    void set_datetime(QDateTime);
signals:
    void change_datetime(QDateTime);
private:
    QDateTime datetime;
};

#endif // MYDATETIMEEDIT_H
