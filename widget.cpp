#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->coffee->setEnabled(0);
    ui->tea->setEnabled(0);
    ui->milk->setEnabled(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Result(int in){
    if(in == 1){
        money = 0;
    }
    else{
        money += in;
    }

    ui->lcdNumber->display(money);

    if(money >= 100){
        ui->coffee->setEnabled(1);
    }
    else{
        ui->coffee->setEnabled(0);
    }

    if(money >= 150){
        ui->tea->setEnabled(1);
    }
    else{
        ui->tea->setEnabled(0);
    }

    if(money >= 200){
        ui->milk->setEnabled(1);
    }
    else{
        ui->milk->setEnabled(0);
    }
}

void Widget::on_won10_clicked()
{
    Result(10);
}

void Widget::on_won50_clicked()
{
    Result(50);
}

void Widget::on_won100_clicked()
{
    Result(100);
}

void Widget::on_won500_clicked()
{
    Result(500);
}

void Widget::on_coffee_clicked()
{
    Result(-100);
}

void Widget::on_tea_clicked()
{
    Result(-150);
}

void Widget::on_milk_clicked()
{
    Result(-200);
}

void Widget::on_reset_clicked()
{
    QMessageBox Q;
    char rest[100];
    int won500, won100, won50, won10;

    won500 = money/500;
    money = money%500;

    won100 = money/100;
    money = money%100;

    won50 = money/50;
    money = money%50;

    won10 = money/10;

    sprintf(rest, "<Rest Money>\n500Won: %d\n100Won: %d\n50Won: %d\n10Won: %d", won500, won100, won50, won10);
    Result(1);

    Q.information(this, "Information!", rest);
}
