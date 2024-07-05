#include "processwindow.h"
#include "./ui_processwindow.h"
#include "util/random.hpp"
#include <cmath>
#include <numeric>
#include <QtCharts>
#include <iostream>


ProcessWindow::ProcessWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessWindow),
    cur_amount(1),
    gen_amount(1),
    solution(),
    polynomial({0}),
    left(0),
    right(0)
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

    cur_amount = 1;
    this->gen_amount = 1;
    ui->genNum->setText(QString::number(cur_amount));
}

ProcessWindow::~ProcessWindow()
{
    delete ui;
}

void ProcessWindow::setData(const std::vector<std::vector<GeneticAlgorithmReport>> &solution, const Polynomial<double> &polynomial, double left, double right, std::size_t gen_amount)
{
	this->polynomial = polynomial;
	this->solution = solution;
	this->left = left;
	this->right = right;
	this->gen_amount = gen_amount;
	this->cur_amount = 1;

	for (int i = 0; i < solution.size() + 1; ++i)
	{
		plotPolinom->addGraph();
		plotEvalFunc->addGraph();
		const auto color = QColor(random<int>(50, 200), random<int>(50, 200), random<int>(50, 200));
		pens.push_back(QPen(color, 10));
		plot_pens.push_back(QPen(color, 2));
	}
	plotPolinom->addGraph();

	drawPoints(plotPolinom, cur_amount);
	setAccuracyPlot(plotEvalFunc, cur_amount);
}

void ProcessWindow::drawPoints(QCustomPlot *plot, std::size_t cur_amount)
{
	setPolynomialPlot(plot);

	for (int i = 0; i < solution.size(); ++i)
	{
		QVector<double> x,y;
		for (const auto &sol : solution[i][cur_amount - 1].best_solution())
		{
			x.push_back(sol);
                        y.push_back(polynomial(sol));
                }

		plot->graph(i + 1)->setPen(pens[i]);
		plot->graph(i + 1)->setData(x, y);
		plot->graph(i + 1)->setLineStyle(QCPGraph::lsNone);
		plot->graph(i + 1)->setScatterStyle(QCPScatterStyle::ssCircle);
    		plot->replot();
	}
}

void ProcessWindow::setPolynomialPlot(QCustomPlot *plot)
{
	QVector<double> x,y;
	double min_value = std::numeric_limits<double>::max();
	double max_value = std::numeric_limits<double>::min();

	for(double i = left; i < right; i += 0.01)
	{
		x.push_back(i);
		y.push_back(this->polynomial(i));

		min_value = std::min(min_value, this->polynomial(i));
		max_value = std::max(max_value, this->polynomial(i));
	}

	plot->yAxis->setRange(min_value * 1.2, max_value * 1.2);
	plot->xAxis->setRange(left, right);
	plot->graph(0)->setData(x, y);
	plot->replot();
}

void ProcessWindow::setAccuracyPlot(QCustomPlot *plot, std::size_t cur_amount)
{
	for (int i = 0; i < solution.size(); ++i)
	{
		QVector<double> x,y;
		const double best = solution[i].back().best_solution()[0];

		for (int j = 1; j <= cur_amount; j++)
		{
			x.push_back(j);
			y.push_back(solution[i][j - 1].accuracy(best));
		}

		plot->graph(i)->setPen(plot_pens[i]);
		plot->graph(i)->setData(x, y);
		plot->yAxis->setRange(0, 1);
		plot->xAxis->setRange(1, gen_amount);
		plot->replot();
	}
}

void ProcessWindow::on_goToFinishButton_clicked()
{
	std::vector<generation_t> best_solutions;
	for (const auto &sol : solution)
	{
		best_solutions.push_back(sol.back().best_solution());
	}

	QCustomPlot *plot = new QCustomPlot();
	for (int i = 0; i < solution.size() + 1; ++i)
	{
		plot->addGraph();
	}
	setAccuracyPlot(plot, cur_amount);

	finish->setSolution(best_solutions, plot);
	finish->show();
}

void ProcessWindow::on_nextGenButton_clicked()
{
	if (cur_amount >= gen_amount)
	{
		return;
	}

	++cur_amount;
	ui->genNum->setText(QString::number(cur_amount));
	drawPoints(plotPolinom, cur_amount);
	setAccuracyPlot(plotEvalFunc, cur_amount);

	if (cur_amount == gen_amount)
	{
		on_goToFinishButton_clicked();
	}
}

void ProcessWindow::on_prevGenButton_clicked()
{
	if (cur_amount <= 1)
	{
		return;
	}

	--cur_amount;
	ui->genNum->setText(QString::number(cur_amount));
	drawPoints(plotPolinom, cur_amount);
	setAccuracyPlot(plotEvalFunc, cur_amount);
}

