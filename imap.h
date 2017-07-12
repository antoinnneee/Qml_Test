#ifndef IMAP_H
#define IMAP_H

#include <QMainWindow>
#include "pov_container.h"

namespace Ui {
class IMap;
}

class IMap : public QMainWindow
{
    Q_OBJECT

public:
    explicit IMap(QWidget *parent = 0);
    ~IMap();

private slots:
    void resizeEvent(QResizeEvent* event);
    void on_pov_0_clicked();
    void on_pov_1_clicked();
    void on_pov_2_clicked();
    void on_pov_3_clicked();
    void paintEvent( QPaintEvent * );

private:
    Ui::IMap *ui;
    Pov_Container *m_p;
};

#endif // IMAP_H
