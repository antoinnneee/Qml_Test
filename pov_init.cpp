#include "pov_container.h"
#include "ui_pov_container.h"
#include "imap.h"
#include "ui_imap.h"
#include <QQuickView>
#include <QtQuick>
#include <QtQuickWidgets/QQuickWidget>
#include <QDebug>
#include "anchor.h"
 #include <QQmlApplicationEngine>


void    Pov_Container::reset_rot()
{

    m_anchor->setProperty("ang", 0);
    media_stop();
    anim_state = false;
    m_ndg = 0;
    if (c_m)
    {
        m_anchor->setProperty("textarea", "No eatser egg here");
        m_anchor->setProperty("titrearea", "not here");
        m_anchor->setProperty("bg", m_bglist[m_index]);
            m_anchor->setProperty("ang", 3);
    }
    player->setMedia(QUrl(m_medialist[m_index]));
}
void    Pov_Container::e_setup()
{
    m_ndg += 1;
}

void    Pov_Container::View_setup(int i)
{

    m_index = i;
    m_angle= 0;
    qDebug()<< "loading view : " << m_index;
//    delete (ui->quickWidget);
//    ui->quickWidget = new QQuickWidget();
//    qDebug()<< "Delete passed";

      ui->quickWidget->close();
QMetaObject::invokeMethod(this, "vsetup_sl", Qt::QueuedConnection);
}

void Pov_Container::vsetup_sl()
{
    ui->quickWidget->setSource(QUrl("qrc:/QML/PovQuick.qml"));
    QObject *object = ui->quickWidget->rootObject();
    m_anchor = object->findChild<QObject*>("anchor");
    ui->quickWidget->show();
    m_anchor->setProperty("bg_play", m_button[0]);
    m_anchor->setProperty("bg", m_bglist[m_index]);
    m_anchor->setProperty("textarea", m_arealist[m_index]);
    m_anchor->setProperty("titrearea", m_titlelist[m_index]);
    m_anchor->setProperty("ang", 0);
    m_anchor->setProperty("gauss", false);
    m_anchor->setProperty("l_ar_x", 0);
    m_anchor->setProperty("r_ar_x", 0);
    player->setMedia(QUrl(m_medialist[m_index]));

    qDebug()<< "property set ";

    /*  setup animation  */

        animation = new QPropertyAnimation(m_anchor, "ang");
        animation->setDuration(190);
        animation->setStartValue(0);
        animation->setEndValue(-180);

        animation_p2 = new QPropertyAnimation(m_anchor, "ang");
        animation_p2->setDuration(260);

    /*  end setup animation  */
        qDebug()<< "animation set ";

    QObject::connect(m_anchor, SIGNAL(flick_nodraged()), this, SLOT(e_setup()));
    QObject::connect(m_anchor, SIGNAL(backclicked()), this, SLOT(Choose_setup()));
    QObject::connect(m_anchor, SIGNAL(r_swiped()), this, SLOT(r_swipe_textarea()));
    QObject::connect(m_anchor, SIGNAL(l_swiped()), this, SLOT(l_swipe_textarea()));
    QObject::connect(animation, SIGNAL(valueChanged(QVariant)),this, SLOT(setRotation()));
    QObject::connect(animation_p2, SIGNAL(finished()), this, SLOT(reset_rot()));
//    QObject::connect(animation_p2, SIGNAL(finished()), this, SLOT(reset_media()));
    QObject::connect(m_anchor, SIGNAL(r_preview()), this, SLOT(Nextpreview()));
    QObject::connect(m_anchor, SIGNAL(l_preview()), this, SLOT(Prevpreview()));
    QObject::connect(m_anchor, SIGNAL(v_reset()), this, SLOT(View_update()), Qt::DirectConnection);
    QObject::connect(m_anchor, SIGNAL(media_play()), this, SLOT(media_start()));
    QObject::connect(m_anchor, SIGNAL(media_stop()), this, SLOT(media_stop()));
    QObject::connect(m_anchor, SIGNAL(arrow_anim_started()), this, SLOT(a_arrow()));
    QObject::connect(m_anchor, SIGNAL(dbg_sign()), this, SLOT(on_pushButton_clicked()));

//    ui->quickWidget->setSource(QUrl("qrc:/QML/PovQuick.qml"));


}

void    Pov_Container::Choose_setup()
{
    player->stop();
    ui->quickWidget->close();
    QMetaObject::invokeMethod(this, "csetup_sl", Qt::QueuedConnection);
//  ==

}
void Pov_Container::csetup_sl()
{
    ui->quickWidget->setSource(QUrl("qrc:/QML/Quickchoose.qml"));

    QQmlContext *ctxt = ui->quickWidget->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(m_titlelist));

    QObject *object = ui->quickWidget->rootObject();
    m_anchor = object->findChild<QObject*>("anchor");
    ui->quickWidget->show();

    QObject::connect(m_anchor, SIGNAL(itemclicked(int)), this, SLOT(View_setup(int)));

}

void    Pov_Container::View_update()
{
//    QObject::disconnect(m_anchor, SIGNAL(v_reset()), this, SLOT(View_init()));
    m_anchor->setProperty("bg", m_bglist[m_index]);
    m_anchor->setProperty("textarea", m_arealist[m_index]);
    m_anchor->setProperty("titrearea", m_titlelist[m_index]);
//    setRotation();
//    QObject::connect(m_anchor, SIGNAL(v_reset()), this, SLOT(View_init()));

}
