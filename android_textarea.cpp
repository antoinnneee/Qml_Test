#include "android_textarea.h"
#include <QGesture>
#include <QDebug>
#include <QtWidgets>
#include <QPainter>

android_textarea::android_textarea(QWidget * parent )
:QTextBrowser(parent)
{

//    grabGesture(Qt::SwipeGesture);

}

bool android_textarea::gestureEvent(QGestureEvent *event)
{
//    if (android_textarea::verbose)
        qDebug() << "gestureEvent():" << event->gestures().size();
    if (QGesture *swipe = event->gesture(Qt::SwipeGesture))
        swipeTriggered(static_cast<QSwipeGesture *>(swipe));
//    else if (QGesture *pan = event->gesture(Qt::PanGesture))
//        panTriggered(static_cast<QPanGesture *>(pan));
//    if (QGesture *pinch = event->gesture(Qt::PinchGesture))
//        pinchTriggered(static_cast<QPinchGesture *>(pinch));
    return true;
}

void android_textarea::swipeTriggered(QSwipeGesture *gesture)
{
    if (gesture->state() == Qt::GestureFinished)
    {
        if (gesture->verticalDirection() == QSwipeGesture::Up)
        {
                qDebug() << "swipeTriggered(): swipe to up";
        }
        else
        {
                qDebug() << "swipeTriggered(): swipe to other";
        }
     //   update();
    }
}


