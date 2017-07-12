#ifndef CLICKLABEL_H
#define CLICKLABEL_H
#include <QLabel>

class clicklabel : public QLabel
{
    Q_OBJECT
public:
    clicklabel();
    clicklabel(QWidget * parent = 0 );
    ~clicklabel(){}
    void setoverlay(bool state, QBrush brush);
    void setimage(QString image);

signals:
    void clicked();

public slots:
    void slotClicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;
    void mouseReleaseEvent( QMouseEvent * event);
    void paintEvent( QPaintEvent * );
private:
    QImage m_image;
    bool m_ispush;
    bool m_debug;
    bool m_overlay;
    QBrush m_brush;
};

#endif // CLICKLABEL_H
