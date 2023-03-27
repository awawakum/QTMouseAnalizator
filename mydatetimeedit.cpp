#include "mydatetimeedit.h"

MyDateTimeEdit::MyDateTimeEdit(QDateTime QDT, QWidget *parent): QDateTimeEdit( parent )
{
    this->setDateTime(QDT);
}

void MyDateTimeEdit::set_datetime(QDateTime date)
{
    emit change_datetime(date);
}
