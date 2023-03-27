#ifndef HISTORY_H
#define HISTORY_H

#include "widget.h"

#include <QObject>
#include <QWidget>

#include <QLabel>

class HistoryLabel : public QLabel
{
    Q_OBJECT
public:
    HistoryLabel(QWidget* parent);
    QString get_vector();
public slots:
    void set_text(QVector<qp>);
    void clear_field();
signals:
    void vector_changed(const QString);
};

#endif // HISTORY_H
