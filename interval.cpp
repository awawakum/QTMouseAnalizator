#include "interval.h"


IntervalDialog::IntervalDialog( QWidget* parent ) : QDialog( parent ) {
    this -> setWindowTitle("Пожалуйста, выберите временной интервал");
    QBoxLayout* layout = new QHBoxLayout;
    time_from = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    time_to = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    layout->addWidget( time_from );
    layout->addWidget( time_to );

    QPushButton* okBtn = new QPushButton( "OK" );
    connect( okBtn, SIGNAL( clicked() ), SLOT( accepted() ) );
    connect( okBtn, SIGNAL( clicked() ), SLOT( accept() ) );
    layout->addWidget( okBtn );

    QPushButton* cancelBtn = new QPushButton( "Cancel" );
    connect( cancelBtn, SIGNAL( clicked() ), SLOT( reject() ) );
    layout->addWidget( cancelBtn );

    connect(time_from, &QDateTimeEdit::dateTimeChanged, this, [this](){
        from = time_from->dateTime();
        emit changed_from(from);
    });

    connect(time_to, &QDateTimeEdit::dateTimeChanged, this, [this](){
        to = time_to->dateTime();
        emit changed_to(to);
    });

    setLayout( layout );
}


void IntervalDialog::accepted(){
}
