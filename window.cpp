/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "widget.h"
#include "mylabel.h"
#include "history.h"
#include "interval.h"
#include "save.h"
#include "load.h"
#include "window.h"

#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include <QDebug>

Window::Window()
{
    this -> setWindowTitle(tr("Тестовое"));
    this -> setFixedSize(1240,680);
    this -> move(100,100);

    QLabel *time_from = new QLabel(this);
    QLabel *time_to = new QLabel(this);

    Widget *native = new Widget(this);
    MyLabel *nativeLabel = new MyLabel(this);
    HistoryLabel * hist_label = new HistoryLabel(this);

    QPushButton *select_interval = new QPushButton(this);
    SaveButton *save = new SaveButton(this);
    QPushButton *load = new QPushButton(this);

    select_interval -> setText("Выбрать интервал");
    load -> setText("Загрузить");
    save -> setText("Сохранить");

    hist_label->setSizePolicy(QSizePolicy::QSizePolicy::Maximum, QSizePolicy::Maximum);

    nativeLabel->setAlignment(Qt::AlignHCenter);

    connect(native, SIGNAL(move(QPoint)), nativeLabel, SLOT(set_text(QPoint)));

    IntervalDialog *interval_dialog = new IntervalDialog(this);
    LoadDialog *load_dialog = new LoadDialog(this);

    connect(select_interval, SIGNAL(clicked()), interval_dialog, SLOT(show()));
    connect(interval_dialog, SIGNAL(changed_from(QDateTime)), native, SLOT(set_time_from(QDateTime)));
    connect(interval_dialog, SIGNAL(changed_to(QDateTime)), native, SLOT(set_time_to(QDateTime)));
    connect(save, SIGNAL(clicked()), save, SLOT(on_click()));
    connect(interval_dialog, SIGNAL(accepted()), hist_label, SLOT(clear_field()));
    connect(hist_label, SIGNAL(vector_changed(QString)), save, SLOT(set_data(QString)));
    connect(load, SIGNAL(clicked()), load_dialog, SLOT(set_FPath()));

    connect(load, SIGNAL(clicked()), native, SLOT(set_time_now()));
    connect(save, SIGNAL(clicked()), native, SLOT(set_time_now()));

    connect(load_dialog, SIGNAL(load_vector(QVector<qp>)), native, SLOT(load_vec(QVector<qp>)));
    connect(interval_dialog, SIGNAL(accepted()), native, SLOT(clear()));
    connect(native, SIGNAL(changed(QVector<qp>)), hist_label, SLOT(set_text(QVector<qp>)));


    QScrollArea *scroll_area = new QScrollArea(this);

    QGridLayout *layout = new QGridLayout(this);

    scroll_area -> setWidget(hist_label);
    scroll_area -> setFixedSize(200,550);
    scroll_area -> setWidgetResizable(true);

    layout->addWidget(native, 0, 0);
    layout->addWidget(nativeLabel, 1, 0);
    layout->addWidget(time_from, 3, 0);
    layout->addWidget(time_to, 1, 1);
    layout->addWidget(select_interval, 2, 0);
    layout->addWidget(save, 2, 1);
    layout->addWidget(load, 3, 1);
    layout->addWidget(scroll_area, 0, 1);

    setLayout(layout);
}

