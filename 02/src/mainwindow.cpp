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

void MainWindow::on_openGlBtn_clicked()
{
    double angX = this->ui->eixoX->value();
    double angY = this->ui->eixoY->value();
    double angZ = this->ui->eixoZ->value();

    this->ui->tela->girar_open_gl(angX, angY, angZ);
}

void MainWindow::on_girarGlBtn_clicked()
{
    double angX = this->ui->eixoX->value();
    double angY = this->ui->eixoY->value();
    double angZ = this->ui->eixoZ->value();

    this->ui->tela->girar_propria(angX, angY, angZ);
}
