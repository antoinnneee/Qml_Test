#ifndef IMAP_H
#define IMAP_H

#include <QMainWindow>

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

private:
    Ui::IMap *ui;
};

#endif // IMAP_H
