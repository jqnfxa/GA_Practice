#ifndef FINISHWINDOW_H
#define FINISHWINDOW_H


#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class FinishWindow;
}

class FinishWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FinishWindow(QWidget *parent = 0);
    ~FinishWindow();

signals:
    void closeSolution();

private slots:
    void on_closeSolutionButton_clicked();

private:
    Ui::FinishWindow *ui;
    QCustomPlot *plot;
};


#endif // FINISHWINDOW_H
