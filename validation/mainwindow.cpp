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

void MainWindow::on_pushButton_clicked() {
    Object.ReadFile(ui->lineEdit->text());
    ui->label->setText("Status: File upload!");
}

void MainWindow::on_pushButton_2_clicked() {
    Object.WriteFile();
    ui->label->setText("Status: File processed!");
}
