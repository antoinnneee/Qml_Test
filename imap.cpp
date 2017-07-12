#include "imap.h"
#include "ui_imap.h"
#include "pov.h"
#include "ui_pov.h"
#include <QDebug>

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
    this->setObjectName("Pov");
    this->setStyleSheet("#Pov{border-image: url(:/new/index/picture/map_0.png) 0 0 0 0 strech strech;}");
}
void    IMap::on_pov_2_clicked()
{
    qDebug() << "pov_2 clicked";
    Pov *p;
    p = new Pov(20);
    p->show();
}
void    IMap::on_pov_3_clicked()
{
    qDebug() << "pov_3 clicked";
    Pov *p;
    p = new Pov();
    p->show();
}
