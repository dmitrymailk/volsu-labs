
#include <QPainter>
#include <QPainterPath>
#include "renderarea.h"


//! [0]
RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{

}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    QPainter p(this); // ??????? ????? ?????? ????????????

    p.setRenderHint(QPainter::Antialiasing, true);

    p.setPen(QPen(Qt::black,0.5,Qt::SolidLine)); // ????????? ?????????

    int step = 20;
    for(int i=0; i < width(); i += step){
        p.drawLine(i, 0, i, height());

    }

    for(int i=0; i < height(); i += step){
        p.drawLine(0, i, width(), i);
    }

    p.setPen(QPen(Qt::black,1.5,Qt::SolidLine));

    int R = radius*step;
    int start_x = axisX;
    int start_y = axisY;
    float one_degree = PI/360;

    for(int i=0; i < 360*2; i += 1){
        float temp_rad = i * one_degree;
        p.drawPoint(cos(temp_rad)*R + start_x, sin(temp_rad)*R + start_y);
    }
}
