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



#include <QPainter>
#include <QPainterPath>
#include "renderarea.h"


//! [0]
RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = Ellipse;
    antialiased = false;

    // generate positions
    int min_x = 0;
    int min_y = -20;

    int max_x = 200;
    int max_y = 80;

    int x = random_generator(min_x, max_x);
    int y = random_generator(min_y, max_y);
    for (int i = 0; i < 3; i++) {
            x = random_generator(min_x, max_x);
            y = random_generator(min_y, max_y);

            std::vector<int> temp;
            temp.push_back(x);
            temp.push_back(y);

            positions.push_back(temp);
    }


}
//! [0]

//! [1]
QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}
//! [1]

//! [2]
QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}
//! [2]

//! [3]
void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}
//! [3]

//! [4]
//void RenderArea::setPen(const QPen &pen)
//{
//    this->pen = pen;
//    update();
//}
//! [4]

//! [5]
void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::setBrush(QBrush &brush)
{
    this->brush = brush;
    update();
}
//! [5]

//! [6]
void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}
//! [6]

//! [7]
void RenderArea::setImage()
{
    imagePath = QFileDialog::getOpenFileName(this,
           tr("Add image to background"), "",
           tr("Image (*.png, *.jpg)"));
    update();
}

void RenderArea::saveImage()
{
    imagePathSave = QFileDialog::getSaveFileName(this,
           tr("Save background image"), "",
           tr("Image (*.png, *.jpg)"));

    QPixmap pixmap(width(), height());
    render(&pixmap, QPoint());
    pixmap.save(imagePathSave);
    update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    QRect rect(10, 20, 60, 60);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

    if(imagePath.length() > 0){
        QImage img(imagePath);
        img = img.scaled(width(), height());
        painter.drawImage(0, 0, img);
    }

    for (int i = 0; i < 3; i++) {
            painter.save();
            int x = positions[i][0];
            int y = positions[i][1];
            painter.translate(x, y);

            switch (shape) {
            case Ellipse:
                painter.drawEllipse(rect);
                break;
            }

            painter.restore();
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(1,1,width()-5, height()-5,3,3);
}
//! [13]

int RenderArea::random_generator(int start, int end) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end); // define the range
    return distr(gen);
}
