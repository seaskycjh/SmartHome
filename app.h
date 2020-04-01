#ifndef APP_H
#define APP_H

#include <QWidget>

namespace Ui {
class App;
}

class App : public QWidget
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = 0);
    ~App();
    void ctrl_dev(int flag);

private slots:
    void on_lamp1Btn_clicked();
    void on_lamp2Btn_clicked();
    void on_fan1Btn_clicked();
    void on_fan2Btn_clicked();
    void on_backBtn_clicked();

private:
    Ui::App *ui;
    bool lamp1 = false;
    bool lamp2 = false;
    bool fan1 = false;
    bool fan2 = false;
    QPixmap lampOn;
    QPixmap lampOff;
    QPixmap fanOn;
    QPixmap fanOff;

    void set_lamp1(void);
};

#endif // APP_H
