#include "clicklabel.h"
#include <QDebug>

clicklabel::clicklabel(QWidget * parent )
:QLabel(parent)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}

void clicklabel::slotClicked()
{
 //   qDebug()<<"Clicked";
}

void clicklabel::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
