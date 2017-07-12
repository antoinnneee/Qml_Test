#ifndef ANDROID_TEXTAREA_H
#define ANDROID_TEXTAREA_H
#include <QTextBrowser>
#include <QGesture>
#include <QPainter>

class android_textarea : public QTextBrowser
{
    Q_OBJECT
public:
    android_textarea();
    android_textarea(QWidget * parent = 0 );
    ~android_textarea(){}


signals:

public slots:

protected:
//    bool    event(QEvent *event);
//    void paintEvent(QPaintEvent*);

private:
    bool gestureEvent(QGestureEvent *event);
    void swipeTriggered(QSwipeGesture *gesture);

};

#endif // ANDROID_TEXTAREA_H
