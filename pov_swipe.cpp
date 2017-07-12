#include "pov_container.h"
#include "ui_pov_container.h"
#include "imap.h"
#include "ui_imap.h"
#include <QQuickView>
#include <QtQuick>
#include <QtQuickWidgets/QQuickWidget>
#include <QDebug>
#include "anchor.h"

void    Pov_Container::r_swipe_textarea()
{

//    m_anchor->setProperty("gauss", true);
    animation->setEndValue(-90);

    animation->start();


}

//void    Pov_Container::mod()
//{

//}

void    Pov_Container::Nextpreview()
{
    //right side
    int tmp = m_index + 1;
    if ( tmp >= m_limit)
        tmp = 0;
    m_anchor->setProperty("bg", m_bglist[tmp]);

    m_anchor->setProperty("textarea", m_arealist[tmp]);
    m_anchor->setProperty("titrearea", m_titlelist[tmp]);
}
void    Pov_Container::Prevpreview()
{
    int tmp = m_index - 1;
    if ( tmp < 0)
        tmp = m_limit - 1;
    m_anchor->setProperty("bg", m_bglist[tmp]);

    m_anchor->setProperty("textarea", m_arealist[tmp]);
    m_anchor->setProperty("titrearea", m_titlelist[tmp]);

}

void    Pov_Container::setRotation()
{
    if (!anim_state)
    {
        if (m_ndg < 10)
            m_ndg = 0;

        anim_state = true;
        if (c_m)
            c_m = false;
    }

    m_angle = m_anchor->property("ang").toInt();
    if (m_angle == 90 || m_angle == -90)
    {
        if (m_angle == 90)
        {
            //right side
            m_index++;
            if ( m_index >= m_limit)
                m_index = 0;
            m_anchor->setProperty("textarea", m_arealist[m_index]);
            m_anchor->setProperty("titrearea", m_titlelist[m_index]);
            m_anchor->setProperty("bg", m_bglist[m_index]);

            animation_p2->setStartValue(180 + 90);
            animation_p2->setEndValue(360);

            animation_p2->start();

        }
        else
        {
            // left side
            m_index--;
            if ( m_index < 0)
                m_index = m_limit - 1;


            m_anchor->setProperty("textarea", m_arealist[m_index]);
            m_anchor->setProperty("titrearea", m_titlelist[m_index]);
            m_anchor->setProperty("bg", m_bglist[m_index]);

            animation_p2->setStartValue(-90-180);
            animation_p2->setEndValue(-360);

            animation_p2->start();
        }
    }
    m_anchor->setProperty("ang", m_angle);

}

void    Pov_Container::l_swipe_textarea()
{
    animation->setEndValue(90);
    animation->start();

//    m_anchor->setProperty("gauss", true);
}
