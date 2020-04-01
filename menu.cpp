#include "menu.h"
#include "ui_menu.h"
#include "xml.h"

#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QFile>

QTcpSocket *mSocket;
void sendFile();

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{

    ui->setupUi(this);
    mSocket = new QTcpSocket();
    mTimer = new QTimer(this);
    app = new App(this);
    app->hide();
    myxml = new Xml();
    connect(mTimer, &QTimer::timeout, this, &Menu::setData);
    connect(mSocket, &QTcpSocket::readyRead, this, &Menu::recv_xml);

    ui->ipEdit->setText(ip);
    ui->portEdit->setText(port);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_ctlBtn_clicked()
{
    app->show();
}

void Menu::on_cntBtn_clicked()
{
    ip = ui->ipEdit->text();
    port = ui->portEdit->text();
    if(ip.isEmpty() || port.isEmpty()){
        qDebug() << "Input ip and port";
    }else{
        mSocket->connectToHost(QHostAddress(ip), port.toInt());
        qDebug() << "ip: " << ip << "  port: " << port.toInt();
    }

}

void Menu::on_discntBtn_clicked()
{
    mSocket->disconnectFromHost();
}

void Menu::on_vcBtn_clicked()
{
    mTimer->start(6000);
    system("arecord -d5 -c1 -r16000 -twav -fS16_LE example.wav");
}

void Menu::setData()
{
    mTimer->stop();
    sendFile();
}

void Menu::recv_xml()
{
    QByteArray buf = mSocket->readAll();
    if(QString(buf).mid(0, 2) == QString("<?")){
        QFile xml_file("file.xml");
        xml_file.open(QIODevice::WriteOnly);
        xml_file.write(buf);
        qDebug() << "recv xml file:" << QString(buf);
        xml_file.close();

        flag = myxml->parse_book(XML_FILE);
        qDebug() << "xml_flag: " << flag;
        ctrl_flag();

    }
}

void Menu::ctrl_flag()
{
    switch(flag){
    case 0:
        break;
    case 1:
        app->show();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        app->hide();
        break;
    default:
        app->ctrl_dev(flag);
        break;
    }
}

void sendFile(){
    //获取文件大小
    QFile file("example.wav");
    int fileSize = 0;
    int sendSize = 0;
    fileSize =  file.size();

    //fileSize整型函数转成字符串
    QString str;
    str.setNum(fileSize);

    //发送录音文件大小
    mSocket->write(str.toUtf8());
    qDebug()<<"example.wav file size "<<str<<"str.toUtf8: "<<str.toUtf8();
    mSocket->write("start");

    //发送已经录音完成的example.wav文件
    file.open(QIODevice::ReadOnly);
    int len = 0;
    char buf[1024] = {0};
    do{
        //读文件数据
        len = file.read(buf, sizeof(buf));
        //发送网络
        mSocket->write(buf, len);
        //累加数据
        sendSize += len;
        qDebug()<<"example.wav file len :"<<len <<" sendSize: "<<sendSize <<" fileSize: "<<fileSize;
    }while(len > 0);

    if(sendSize != fileSize){
        file.close();
        qDebug()<<QString("file send nocomplete");
        return ;
    }
    qDebug()<<QString("file send complete");
    file.close();
}


