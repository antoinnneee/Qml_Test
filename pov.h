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
             Pov(int index, QWidget *parent = 0);
        void setglob();
    ~Pov();

private slots:
    void on_backButton_clicked();
    void resizeEvent(QResizeEvent* event);
    void changebg();
    void paintEvent( QPaintEvent * );


private:
    Ui::Pov *ui;
    int m_id;
    QString m_bg;
    QString m_song;
};

#endif // POV_H
