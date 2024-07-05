#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "structures/polynomial.hpp"
#include "evolution/interface.hpp"
#include "evolution/selection/selection.hpp"
#include "evolution/mutation/mutation.hpp"
#include "evolution/crossover/crossover.hpp"
#include "core/generation.hpp"
#include "core/genetic.hpp"
#include "util/random.hpp"
#include <cmath>
#include <numeric>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    this->setMinimumHeight(701);
    this->setMinimumWidth(1003);
    ui->solveButton->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->setGraphButton->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->drawReaden->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x0coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x1coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x2coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x3coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x4coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->x5coef->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    //ui->setgraphVis->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->leftrange->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->rightrange->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->mixchance->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->mutationchance->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->startamount->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->genamount->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");

    plot = new QCustomPlot();
    plot->xAxis->setRange(-10, 10);
    plot->yAxis->setRange(-10, 10);
    ui->layout->addWidget(plot, 0);
    //ui->layout = new QVBoxLayout();
    //ui->layout->removeWidget(plot);

    process = new ProcessWindow();
    random = new QAction("Случайным образом");
    fromFile = new QAction("Из файла");

    graphOptions = new QMenu(ui->setGraphButton);
    graphOptions->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    graphOptions->addAction(random);
    graphOptions->addAction(fromFile);
    ui->setGraphButton->setMenu(graphOptions);
    connect(random, SIGNAL(triggered()), this, SLOT(randomFill()));
    connect(fromFile, SIGNAL(triggered()), this, SLOT(fillFromFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::randomFill()
{
	double min_coefficient = -1000;
	double max_coefficient = 1000;

	ui->x0coef->setText(QString::number(rnd(min_coefficient, max_coefficient)));
	ui->x1coef->setText(QString::number(rnd(min_coefficient, max_coefficient)));
	ui->x2coef->setText(QString::number(rnd(min_coefficient, max_coefficient)));
	ui->x3coef->setText(QString::number(rnd(min_coefficient, max_coefficient)));
	ui->x4coef->setText(QString::number(rnd(min_coefficient, max_coefficient)));
	ui->x5coef->setText(QString::number(rnd(min_coefficient, max_coefficient)));
	ui->leftrange->setText(QString::number(rnd<double>(-15, 0)));
	ui->rightrange->setText(QString::number(rnd<double>(0, 15)));
	ui->genamount->setText(QString::number(rnd<int>(5, 25)));
	ui->startamount->setText(QString::number(rnd<int>(10, 100)));
	ui->mixchance->setText(QString::number(rnd<double>(0, 1)));
	ui->mutationchance->setText(QString::number(rnd<double>(0, 1)));
}

void MainWindow::fillFromFile()
{
    QString myDir = QFileDialog::getOpenFileName();
    if (myDir==nullptr) return;

    std::vector<double> numbers(12);
    std::string dir = myDir.toStdString();
    std::ifstream file(dir);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    std::string line;
    if (std::getline(file, line)) {
        std::istringstream iss(line);

        int i = 0;
        while (iss >> numbers[i]) {
            ++i;
            if (i == 12) break; // Останавливаемся после 12 чисел
        }

        if (i != 12) {
            throw std::runtime_error("Неполное количество чисел в строке");
        }
    } else {
        throw std::runtime_error("Файл пустой");
    }

    ui->x0coef->setText(QString::number(numbers[0]));
    ui->x1coef->setText(QString::number(numbers[1]));
    ui->x2coef->setText(QString::number(numbers[2]));
    ui->x3coef->setText(QString::number(numbers[3]));
    ui->x4coef->setText(QString::number(numbers[4]));
    ui->x5coef->setText(QString::number(numbers[5]));
    ui->leftrange->setText(QString::number(numbers[6]));
    ui->rightrange->setText(QString::number(numbers[7]));
    ui->startamount->setText(QString::number(numbers[8]));
    ui->genamount->setText(QString::number(numbers[9]));
    ui->mixchance->setText(QString::number(numbers[10]));
    ui->mutationchance->setText(QString::number(numbers[11]));
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
    mutChance = ui->mutationchance->toPlainText().toDouble();

    mixChance = std::min(1.0, mixChance);
    mixChance = std::max(0.0, mixChance);

    mutChance = std::min(1.0, mutChance);
    mutChance = std::max(0.0, mutChance);

    startAmount = ui->startamount->toPlainText().toInt();
    if (startAmount <= 0) startAmount = 10;

    genAmount = ui->genamount->toPlainText().toInt();
    if (genAmount <= 0) genAmount = 10;

    Polynomial<double> polynomial(coefs);
    GeneticAlgorithm algorithm(
	startAmount,
	genAmount,
        mutChance,
        mixChance,
        new RouletteWheel,
        new MixerCrossover(0.5, rangeLeft, rangeRight),
	new SubstanceMutation(rangeLeft, rangeRight),
        new PolynomialEvaluator(polynomial),
	rangeLeft,
	rangeRight,
	polynomial
    );

    process->setData(algorithm.run(3), polynomial, rangeLeft, rangeRight, genAmount);
    process->show();
}

void MainWindow::slotRangeChanged(const QCPRange &newRange)
{
    /* If a scope chart is less than one day,
     * then display the hours and minutes in the Axis X,
     * otherwise display the date "Month Day Year"
     * */
    //customPlot->xAxis->setDateTimeFormat((newRange.size() <= 86400)? "hh:mm" : "dd MMM yy");
}

void MainWindow::on_setGraphButton_triggered(QAction *arg1)
{

}


void MainWindow::on_drawReaden_clicked()
{
    // handle data for GA
    std::vector<double> coefs;
    double rangeLeft, rangeRight;
    coefs.push_back(ui->x0coef->toPlainText().toDouble());
    coefs.push_back(ui->x1coef->toPlainText().toDouble());
    coefs.push_back(ui->x2coef->toPlainText().toDouble());
    coefs.push_back(ui->x3coef->toPlainText().toDouble());
    coefs.push_back(ui->x4coef->toPlainText().toDouble());
    coefs.push_back(ui->x5coef->toPlainText().toDouble());
    rangeLeft = ui->leftrange->toPlainText().toDouble();
    rangeRight = ui->rightrange->toPlainText().toDouble();

    QVector<double> x,y;
    double min_value = std::numeric_limits<double>::max();
    double max_value = std::numeric_limits<double>::min();

    for(double i = rangeLeft; i < rangeRight; i += 0.01)
    {
	double temp = coefs[0]+coefs[1]*i+coefs[2]*pow(i, 2)+coefs[3]*pow(i, 3)+coefs[4]*pow(i, 4)+coefs[5]*pow(i, 5);
        x.push_back(i);
        y.push_back(temp);

	min_value = std::min(min_value, temp);
	max_value = std::max(max_value, temp);
    }

    plot->yAxis->setRange(min_value, max_value);
    plot->addGraph();
    plot->addGraph();
    plot->graph(0)->setData(x, y);
    plot->xAxis->setRange(rangeLeft, rangeRight);
    plot->replot();

}

