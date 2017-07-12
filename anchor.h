#ifndef ANCHOR_H
#define ANCHOR_H

#include <QObject>
#include <QColor>
#include <QString>

class Anchor: public QObject
{
    Q_OBJECT
//  Q_PROPERTY(Type QmlAnchor READ GetterFunc WRITE SetterFunc NOTIFY signal)
    Q_PROPERTY(QString bg READ getbg WRITE setbg NOTIFY bgChanged)
    Q_PROPERTY(bool gauss READ gauss WRITE setGauss NOTIFY gaussChanged)
    Q_PROPERTY(int ang READ getangle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(int l_ar_x READ getl_ar_x WRITE setl_ar_x NOTIFY l_ar_xChanged)
    Q_PROPERTY(int r_ar_x READ getr_ar_x WRITE setr_ar_x NOTIFY r_ar_xChanged)
    Q_PROPERTY(QString textarea READ gettext WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString titrearea READ gettitre WRITE setTitre NOTIFY titreChanged)
    Q_PROPERTY(QString bg_play READ getbg_play WRITE setbg_play NOTIFY bg_playChanged)
//    Q_PROPERTY(QObject myModel READ myModel WRITE setMyModel NOTIFY myModelChanged)
public:
    Anchor() :  _bg(""), _gauss(false), _ang(0), _l_ar_x(0), _text(""), _titre("Title"), _bg_play("") { }
    //SIGNAL FROM QML
    Q_INVOKABLE void backclick(){
        emit backclicked();
    }
    Q_INVOKABLE void debug_signal(){
        emit dbg_sign();
    }
    Q_INVOKABLE void arrow_start(){
        emit arrow_anim_started();
    }
    Q_INVOKABLE void flick_nodrag(){
        emit flick_nodraged();
    }
    Q_INVOKABLE void itemclick(int index){
        emit itemclicked(index);
    }

    Q_INVOKABLE void r_swip(){
        emit r_swiped();
    }
    Q_INVOKABLE void l_swip(){
        emit l_swiped();
    }
    Q_INVOKABLE void r_prew(){
        emit    r_preview();
    }
    Q_INVOKABLE void l_prew(){
        emit    l_preview();
    }
    Q_INVOKABLE void view_reset(){
        emit    v_reset();
    }
    Q_INVOKABLE void media_play_click(){
        emit    media_play();
    }
    Q_INVOKABLE void media_stop_click(){
        emit    media_stop();
    }


   //GETTER
//    QObject myModel () const {
//        return _myModel;
//    }
    bool    gauss () const {
        return _gauss;
    }
    int    getangle() const {
        return _ang;
    }
    int getl_ar_x() const {
        return _l_ar_x;
    }
    int getr_ar_x() const {
        return _r_ar_x;
    }
    QString getbg() const {
        return _bg;
    }
    QString getbg_play() const {
        return _bg_play;
    }
    QString gettext() const {
        return _text;
    }
    QString gettitre() const {
        return _titre;
    }

    //SETTER
//    void setMyModel(const QObject &var){
//        _myModel = var;
//        emit myModelChanged();
//    }

    void setbg(const QString &bg) {
        _bg = bg;
        emit bgChanged();
    }
    void setbg_play(const QString &bg_play) {
        _bg_play = bg_play;
        emit bg_playChanged();
    }
    void setText(const QString &text) {
        _text = text;
        emit textChanged();
    }
    void setTitre(const QString &titre) {
        _titre = titre;
        emit titreChanged();
    }
    void setAngle(const int angle) {
        _ang = angle;
        emit angleChanged();
    }
    void setGauss(const bool gauss) {
        _gauss = gauss;
        emit gaussChanged();
    }
    void setl_ar_x(const int l_ar_x) {
        _l_ar_x = l_ar_x;
        emit l_ar_xChanged(l_ar_x);
    }
    void setr_ar_x(const int r_ar_x) {
        _r_ar_x = r_ar_x;
        emit r_ar_xChanged(r_ar_x);
    }

signals:
    void bgChanged();
    void angleChanged();
    void textChanged();
    void titreChanged();
    void gaussChanged();
    void backclicked();
//    void myModelChanged();
    void itemclicked(int index);
    void r_swiped();
    void l_swiped();
    void r_preview();
    void l_preview();
    void v_reset();
    void media_play();
    void media_stop();
    void bg_playChanged();
    void dbg_sign();
    void l_ar_xChanged(int l_ar_x);
    void flick_nodraged();
    void arrow_anim_started();
    void r_ar_xChanged(int r_ar_x);

private:
    QString _bg;
    QString _bg_play;
    QString _text;
    QString _titre;
    int     _ang;
    int     _l_ar_x;
    int     _r_ar_x;
    bool    _gauss;
//    QObject _myModel;
};

#endif // ANCHOR_H
