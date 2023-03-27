#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    MyLabel(QWidget* parent);

public slots:
    void set_text(const QPoint);

};

#endif // MYLABEL_H
