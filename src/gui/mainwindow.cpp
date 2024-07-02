#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    ui->solveButton->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->setGraphButton->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->drawReaden->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x0coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x1coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x2coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x3coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x4coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x5coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->setgraphVis->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->leftrange->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->rightrange->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->mixchance->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->mutationchance->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->startamount->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->genamount->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");

    process = new ProcessWindow();
    random = new QAction("Случайным образом");
    fromFile = new QAction("Из файла");

    graphOptions = new QMenu(ui->setGraphButton);
    graphOptions->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    graphOptions->addAction(random);
    graphOptions->addAction(fromFile);
    ui->setGraphButton->setMenu(graphOptions);
    connect(random, SIGNAL(triggered()), this, SLOT(randomFill()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::randomFill()
{
    ui->x0coef->setText(QString::number(double(rand())/rand() - double(rand())/rand()));
    ui->x1coef->setText(QString::number(double(rand())/rand() - double(rand())/rand()));
    ui->x2coef->setText(QString::number(double(rand())/rand() - double(rand())/rand()));
    ui->x3coef->setText(QString::number(double(rand())/rand() - double(rand())/rand()));
    ui->x4coef->setText(QString::number(double(rand())/rand() - double(rand())/rand()));
    ui->x5coef->setText(QString::number(double(rand())/rand() - double(rand())/rand()));
    ui->leftrange->setText(QString::number(-double(rand())/rand()));
    ui->rightrange->setText(QString::number(double(rand())/rand()));
    ui->genamount->setText(QString::number(rand()%100));
    ui->startamount->setText(QString::number(rand()%100));
    ui->mixchance->setText(QString::number(rand()%100));
    ui->mutationchance->setText(QString::number(rand()%100));
}

void MainWindow::fillFromFile()
{

}

void MainWindow::on_solveButton_clicked()
{
    // handle data for GA
    std::vector<double> coefs;
    double rangeLeft, rangeRight;
    double mixChance, mutChance;
    int startAmount, genAmount;
    coefs.push_back(ui->x0coef->toPlainText().toDouble());
    coefs.push_back(ui->x1coef->toPlainText().toDouble());
    coefs.push_back(ui->x2coef->toPlainText().toDouble());
    coefs.push_back(ui->x3coef->toPlainText().toDouble());
    coefs.push_back(ui->x4coef->toPlainText().toDouble());
    coefs.push_back(ui->x5coef->toPlainText().toDouble());
    rangeLeft = ui->leftrange->toPlainText().toDouble();
    rangeRight = ui->rightrange->toPlainText().toDouble();
    mixChance = ui->mixchance->toPlainText().toDouble();
    if (mixChance <= 0) mixChance = 0.9;

    mutChance = ui->mutationchance->toPlainText().toDouble();
    if (mutChance <= 0) mutChance = 0.05;

    startAmount = ui->startamount->toPlainText().toInt();
    if (startAmount <= 0) startAmount = 10;

    genAmount = ui->genamount->toPlainText().toInt();
    if (genAmount <= 0) genAmount = 10;

    qDebug() << QString::number(genAmount);

    // go to solution process step
    process->setGenAmount(genAmount);
    process->show();
}



void MainWindow::on_setGraphButton_triggered(QAction *arg1)
{

}

