/********************************************************************************
** Form generated from reading UI file 'WelcomeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
    QLineEdit *emailAddressField;
    QLabel *label_5;
    QLabel *logo;
    QMenuBar *menubar;
    QMenu *menuWelcome_to_Canopy_Search;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName(QStringLiteral("WelcomeWindow"));
        WelcomeWindow->resize(958, 598);
        centralwidget = new QWidget(WelcomeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 50, 591, 91));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 170, 201, 31));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        suspectNameField = new QLineEdit(centralwidget);
        suspectNameField->setObjectName(QStringLiteral("suspectNameField"));
        suspectNameField->setGeometry(QRect(290, 170, 601, 31));
        suspectNameField->setFont(font1);
        warrantNumberField = new QLineEdit(centralwidget);
        warrantNumberField->setObjectName(QStringLiteral("warrantNumberField"));
        warrantNumberField->setGeometry(QRect(290, 220, 601, 31));
        warrantNumberField->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 220, 181, 31));
        label_3->setFont(font1);
        fileFrame = new QFrame(centralwidget);
        fileFrame->setObjectName(QStringLiteral("fileFrame"));
        fileFrame->setGeometry(QRect(230, 330, 441, 171));
        fileFrame->setAutoFillBackground(false);
        fileFrame->setFrameShape(QFrame::StyledPanel);
        fileFrame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(fileFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 421, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        fileNameLabel = new QLabel(fileFrame);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(210, 120, 211, 31));
        fileNameLabel->setFont(font2);
        browseButton = new QPushButton(fileFrame);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(20, 120, 131, 31));
        QFont font3;
        font3.setPointSize(12);
        browseButton->setFont(font3);
        evaluateButton = new QPushButton(centralwidget);
        evaluateButton->setObjectName(QStringLiteral("evaluateButton"));
        evaluateButton->setEnabled(false);
        evaluateButton->setGeometry(QRect(710, 430, 201, 71));
        QFont font4;
        font4.setPointSize(15);
        evaluateButton->setFont(font4);
        emailAddressField = new QLineEdit(centralwidget);
        emailAddressField->setObjectName(QStringLiteral("emailAddressField"));
        emailAddressField->setGeometry(QRect(290, 270, 601, 31));
        emailAddressField->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 270, 181, 31));
        label_5->setFont(font1);
        logo = new QLabel(centralwidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(-40, -20, 241, 111));
        logo->setPixmap(QPixmap(QString::fromUtf8("../images/CanopyLogo-04.png")));
        logo->setScaledContents(true);
        WelcomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WelcomeWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 958, 22));
        menuWelcome_to_Canopy_Search = new QMenu(menubar);
        menuWelcome_to_Canopy_Search->setObjectName(QStringLiteral("menuWelcome_to_Canopy_Search"));
        WelcomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WelcomeWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WelcomeWindow->setStatusBar(statusbar);

        menubar->addAction(menuWelcome_to_Canopy_Search->menuAction());

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QApplication::translate("WelcomeWindow", "MainWindow", 0));
        label->setText(QApplication::translate("WelcomeWindow", "Warranted Email Evaluator", 0));
        label_2->setText(QApplication::translate("WelcomeWindow", "Suspect/Case Name", 0));
        label_3->setText(QApplication::translate("WelcomeWindow", "Warrant Number", 0));
        label_4->setText(QApplication::translate("WelcomeWindow", "Select File or Folder Containing Emails", 0));
        fileNameLabel->setText(QApplication::translate("WelcomeWindow", "No file selected", 0));
        browseButton->setText(QApplication::translate("WelcomeWindow", "Browse", 0));
        evaluateButton->setText(QApplication::translate("WelcomeWindow", "Evaluate", 0));
        label_5->setText(QApplication::translate("WelcomeWindow", "Email Address", 0));
        logo->setText(QString());
        menuWelcome_to_Canopy_Search->setTitle(QApplication::translate("WelcomeWindow", "Welcome to Canopy Search", 0));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
