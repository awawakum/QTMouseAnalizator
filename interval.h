#ifndef INTERVAL_H
#define INTERVAL_H


#include <QDialog>
#include <QDateTime>
#include <QPushButton>
#include <QBoxLayout>
#include <QDebug>
#include <QAction>
#include <QDateTimeEdit>


class IntervalDialog : public QDialog {
    Q_OBJECT

public:
    IntervalDialog( QWidget* parent = 0 );

    QString getInput() const;

signals:
    void applied();
    void changed_from(QDateTime);
    void changed_to(QDateTime);

public slots:
    void accepted();

private:
    QDateTimeEdit *time_from;
    QDateTimeEdit *time_to;
    QDateTime from;
    QDateTime to;

};


#endif // INTERVAL_H
