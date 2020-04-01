#include "app.h"
#include "ui_app.h"

App::App(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);
    lampOn = QPixmap(":/image/images/lamp_on.png");
    lampOff = QPixmap(":/image/images/lamp_off.png");
    fanOn = QPixmap(":/image/images/fan_on.png");
    fanOff = QPixmap(":/image/images/fan_off.png");
}

App::~App()
{
    delete ui;
}

void App::ctrl_dev(int flag)
{
    switch(flag){
    case 5:
        lamp1 = true;
        break;
    case 6:
        lamp1 = false;
        break;
    default:
        break;
    }
    set_lamp1();
}

void App::on_lamp1Btn_clicked()
{
    set_lamp1();
    lamp1 = !lamp1;
}

void App::on_lamp2Btn_clicked()
{
    ui->lamp2Btn->setText(lamp2 ? "open" : "close");
    ui->lamp2->setPixmap(lamp2 ? lampOff : lampOn);
    lamp2 = !lamp2;
}

void App::on_fan1Btn_clicked()
{
    ui->fan1Btn->setText(fan1 ? "open" : "close");
    ui->fan1->setPixmap(fan1 ? fanOff : fanOn);
    fan1 = !fan1;
}

void App::on_fan2Btn_clicked()
{
    ui->fan2Btn->setText(fan2 ? "open" : "close");
    ui->fan2->setPixmap(fan2 ? fanOff : fanOn);
    fan2 = !fan2;
}

void App::on_backBtn_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

void App::set_lamp1()
{
    ui->lamp1Btn->setText(lamp1 ? "open" : "close");
    ui->lamp1->setPixmap(lamp1 ? lampOff : lampOn);
}
