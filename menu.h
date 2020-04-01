#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QTimer>

#include "app.h"
#include "xml.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_ctlBtn_clicked();
    void on_cntBtn_clicked();
    void on_discntBtn_clicked();
    void on_vcBtn_clicked();
    void setData();
    void recv_xml();

private:
    Ui::Menu *ui;
    App *app;
    QTimer *mTimer;
    Xml *myxml;
    QString ip = "192.168.1.12";
    QString port = "8090";
    int flag;

    void ctrl_flag();
};

#endif // MENU_H
