#include "imap.h"
#include "ui_imap.h"
#include "pov.h"
#include "ui_pov.h"
#include "ui_pov_container.h"
#include "pov_container.h"
#include <QDebug>
#include <QPainter>


# ifdef PLATFORM_AND
#  define ANDROID 1
# else
#    define ANDROID 0
# endif

IMap::IMap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IMap)
{
    ui->setupUi(this);
//    ui->pov_1->setimage(":/new/index/picture/info_1.png");
//    ui->pov_0->setimage(":/new/index/picture/info_0.png");
//    ui->pov_2->setimage(":/new/index/picture/info_2.png");
//    ui->pov_3->setimage(":/new/index/picture/info_3.png");

    m_p = new Pov_Container();

    connect(m_p, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
    this->setAttribute(Qt::WA_DeleteOnClose);
    emit resizeEvent(0);

}

IMap::~IMap()
{
    delete ui;
}

void IMap::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   int height = this->geometry().height();
   int width  = this->geometry().width();
   ui->gridLayoutWidget->setGeometry(0,0,width,height);
}

void    IMap::on_pov_0_clicked()
{
    qDebug() << "pov_0 clicked";
    Pov *p;
    p = new Pov();

    if (ANDROID)
        p->showFullScreen();
    else
        p->show();
}
void    IMap::on_pov_1_clicked()
{
    /*
    qDebug() << "pov_1 clicked";
    Pov *p;
    p = new Pov();
    p->show();
    */
//    this->setObjectName("Pov");
//    this->setStyleSheet("#Pov{border-image: url(:/new/index/picture/map_0.png) 0 0 0 0 strech strech;}");
    this->hide();
    m_p->show();

}
void    IMap::on_pov_2_clicked()
{
    qDebug() << "pov_2 clicked";
    Pov *p;
    p = new Pov();
    p->show();
}
void    IMap::on_pov_3_clicked()
{
    qDebug() << "pov_3 clicked";
    Pov *p;
    p = new Pov();
    p->show();
}

void IMap::paintEvent( QPaintEvent * )
{
    qDebug() << "repaint";
//    QPixmap  bg(":/new/index/picture/bg_test.png");
    QPainter p(this);
 //   p.drawPixmap( rect(), bg, bg.rect() );
//    p.drawImage(rect(), QImage(":/new/index/picture/map_0.png"));
}

