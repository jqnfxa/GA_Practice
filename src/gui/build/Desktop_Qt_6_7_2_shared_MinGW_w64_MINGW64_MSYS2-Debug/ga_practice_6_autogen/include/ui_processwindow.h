/********************************************************************************
** Form generated from reading UI file 'processwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSWINDOW_H
#define UI_PROCESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessWindow
{
public:
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QPushButton *goToFinishButton;
    QPushButton *nextGenButton;
    QPushButton *prevGenButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *genNum;

    void setupUi(QWidget *ProcessWindow)
    {
        if (ProcessWindow->objectName().isEmpty())
            ProcessWindow->setObjectName("ProcessWindow");
        ProcessWindow->resize(1105, 621);
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        ProcessWindow->setFont(font);
        graphicsView = new QGraphicsView(ProcessWindow);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(460, 20, 611, 581));
        graphicsView_2 = new QGraphicsView(ProcessWindow);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(50, 270, 361, 251));
        goToFinishButton = new QPushButton(ProcessWindow);
        goToFinishButton->setObjectName("goToFinishButton");
        goToFinishButton->setGeometry(QRect(160, 540, 141, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(12);
        goToFinishButton->setFont(font1);
        nextGenButton = new QPushButton(ProcessWindow);
        nextGenButton->setObjectName("nextGenButton");
        nextGenButton->setGeometry(QRect(320, 550, 41, 29));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter")});
        font2.setPointSize(20);
        font2.setBold(true);
        nextGenButton->setFont(font2);
        nextGenButton->setFlat(true);
        prevGenButton = new QPushButton(ProcessWindow);
        prevGenButton->setObjectName("prevGenButton");
        prevGenButton->setGeometry(QRect(100, 550, 41, 29));
        prevGenButton->setFont(font2);
        prevGenButton->setFlat(true);
        label = new QLabel(ProcessWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 180, 321, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Inter")});
        font3.setPointSize(14);
        label->setFont(font3);
        label->setLineWidth(0);
        label_2 = new QLabel(ProcessWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 20, 211, 31));
        label_2->setFont(font3);
        label_3 = new QLabel(ProcessWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 50, 181, 31));
        label_3->setFont(font3);
        genNum = new QLabel(ProcessWindow);
        genNum->setObjectName("genNum");
        genNum->setGeometry(QRect(270, 19, 101, 31));
        genNum->setFont(font3);

        retranslateUi(ProcessWindow);

        QMetaObject::connectSlotsByName(ProcessWindow);
    } // setupUi

    void retranslateUi(QWidget *ProcessWindow)
    {
        ProcessWindow->setWindowTitle(QCoreApplication::translate("ProcessWindow", "Form", nullptr));
        goToFinishButton->setText(QCoreApplication::translate("ProcessWindow", "\320\237\321\200\320\276\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
        nextGenButton->setText(QCoreApplication::translate("ProcessWindow", ">", nullptr));
        prevGenButton->setText(QCoreApplication::translate("ProcessWindow", "<", nullptr));
        label->setText(QCoreApplication::translate("ProcessWindow", "<html><head/><body><p>\320\223\321\200\320\260\321\204\320\270\320\272 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\260</p><p>\321\200\320\265\321\210\320\265\320\275\320\270\321\217:</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ProcessWindow", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\276\320\272\320\276\320\273\320\265\320\275\320\270\321\217:", nullptr));
        label_3->setText(QCoreApplication::translate("ProcessWindow", "\320\242\320\276\320\277 \321\200\320\265\321\210\320\265\320\275\320\270\320\271:", nullptr));
        genNum->setText(QCoreApplication::translate("ProcessWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessWindow: public Ui_ProcessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSWINDOW_H
