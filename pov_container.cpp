#include "pov_container.h"
#include "ui_pov_container.h"
#include "imap.h"
#include "ui_imap.h"
#include <QQuickView>
#include <QtQuick>
#include <QtQuickWidgets/QQuickWidget>
#include <QDebug>
#include "anchor.h"
#include <QFile>
#include <QMediaPlayer>


Pov_Container::Pov_Container(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pov_Container)
{

    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
//  == Setup string area ==
    m_index = 0;
    c_m = false;


    load_text();
    m_bglist    << "qrc:/background/BG0"
                << "qrc:/background/BG1"
                << "qrc:/background/BG2"
                << "qrc:/background/BG3"
                << "qrc:/background/BG4"
                << "qrc:/background/BG5"
                << "qrc:/background/BG6"
                    ;

    m_limit = m_arealist.count();
    m_button << "qrc:/icone/PLAY0"
             << "qrc:/icone/PAUSE0"
             << "qrc:/icone/STOP"
                ;
    m_medialist << "qrc:/sound/SOUND0"
                << "qrc:/sound/SOUND1"
                << "qrc:/sound/SOUND2"
                << "qrc:/sound/SOUND3"
                << "qrc:/sound/SOUND4"
                << "qrc:/sound/SOUND5"
                << "qrc:/sound/SOUND6"
                   ;

//  == end setup string area ==

//  == setup player ==
    player = new QMediaPlayer;
//  == end setup ==

    //  == load and setup gml interface ==
        qmlRegisterType<Anchor>("Ancre", 4, 2, "Anchor");
//qmlRegisterUncreatableType<QString>("MyModel", 1, 0, "MyModel", "Instanciated C++ side !");
    Choose_setup();
//    View_setup(2);
    //  == end load qml interface ==

            m_preview_mode = 0;
            m_angle = 0;
            m_ndg = 0;
//  Connection
        emit resizeEvent(0);

}

void Pov_Container::load_text()
{
    int index = 0;
    bool init = true;
    QFile file(":/texte/TA0");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    while (init)
    {
        QString pathta = ":/texte/TA" + QString::number(index);
        QString pathti = ":/texte/T" + QString::number(index);
        QFile titrearea(pathti);
        QFile textarea(pathta);
        titrearea.open(QIODevice::ReadOnly | QIODevice::Text);
        textarea.open(QIODevice::ReadOnly | QIODevice::Text);

        if (titrearea.exists())
        {
            m_arealist << textarea.readAll();
            m_titlelist << titrearea.readAll();
            index++;
            titrearea.close();
            textarea.close();

        }
        else
            init = false;
    }
}

void Pov_Container::media_start()
{
    if (player->state() == QMediaPlayer::PlayingState)
    {
        player->pause();
        m_anchor->setProperty("bg_play", m_button[0]);


    }
    else
    {
        player->play();
        m_anchor->setProperty("bg_play", m_button[1]);
    }
}

void Pov_Container::media_stop()
{
    player->stop();
    m_anchor->setProperty("bg_play", m_button[0]);
}

void Pov_Container::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   int height = this->geometry().height();
   int width  = this->geometry().width();
   ui->verticalLayoutWidget->setGeometry(0,0,width,height);
   ui->quickWidget->setGeometry(0,0,width,height);
}

void Pov_Container::a_arrow()
{
    QSequentialAnimationGroup *lgroup = new QSequentialAnimationGroup;
    QSequentialAnimationGroup *rgroup = new QSequentialAnimationGroup;

    l_arrow_annim = new QPropertyAnimation(m_anchor, "l_ar_x");
    l_arrow_annim->setDuration(500);
    l_arrow_annim->setStartValue(0);
    l_arrow_annim->setEndValue(30);
    l_arrow_annim->setEasingCurve(QEasingCurve::SineCurve);

    l_arrow_annim1 = new QPropertyAnimation(m_anchor, "l_ar_x");
    l_arrow_annim1->setDuration(500);
    l_arrow_annim1->setStartValue(0);
    l_arrow_annim1->setEndValue(25);
    l_arrow_annim1->setEasingCurve(QEasingCurve::SineCurve);


    r_arrow_annim = new QPropertyAnimation(m_anchor, "r_ar_x");
    r_arrow_annim->setDuration(500);
    r_arrow_annim->setStartValue(0);
    r_arrow_annim->setEndValue(-30);
    r_arrow_annim->setEasingCurve(QEasingCurve::SineCurve);

    r_arrow_annim1 = new QPropertyAnimation(m_anchor, "r_ar_x");
    r_arrow_annim1->setDuration(500);
    r_arrow_annim1->setStartValue(0);
    r_arrow_annim1->setEndValue(-25);
    r_arrow_annim1->setEasingCurve(QEasingCurve::SineCurve);


    lgroup->addAnimation(l_arrow_annim);
    lgroup->addAnimation(l_arrow_annim1);

    rgroup->addAnimation(r_arrow_annim);
    rgroup->addAnimation(r_arrow_annim1);

    rgroup->start();
    lgroup->start();

}

void Pov_Container::on_pushButton_clicked()
{
    static int toto = 0;

    if (anim_state && m_ndg > 10)
    {
        qDebug() << "egg";
        c_m = true;
    }

    toto++;
    qDebug() << "really, only this";

}

Pov_Container::~Pov_Container()
{
    delete ui;
}
