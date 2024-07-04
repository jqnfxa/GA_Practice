/********************************************************************************
** Form generated from reading UI file 'finishwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISHWINDOW_H
#define UI_FINISHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FinishWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QGraphicsView *qualityGraphVis;
    QTextBrowser *solution;
    QPushButton *closeSolutionButton;

    void setupUi(QWidget *FinishWindow)
    {
        if (FinishWindow->objectName().isEmpty())
            FinishWindow->setObjectName("FinishWindow");
        FinishWindow->resize(697, 500);
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        font.setPointSize(14);
        FinishWindow->setFont(font);
        label = new QLabel(FinishWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 251, 31));
        label->setFont(font);
        label_2 = new QLabel(FinishWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 20, 301, 71));
        label_2->setFont(font);
        qualityGraphVis = new QGraphicsView(FinishWindow);
        qualityGraphVis->setObjectName("qualityGraphVis");
        qualityGraphVis->setGeometry(QRect(310, 110, 361, 321));
        solution = new QTextBrowser(FinishWindow);
        solution->setObjectName("solution");
        solution->setGeometry(QRect(20, 110, 256, 231));
        closeSolutionButton = new QPushButton(FinishWindow);
        closeSolutionButton->setObjectName("closeSolutionButton");
        closeSolutionButton->setGeometry(QRect(70, 380, 161, 41));

        retranslateUi(FinishWindow);

        QMetaObject::connectSlotsByName(FinishWindow);
    } // setupUi

    void retranslateUi(QWidget *FinishWindow)
    {
        FinishWindow->setWindowTitle(QCoreApplication::translate("FinishWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("FinishWindow", "<html><head/><body><p>\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\275\320\276\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\320\265</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("FinishWindow", "<html><head/><body><p>\320\223\321\200\320\260\321\204\320\270\320\272 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\260</p><p>\321\200\320\265\321\210\320\265\320\275\320\270\321\217</p></body></html>", nullptr));
        closeSolutionButton->setText(QCoreApplication::translate("FinishWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinishWindow: public Ui_FinishWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHWINDOW_H
