#include "processwindow.h"
#include "./ui_processwindow.h"

ProcessWindow::ProcessWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    ui->prevGenButton->setStyleSheet("background-color: white; color: rgb(43, 104, 255);");
    ui->nextGenButton->setStyleSheet("background-color: white; color: rgb(43, 104, 255);");
    ui->goToFinishButton->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    finish = new FinishWindow();
    connect(finish, &FinishWindow::closeSolution, this, &ProcessWindow::close);

    plotPolinom = new QCustomPlot();
    ui->layoutPolinom->addWidget(plotPolinom, 0);

    plotEvalFunc = new QCustomPlot();
    ui->layoutEval->addWidget(plotEvalFunc, 0);

    curAmount = 0;
    genAmount = curAmount;
    ui->genNum->setText(QString::number(curAmount));
}

ProcessWindow::~ProcessWindow()
{
    delete ui;
}

void ProcessWindow::setGenAmount(int amount)
{
    genAmount = amount;
}

void ProcessWindow::setPlotPolinom(QCustomPlot *newPlot)
{

}

void ProcessWindow::on_goToFinishButton_clicked()
{
    finish->show();
}


void ProcessWindow::on_nextGenButton_clicked()
{
    if (curAmount == genAmount) return;

    curAmount++;
    ui->genNum->setText(QString::number(curAmount));

    if (curAmount == genAmount)
    {
        on_goToFinishButton_clicked();
    }
}


void ProcessWindow::on_prevGenButton_clicked()
{
    if (curAmount <= 0) return;

    curAmount--;
    ui->genNum->setText(QString::number(curAmount));
}

