#include "clicklabel.h"
#include <QDebug>
#include <QPainter>
#include <QPixmap>

clicklabel::clicklabel(QWidget * parent )
:QLabel(parent)
{
    m_ispush = 0;
    m_debug = 0;
    m_overlay = 1;
    m_brush = Qt::white;
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}

void clicklabel::slotClicked()
{
 //   qDebug()<<"Clicked";
}

void clicklabel::mouseReleaseEvent( QMouseEvent * event)
{
        m_ispush = 0;
        this->repaint();

}

void clicklabel::mousePressEvent ( QMouseEvent * event )
{
    m_ispush = 1;
    this->repaint();

    emit clicked();

}

void    clicklabel::setimage(QString image)
{
    m_image = QImage(image);
    this->repaint();
}

void    clicklabel::setoverlay(bool state, QBrush brush)
{
    m_overlay = state;
    m_brush = brush;
}

void clicklabel::paintEvent( QPaintEvent *)
{
    QPainter p(this);
    QPainterPath path;
    QRect newrect;

    if (!m_image.isNull())
        p.drawImage(rect(), m_image);
    if(m_ispush && m_overlay)
    {
        int deltaX ;
        int deltaY ;

        if (m_debug)
        {
            p.setPen(Qt::yellow);
            p.fillRect(rect(),Qt::yellow);
            p.setPen(Qt::blue);
            p.setOpacity(0.80);

            newrect.setRect(0, 0, rect().width() * 0.85, rect().height() * 0.85);
            path.addRoundedRect(newrect, 12, 17);
    //        path.moveTo(rect().width()*0.45,rect().height()*0.45 );

         //   p.scale(0.85, 0.85);
            int deltaX = rect().width() - newrect.width();
            int deltaY = rect().height() - newrect.height();

            // Just apply coordinates transformation to draw where we need.
            p.translate(deltaX / 2, deltaY / 2);
            p.fillPath(path, m_brush);

        }
        else
        {
            p.setOpacity(0.25);

            newrect.setRect(0, 0, rect().width() * 0.85, rect().height() * 0.85);
            path.addRoundedRect(newrect, 12, 17);
    //        path.moveTo(rect().width()*0.45,rect().height()*0.45 );

         //   p.scale(0.85, 0.85);
            deltaX = rect().width() - newrect.width();
            deltaY = rect().height() - newrect.height();

            // Just apply coordinates transformation to draw where we need.
            p.translate(deltaX / 2, deltaY / 2);
            p.fillPath(path, m_brush);

        }


//        p.drawPath(path);
    }
}

