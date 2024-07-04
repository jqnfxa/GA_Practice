/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *setgraphVis;
    QLabel *label;
    QLabel *label_2;
    QToolButton *setGraphButton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *leftrange;
    QTextEdit *rightrange;
    QTextEdit *startamount;
    QTextEdit *genamount;
    QTextEdit *mixchance;
    QTextEdit *mutationchance;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *solveButton;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QTextEdit *x5coef;
    QTextEdit *x4coef;
    QTextEdit *x3coef;
    QTextEdit *x2coef;
    QTextEdit *x1coef;
    QTextEdit *x0coef;
    QPushButton *drawReaden;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1003, 701);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        setgraphVis = new QGraphicsView(centralwidget);
        setgraphVis->setObjectName("setgraphVis");
        setgraphVis->setGeometry(QRect(430, 240, 541, 391));
        QFont font;
        font.setPointSize(12);
        setgraphVis->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 10, 631, 91));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(16);
        label->setFont(font1);
        label->setTextFormat(Qt::TextFormat::MarkdownText);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 130, 121, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter")});
        font2.setPointSize(12);
        label_2->setFont(font2);
        setGraphButton = new QToolButton(centralwidget);
        setGraphButton->setObjectName("setGraphButton");
        setGraphButton->setGeometry(QRect(470, 110, 151, 41));
        setGraphButton->setFont(font2);
        setGraphButton->setStyleSheet(QString::fromUtf8("setGraphButton {\n"
"	background-color: rgb(43, 104, 255); color:white; border: 3px solid white; border-radius: 10px;\n"
"}"));
        setGraphButton->setPopupMode(QToolButton::ToolButtonPopupMode::MenuButtonPopup);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 200, 121, 41));
        label_3->setFont(font2);
        label_3->setTextFormat(Qt::TextFormat::AutoText);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 240, 31, 31));
        label_4->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(220, 240, 31, 31));
        label_5->setFont(font2);
        leftrange = new QTextEdit(centralwidget);
        leftrange->setObjectName("leftrange");
        leftrange->setGeometry(QRect(80, 240, 91, 41));
        leftrange->setFont(font2);
        rightrange = new QTextEdit(centralwidget);
        rightrange->setObjectName("rightrange");
        rightrange->setGeometry(QRect(260, 240, 91, 41));
        rightrange->setFont(font2);
        startamount = new QTextEdit(centralwidget);
        startamount->setObjectName("startamount");
        startamount->setGeometry(QRect(290, 340, 91, 41));
        startamount->setFont(font2);
        genamount = new QTextEdit(centralwidget);
        genamount->setObjectName("genamount");
        genamount->setGeometry(QRect(290, 390, 91, 41));
        genamount->setFont(font2);
        mixchance = new QTextEdit(centralwidget);
        mixchance->setObjectName("mixchance");
        mixchance->setGeometry(QRect(290, 440, 91, 41));
        mixchance->setFont(font2);
        mutationchance = new QTextEdit(centralwidget);
        mutationchance->setObjectName("mutationchance");
        mutationchance->setGeometry(QRect(290, 490, 91, 41));
        mutationchance->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 290, 261, 31));
        label_6->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 340, 261, 31));
        label_7->setFont(font2);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 390, 241, 31));
        label_8->setFont(font2);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 440, 251, 31));
        label_9->setFont(font2);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 490, 251, 31));
        label_10->setFont(font2);
        solveButton = new QPushButton(centralwidget);
        solveButton->setObjectName("solveButton");
        solveButton->setGeometry(QRect(110, 570, 171, 31));
        solveButton->setFont(font2);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(130, 160, 21, 31));
        label_11->setFont(font);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(260, 160, 31, 31));
        label_12->setFont(font);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(410, 160, 51, 31));
        label_13->setFont(font);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(580, 160, 51, 31));
        label_14->setFont(font);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(750, 160, 51, 31));
        label_15->setFont(font);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(920, 160, 51, 31));
        label_16->setFont(font);
        x5coef = new QTextEdit(centralwidget);
        x5coef->setObjectName("x5coef");
        x5coef->setGeometry(QRect(810, 160, 101, 41));
        x5coef->setFont(font2);
        x4coef = new QTextEdit(centralwidget);
        x4coef->setObjectName("x4coef");
        x4coef->setGeometry(QRect(640, 160, 101, 41));
        x4coef->setFont(font2);
        x3coef = new QTextEdit(centralwidget);
        x3coef->setObjectName("x3coef");
        x3coef->setGeometry(QRect(470, 160, 101, 41));
        x3coef->setFont(font2);
        x2coef = new QTextEdit(centralwidget);
        x2coef->setObjectName("x2coef");
        x2coef->setGeometry(QRect(300, 160, 101, 41));
        x2coef->setFont(font2);
        x1coef = new QTextEdit(centralwidget);
        x1coef->setObjectName("x1coef");
        x1coef->setGeometry(QRect(150, 160, 101, 41));
        x1coef->setFont(font2);
        x0coef = new QTextEdit(centralwidget);
        x0coef->setObjectName("x0coef");
        x0coef->setGeometry(QRect(20, 160, 101, 41));
        x0coef->setFont(font2);
        drawReaden = new QPushButton(centralwidget);
        drawReaden->setObjectName("drawReaden");
        drawReaden->setGeometry(QRect(640, 110, 331, 41));
        drawReaden->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\237\320\276\320\270\321\201\320\272 \320\273\320\276\320\272\320\260\320\273\321\214\320\275\321\213\321\205 \320\270 \320\263\320\273\320\276\320\261\320\260\320\273\321\214\320\275\320\276\320\263\320\276</p><p align=\"center\">\320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274\320\276\320\262 \320\275\320\260 \320\276\321\202\321\200\320\265\320\267\320\272\320\265 \320\277\320\276\320\273\320\270\320\275\320\276\320\274\320\260</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\270\320\275\320\276\320\274", nullptr));
        setGraphButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\272 \320\267\320\260\320\264\320\260\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\267\320\276\320\272", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\276\321\202", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\264\320\276", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\263\320\265\320\275\320\276\320\262 \320\275\320\260 \321\201\321\202\320\260\321\200\321\202\320\265:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\277\320\276\320\272\320\276\320\273\320\265\320\275\320\270\320\271:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\275\321\201 \321\201\320\272\321\200\320\265\321\211\320\270\320\262\320\260\320\275\320\270\321\217:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\275\321\201 \320\274\321\203\321\202\320\260\321\206\320\270\320\270:", nullptr));
        solveButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "x+", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "x^2+", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "x^3+", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "x^4+", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "x^5", nullptr));
        drawReaden->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214  \320\262\320\262\320\265\320\264\320\265\320\275\321\213\320\271 \320\277\320\276\320\273\320\270\320\275\320\276\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
