#include "finishwindow.h"
#include "./ui_finishwindow.h"

FinishWindow::FinishWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinishWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    ui->solution->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->qualityGraphVis->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->closeSolutionButton->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
}

FinishWindow::~FinishWindow()
{
    delete ui;
}



void FinishWindow::on_closeSolutionButton_clicked()
{
    this->close();
    emit closeSolution();
}

