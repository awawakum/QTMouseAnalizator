#ifndef LOAD_H
#define LOAD_H


#include <QFileDialog>
#include <QVector>
#include <QDebug>
#include "widget.h"


class LoadDialog : public QFileDialog
{
    Q_OBJECT

public:
    LoadDialog(QWidget* parent = 0 );
    qp extractCords(const QString &s);

signals:
    void load_vector(QVector<qp>);

public slots:
    void set_FPath();

private:
    QString FPath;

};


#endif // LOAD_H
