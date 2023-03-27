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

#include "string.h"
#include "string"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QPalette pl; //объект палитра необходим для заданимя фона окна
    pl.setColor(QPalette::Background, QColor(240, 248, 255)); //определить цвет
    this->setAutoFillBackground(true); //фон окна заливается автоматически
    this->setPalette(pl); //устанавливаем фон окна
    this->setMouseTracking(true); //отслеживаем движение мыши
    f = 0;
}

void Widget::load_vec(QVector <qp> vec)
{
    vcp = vec;

    qDebug() << "OPA";

    emit changed(vec);
}

void Widget::set_time_now()
{
    time_from = QDateTime::currentDateTime();
    time_to = QDateTime::currentDateTime();
}

void Widget::clear()
{
    QVector<qp> v;
    vcp = v;
    emit changed(v);
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setPen (QPen(Qt::gray, Qt::SolidLine)); //цвет и тип пера
    for (int i = 1; i < vcp.size(); ++i)
    {
        if(vcp[i-1].fl==1) continue; //от этой координаты не рисуем
        p.drawLine(vcp[i-1].pos.x(), vcp[i-1].pos.y(), vcp[i].pos.x(), vcp[i].pos.y());
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int from_to_now_msec = time_from.msecsTo(QDateTime::currentDateTime());
    int now_to_time_msec = QDateTime::currentDateTime().msecsTo(time_to);

    (from_to_now_msec >= 0 && now_to_time_msec > 0) ? f = 1 : f = 0;

    if (f==1){
        emit move(event->pos());
        this->pos = event -> pos(); //положение курсора мыши
        qp qp1;
        qp1.pos = this->pos;
        vcp.append(qp1); //добавили в массив для рисования
        emit changed(vcp);
        this->update();  //обновить экран
    }

}

void Widget::set_time_from(QDateTime from){
    time_from = from;
}

void Widget::set_time_to(QDateTime to){
    time_to = to;
}

QDateTime Widget::get_time_from(){
    return time_from;
}

QDateTime Widget::get_time_to(){
    return time_to;
}

std::string Widget::get_point_vector()
{
    std::string vector_info = "Cords vector: \n";

    for(int i =0; i<vcp.size(); i++){
        vector_info += "------------------------------";
        vector_info += "Pos x: " + std::to_string(vcp[i].pos.x()) + "\n";
        vector_info += "Pos y: " + std::to_string(vcp[i].pos.y()) + "\n";
    }
    return vector_info;
}
