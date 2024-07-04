#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <vector>
#include <cstdlib>
#include <QFileDialog>
#include <string>
#include <sstream>
#include <fstream>
#include "processwindow.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotRangeChanged (const QCPRange &newRange);

    void randomFill();

    void fillFromFile();

    void on_solveButton_clicked();

    void on_setGraphButton_triggered(QAction *arg1);

    void on_drawReaden_clicked();

private:
    Ui::MainWindow *ui;
    QCustomPlot *plot;
    QCPGraph *polinom;
    QMenu *graphOptions;
    QAction *random;
    QAction *fromFile;
    ProcessWindow *process;
};
#endif // MAINWINDOW_H
