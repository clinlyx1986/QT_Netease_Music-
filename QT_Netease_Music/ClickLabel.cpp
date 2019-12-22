#include "ClickLabel.h"
#include <QtDebug>

ClickLabel::ClickLabel(QWidget *parent)
    : QLabel (parent)
{

}

ClickLabel::~ClickLabel()
{

}

void ClickLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        emit clicked();

    qDebug() << "label clicked.";
    QLabel::mousePressEvent(event);
}
