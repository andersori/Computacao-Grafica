#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_girarBtn_clicked()
{
    double x = this->ui->eixoX->value();
    double y = this->ui->eixoY->value();
    double z = this->ui->eixoZ->value();

    this->ui->tela->girar(x, y, z);
}
