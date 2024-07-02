#ifndef PROCESSWINDOW_H
#define PROCESSWINDOW_H


#include <QWidget>
#include "finishwindow.h"

namespace Ui {
class ProcessWindow;
}

class ProcessWindow : public QWidget
{
    Q_OBJECT

public:
    int genAmount, curAmount;

    explicit ProcessWindow(QWidget *parent = 0);
    void setGenAmount(int amount);
    ~ProcessWindow();


private slots:
    void on_goToFinishButton_clicked();

    void on_nextGenButton_clicked();

    void on_prevGenButton_clicked();

private:
    Ui::ProcessWindow *ui;
    FinishWindow *finish;

};


#endif // PROCESSWINDOW_H
