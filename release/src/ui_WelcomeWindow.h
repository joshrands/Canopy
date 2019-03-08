/********************************************************************************
** Form generated from reading UI file 'WelcomeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *suspectNameField;
    QLineEdit *warrantNumberField;
    QLabel *label_3;
    QFrame *fileFrame;
    QLabel *label_4;
    QLabel *fileNameLabel;
    QPushButton *browseButton;
    QPushButton *evaluateButton;
    QMenuBar *menubar;
    QMenu *menuWelcome_to_Canopy_Search;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName(QString::fromUtf8("WelcomeWindow"));
        WelcomeWindow->resize(958, 598);
        centralwidget = new QWidget(WelcomeWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 50, 591, 91));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 170, 181, 31));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        suspectNameField = new QLineEdit(centralwidget);
        suspectNameField->setObjectName(QString::fromUtf8("suspectNameField"));
        suspectNameField->setGeometry(QRect(280, 170, 611, 31));
        suspectNameField->setFont(font1);
        warrantNumberField = new QLineEdit(centralwidget);
        warrantNumberField->setObjectName(QString::fromUtf8("warrantNumberField"));
        warrantNumberField->setGeometry(QRect(280, 230, 611, 31));
        warrantNumberField->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 230, 181, 31));
        label_3->setFont(font1);
        fileFrame = new QFrame(centralwidget);
        fileFrame->setObjectName(QString::fromUtf8("fileFrame"));
        fileFrame->setGeometry(QRect(230, 330, 441, 171));
        fileFrame->setAutoFillBackground(false);
        fileFrame->setFrameShape(QFrame::StyledPanel);
        fileFrame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(fileFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 341, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        fileNameLabel = new QLabel(fileFrame);
        fileNameLabel->setObjectName(QString::fromUtf8("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(210, 120, 211, 31));
        fileNameLabel->setFont(font2);
        browseButton = new QPushButton(fileFrame);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setGeometry(QRect(20, 120, 131, 31));
        QFont font3;
        font3.setPointSize(12);
        browseButton->setFont(font3);
        evaluateButton = new QPushButton(centralwidget);
        evaluateButton->setObjectName(QString::fromUtf8("evaluateButton"));
        evaluateButton->setEnabled(false);
        evaluateButton->setGeometry(QRect(710, 430, 201, 71));
        QFont font4;
        font4.setPointSize(15);
        evaluateButton->setFont(font4);
        WelcomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WelcomeWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 958, 22));
        menuWelcome_to_Canopy_Search = new QMenu(menubar);
        menuWelcome_to_Canopy_Search->setObjectName(QString::fromUtf8("menuWelcome_to_Canopy_Search"));
        WelcomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WelcomeWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WelcomeWindow->setStatusBar(statusbar);

        menubar->addAction(menuWelcome_to_Canopy_Search->menuAction());

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QApplication::translate("WelcomeWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("WelcomeWindow", "Warranted Email Evaluator", nullptr));
        label_2->setText(QApplication::translate("WelcomeWindow", "Suspect/Case Name", nullptr));
        label_3->setText(QApplication::translate("WelcomeWindow", "Warrant Number", nullptr));
        label_4->setText(QApplication::translate("WelcomeWindow", "Select File or Folder Containing Emails", nullptr));
        fileNameLabel->setText(QApplication::translate("WelcomeWindow", "No file selected", nullptr));
        browseButton->setText(QApplication::translate("WelcomeWindow", "Browse", nullptr));
        evaluateButton->setText(QApplication::translate("WelcomeWindow", "Evaluate", nullptr));
        menuWelcome_to_Canopy_Search->setTitle(QApplication::translate("WelcomeWindow", "Welcome to Canopy Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
