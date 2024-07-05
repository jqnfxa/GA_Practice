#include "finishwindow.h"
#include "./ui_finishwindow.h"

FinishWindow::FinishWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinishWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    ui->solution->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    ui->closeSolutionButton->setStyleSheet("background-color: white; border: 2px solid rgb(43, 104, 255);");
    plot = nullptr;
}

FinishWindow::~FinishWindow()
{
    delete ui;
}

void FinishWindow::setSolution(const std::vector<generation_t> &best_solutions, QCustomPlot *accuracy_plot)
{
	std::string report;
	for (int i = 0; i < best_solutions.size(); ++i)
	{
		report += "Solution " + std::to_string(i + 1) + "\n";
		for (const auto &individual : best_solutions[i])
		{
			report += std::to_string(individual);
			report.push_back('\n');
		}
		report.push_back('\n');
	}

	ui->solution->setText(QString::fromStdString(report));


	if (plot != nullptr)
	{
		ui->layoutEval->removeWidget(plot);
		delete plot;
	}

	plot = accuracy_plot;
	ui->layoutEval->addWidget(plot, 0);
	plot->show();
}

void FinishWindow::on_closeSolutionButton_clicked()
{
    this->close();
    emit closeSolution();
}

