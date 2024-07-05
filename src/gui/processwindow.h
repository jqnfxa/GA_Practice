#ifndef PROCESSWINDOW_H
#define PROCESSWINDOW_H


#include <QWidget>
#include "finishwindow.h"
#include "qcustomplot.h"
#include "core/genetic.hpp"

namespace Ui {
class ProcessWindow;
}

class ProcessWindow : public QWidget
{
    Q_OBJECT

public:
    std::vector<QPen> pens;
    std::vector<QPen> plot_pens;
    std::size_t cur_amount;
    std::size_t gen_amount;
    std::vector<std::vector<GeneticAlgorithmReport>> solution;
    Polynomial<double> polynomial;
    double left;
    double right;

    explicit ProcessWindow(QWidget *parent = 0);
    void setData(const std::vector<std::vector<GeneticAlgorithmReport>> &solution, const Polynomial<double> &polynomial, double left, double right, std::size_t gen_amount);

    void drawPoints(QCustomPlot *plot, std::size_t cur_amount);
    void setPolynomialPlot(QCustomPlot *plot);
    void setAccuracyPlot(QCustomPlot *plot, std::size_t cur_amount);
    ~ProcessWindow();


private slots:
    void on_goToFinishButton_clicked();

    void on_nextGenButton_clicked();

    void on_prevGenButton_clicked();

private:
    Ui::ProcessWindow *ui;
    QCustomPlot *plotPolinom;
    QCustomPlot *plotEvalFunc;
    FinishWindow *finish;
};


#endif // PROCESSWINDOW_H
