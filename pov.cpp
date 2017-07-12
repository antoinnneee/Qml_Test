#include "pov.h"
#include "ui_pov.h"
#include <QTimer>
#include <QStyle>
#include <QPainter>
#include <QRect>
#include <QDebug>


void Pov::changebg()
{
    QPixmap  bg(":/new/index/picture/bg_test.png");
    int height = this->geometry().height();
    int width  = this->geometry().width();
    ui->centralwidget->repaint();
}

Pov::Pov(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pov)
{
    ui->setupUi(this);

//  ===== init text area =====

    ui->text_area->setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas fermentum scelerisque nibh vel varius. Donec sollicitudin sem eget dolor placerat tristique. Sed commodo lacus sed diam lobortis facilisis.\n\n Nunc vehicula sodales varius. Suspendisse tortor odio, tristique pellentesque cursus sed, eleifend in justo.\n\n Morbi venenatis ullamcorper quam quis scelerisque. Aenean tempor laoreet rhoncus.\n Nullam lacus nibh, blandit eget venenatis ut, convallis id turpis. Aliquam iaculis ante ut odio consequat dictum. Cras eleifend et magna id iaculis. Mauris mi diam, porta non pulvinar sit amet, fermentum non nulla.\n\n\n Duis feugiat eget justo non suscipit. Nullam elementum, mauris ac lobortis ornare, urna justo pharetra ante, sed malesuada justo eros at nisl. Nulla aliquam lorem non sem porta, sit amet molestie urna faucibus.\n\n Suspendisse et dolor a sapien vehicula rutrum id sit amet tellus. Aenean in ipsum bibendum, euismod dolor ut, luctus nibh.Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n\n Maecenas fermentum scelerisque nibh vel varius. Donec sollicitudin sem eget dolor placerat tristique. Sed commodo lacus sed diam lobortis facilisis. Nunc vehicula sodales varius. Suspendisse tortor odio, tristique pellentesque cursus sed, eleifend in justo.\n\n Morbi venenatis ullamcorper quam quis scelerisque. Aenean tempor laoreet rhoncus. Nullam lacus nibh, blandit eget venenatis ut, convallis id turpis. Aliquam iaculis ante ut odio consequat dictum. Cras eleifend et magna id iaculis. Mauris mi diam, porta non pulvinar sit amet, fermentum non nulla. Duis feugiat eget justo non suscipit. Nullam elementum, mauris ac lobortis ornare, urna justo pharetra ante, sed malesuada justo eros at nisl. Nulla aliquam lorem non sem porta, sit amet molestie urna faucibus. Suspendisse et dolor a sapien vehicula rutrum id sit amet tellus. Aenean in ipsum bibendum, euismod dolor ut, luctus nibh.");
    QFont font = ui->text_area->font();
    font.setPointSize(16);
    ui->text_area->setFont(font);
//  ===== init bouton  =====

    ui->bplay->setimage(":/new/index/picture/play.png");
    ui->bstop->setimage(":/new/index/picture/stop_button.png");
    ui->backbutton->setimage(":/new/index/picture/backbut.png");


    ui->backbutton->setoverlay(1, QBrush(Qt::white, Qt::Dense4Pattern));
    ui->bplay->setoverlay(1, QBrush(Qt::white, Qt::Dense4Pattern));
    ui->bstop->setoverlay(1, QBrush(Qt::white, Qt::Dense2Pattern));

//  ==== init spacer ====

//    ui->spacer_UL0->;

    emit resizeEvent(0);
}

Pov::~Pov()
{
    delete ui;
}

void Pov::on_backButton_clicked()
{
    qDebug() << "backbutton";

    this->close();
}

void Pov::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   int height = this->geometry().height();
   int width  = this->geometry().width();
   ui->gridLayoutWidget->setGeometry(0,0,width,height);
   //ui->frame->setGeometry(0,0,width,height);
//   this->setStyleSheet("#Pov{border-image: url(:/new/index/picture/bg_test.png) 0 0 0 0 strech strech;}");
}

void Pov::paintEvent( QPaintEvent * )
{
    qDebug() << "repaint";
    QPixmap  bg(":/new/index/picture/bg_test.png");
    QPainter p(this);
 //   p.drawPixmap( rect(), bg, bg.rect() );
    p.drawImage(rect(), QImage(":/new/index/picture/bg_test.png"));
}
