#include "pov.h"
#include "ui_pov.h"
#include <QTimer>
#include <QStyle>
#include <QPainter>
#include <QRect>
#include <QDebug>
#include <QMediaPlayer>


void Pov::changebg()
{
 //   QStyle posty;

//    ui->centralwidget->setObjectName("ov");
 //   ui->frame->setStyleSheet("QWidget#centralwidget {border-image: url(:/new/index/picture/bg_test.png) 0 0 0 0 strech strech;}");
    QPixmap  bg(":/new/index/picture/bg_test.png");
//    QPainter p(this);
    int height = this->geometry().height();
    int width  = this->geometry().width();
    ui->centralwidget->repaint();
//    p.drawPixmap( QRect(0, 0, width, height), bg, bg.rect() );
}

Pov::Pov(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pov)
{
    ui->setupUi(this);
    ui->text_area->setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas fermentum scelerisque nibh vel varius. Donec sollicitudin sem eget dolor placerat tristique. Sed commodo lacus sed diam lobortis facilisis. Nunc vehicula sodales varius. Suspendisse tortor odio, tristique pellentesque cursus sed, eleifend in justo. Morbi venenatis ullamcorper quam quis scelerisque. Aenean tempor laoreet rhoncus. Nullam lacus nibh, blandit eget venenatis ut, convallis id turpis. Aliquam iaculis ante ut odio consequat dictum. Cras eleifend et magna id iaculis. Mauris mi diam, porta non pulvinar sit amet, fermentum non nulla. Duis feugiat eget justo non suscipit. Nullam elementum, mauris ac lobortis ornare, urna justo pharetra ante, sed malesuada justo eros at nisl. Nulla aliquam lorem non sem porta, sit amet molestie urna faucibus. Suspendisse et dolor a sapien vehicula rutrum id sit amet tellus. Aenean in ipsum bibendum, euismod dolor ut, luctus nibh.");
    //set font
    QFont font = ui->text_area->font();
    font.setPointSize(16);
//    font.setBold(true);
    ui->text_area->setFont(font);
//    QTimer::singleShot(100, this, SLOT(changebg));
    emit resizeEvent(0);
}

Pov::Pov(int index, QWidget *parent) :
    m_id(index),QMainWindow(parent),
    ui(new Ui::Pov)
{
    ui->setupUi(this);
    ui->label_3->setText(QString::number(m_id));
    ui->text_area->setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas fermentum scelerisque nibh vel varius. Donec sollicitudin sem eget dolor placerat tristique. Sed commodo lacus sed diam lobortis facilisis. Nunc vehicula sodales varius. Suspendisse tortor odio, tristique pellentesque cursus sed, eleifend in justo. Morbi venenatis ullamcorper quam quis scelerisque. Aenean tempor laoreet rhoncus. Nullam lacus nibh, blandit eget venenatis ut, convallis id turpis. Aliquam iaculis ante ut odio consequat dictum. Cras eleifend et magna id iaculis. Mauris mi diam, porta non pulvinar sit amet, fermentum non nulla. Duis feugiat eget justo non suscipit. Nullam elementum, mauris ac lobortis ornare, urna justo pharetra ante, sed malesuada justo eros at nisl. Nulla aliquam lorem non sem porta, sit amet molestie urna faucibus. Suspendisse et dolor a sapien vehicula rutrum id sit amet tellus. Aenean in ipsum bibendum, euismod dolor ut, luctus nibh.");
    //set font
    QFont font = ui->text_area->font();
    font.setPointSize(16);
//    font.setBold(true);
    ui->text_area->setFont(font);
//    QTimer::singleShot(100, this, SLOT(changebg));
    emit resizeEvent(0);
    setglob();
}

Pov::~Pov()
{
    delete ui;
}

void Pov::setglob()
{
    m_bg = ":/new/index/picture/bg_" + QString::number(m_id) + ".png";
    m_song = ":/new/index/picture/s_"+ QString::number(m_id) + ".mp3";
}

void Pov::on_backButton_clicked()
{
    qDebug() << "backbutton";

//       changebg();
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
    QPainter p(this);
    p.drawImage(rect(), QImage(m_bg));
}
