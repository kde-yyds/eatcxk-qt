#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <unistd.h>
#include <iostream>
#include <ctime>
#include <QLabel>
#include <time.h>
using namespace std;
int t=0,s=0,stop=0,speed=1000;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->slider->hide();
    ui->stop->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_pushButton_clicked()
{
    ui->start_pushButton->hide();
    ui->slider->show();
    ui->stop->show();
    QApplication::processEvents(QEventLoop::AllEvents,30);
    for(int i=1;i<=361;i++)
    {

        QApplication::processEvents(QEventLoop::AllEvents,30);
        usleep(i*15);
        ui->scrollArea->resize(i*581/361,i);
    }
    ui->label_2->setNum(0);
    //width:581
    while(!stop)
    {
        ui->label_2->setNum(t);
        QApplication::processEvents(QEventLoop::AllEvents,30);
        /*
         * //timer
         *             TIME:20
         *
         *
         * //scrollarea
         *
         * 0---------145--------290---------437---------581
         * |          |          |           |           |
         * |          |          |           |           |
         * |          |          |           |           |
         * |          |          |           |           |
         * |          |          |           |           |
         * |          |          |           |           |
         * |          |          |           |           |
         * |          |          |           |           |
         * |          |          |           |           |
         * |          |   cxk    |           |           |
         * -----------------------------------------------
         *
         * //silder
         * ·-------------||------------------·------------
         *
         */
            QApplication::processEvents(QEventLoop::AllEvents,30);
            srand(clock()*time(0));
            int randnum=(rand())%4;
            int x=randnum*145.25+20;
//            QLabel c;
            ui->c->setParent(ui->scrollArea);
            ui->c->resize(70,84);
            ui->c->move(x,10);
            srand(clock()*time(0));
            int randnum2=(rand())%2;
            if(randnum2==0)
            {
                QImage image(QString("/usr/lib/eatcxk/cxk.png"));
                ui->c->setPixmap(QPixmap::fromImage(image));
            }
            else
            {
                QImage image(QString("/usr/lib/eatcxk/chicken.png"));
                ui->c->setPixmap(QPixmap::fromImage(image));
            }
            for(int i=10;i<=300;i++)
            {
                QApplication::processEvents(QEventLoop::AllEvents,30);
                usleep(speed);
                ui->c->move(x,i);
                ui->c->show();
            }
            if(ui->slider->value()>=randnum*145.25&&ui->slider->value()<=(randnum+1)*145.25)
            {
                s++;
                ui->label_4->setNum(s);
                if(randnum==0) system("mpv --no-video /usr/lib/eatcxk/j.mp3&");
                if(randnum==1) system("mpv --no-video /usr/lib/eatcxk/n.mp3&");
                if(randnum==2) system("mpv --no-video /usr/lib/eatcxk/t.mp3&");
                if(randnum==3) system("mpv --no-video /usr/lib/eatcxk/m.mp3&");
            }
            t++;


    }
}


void MainWindow::on_stop_clicked()
{
    stop=1;
    QApplication::processEvents(QEventLoop::AllEvents,30);
    for(int i=1;i<=361;i++)
    {

        QApplication::processEvents(QEventLoop::AllEvents,30);
        usleep(i*15);
        ui->scrollArea->resize(i*581/361,i);
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    speed=value;
}


void MainWindow::on_close_clicked()
{
    system("killall eatcxk-qt");
}

