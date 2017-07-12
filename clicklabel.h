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

signals:
    void clicked();

public slots:
    void slotClicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;

};

#endif // CLICKLABEL_H
