#ifndef POV_CONTAINER_H
#define POV_CONTAINER_H

#include <QMainWindow>
#include <QQuickView>
#include <anchor.h>
#include <QPropertyAnimation>
#include <QMediaPlayer>

typedef bool cool;

namespace Ui {
class Pov_Container;
}

class Pov_Container : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pov_Container(QWidget *parent = 0);
    ~Pov_Container();

protected:
    void resizeEvent(QResizeEvent* event);

public slots:
    void vsetup_sl();
    void csetup_sl();



private slots:
    void on_pushButton_clicked();
    void setRotation();
    void r_swipe_textarea();
    void l_swipe_textarea();
    void reset_rot();
    void Prevpreview();
    void Nextpreview();
    void View_update();
    void media_start();
    void media_stop();
    void View_setup(int i);
    void Choose_setup();
    void e_setup();
    void a_arrow();
    void load_text();


private:
    Ui::Pov_Container *ui;
    QQuickView *m_view;
    QWidget *m_container;
    QObject * m_anchor;
    QStringList m_arealist;
    QStringList m_titlelist;
    QStringList m_bglist;
    QStringList m_button;
    QStringList m_medialist;
    int     m_index;
    int     m_ndg;
    int     m_limit;
    int     m_angle;
    int     m_preview_mode;
    cool    c_m;
    cool    anim_state;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation_p2;
    QPropertyAnimation *r_arrow_annim;
    QPropertyAnimation *l_arrow_annim;
    QPropertyAnimation *r_arrow_annim2;
    QPropertyAnimation *l_arrow_annim2;
    QPropertyAnimation *r_arrow_annim3;
    QPropertyAnimation *l_arrow_annim3;
    QPropertyAnimation *r_arrow_annim4;
    QPropertyAnimation *l_arrow_annim4;
    QPropertyAnimation *l_arrow_annim1_5;
    QPropertyAnimation *l_arrow_annim1;
    QPropertyAnimation *r_arrow_annim1_5;
    QPropertyAnimation *r_arrow_annim1;
    QMediaPlayer *player;


//    QQmlContext *ctx;

};

#endif // POV_CONTAINER_H
