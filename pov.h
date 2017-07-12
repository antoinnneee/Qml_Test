#ifndef POV_H
#define POV_H

#include <QMainWindow>

namespace Ui {
class Pov;
}

class Pov : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pov(QWidget *parent = 0);
    ~Pov();

private slots:
    void on_backButton_clicked();
    void resizeEvent(QResizeEvent* event);
    void changebg();
    void paintEvent( QPaintEvent * );


private:
    Ui::Pov *ui;
};

#endif // POV_H
