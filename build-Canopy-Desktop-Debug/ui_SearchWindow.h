/********************************************************************************
** Form generated from reading UI file 'SearchWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindow
{
public:
    QWidget *centralWidget;
    QFrame *suspectFrame;
    QLabel *suspectPortrait;
    QLabel *suspectNameLabel;
    QFrame *infoFrame;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *emailCountLabel;
    QLabel *label;
    QLabel *label_8;
    QLabel *warrantNumberLabel;
    QLabel *sourceLabel;
    QLabel *fileSizeLabel;
    QLabel *dateLabel;
    QLabel *label_5;
    QPushButton *backButton;
    QMenuBar *menuBar;
    QMenu *menuCanopy_Search;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QStringLiteral("SearchWindow"));
        SearchWindow->resize(1250, 891);
        centralWidget = new QWidget(SearchWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        suspectFrame = new QFrame(centralWidget);
        suspectFrame->setObjectName(QStringLiteral("suspectFrame"));
        suspectFrame->setGeometry(QRect(10, 10, 250, 361));
        suspectFrame->setFrameShape(QFrame::StyledPanel);
        suspectFrame->setFrameShadow(QFrame::Raised);
        suspectPortrait = new QLabel(suspectFrame);
        suspectPortrait->setObjectName(QStringLiteral("suspectPortrait"));
        suspectPortrait->setGeometry(QRect(0, 10, 240, 240));
        QFont font;
        font.setKerning(false);
        suspectPortrait->setFont(font);
        suspectPortrait->setAlignment(Qt::AlignCenter);
        suspectNameLabel = new QLabel(suspectFrame);
        suspectNameLabel->setObjectName(QStringLiteral("suspectNameLabel"));
        suspectNameLabel->setGeometry(QRect(10, 300, 230, 50));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        suspectNameLabel->setFont(font1);
        suspectNameLabel->setAlignment(Qt::AlignCenter);
        infoFrame = new QFrame(centralWidget);
        infoFrame->setObjectName(QStringLiteral("infoFrame"));
        infoFrame->setGeometry(QRect(10, 380, 250, 411));
        infoFrame->setFrameShape(QFrame::StyledPanel);
        infoFrame->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(infoFrame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 340, 161, 21));
        label_10->setFont(font1);
        label_3 = new QLabel(infoFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 121, 21));
        label_3->setFont(font1);
        emailCountLabel = new QLabel(infoFrame);
        emailCountLabel->setObjectName(QStringLiteral("emailCountLabel"));
        emailCountLabel->setGeometry(QRect(20, 290, 111, 21));
        QFont font2;
        font2.setPointSize(12);
        emailCountLabel->setFont(font2);
        label = new QLabel(infoFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 121, 21));
        label->setFont(font1);
        label_8 = new QLabel(infoFrame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 260, 121, 21));
        label_8->setFont(font1);
        warrantNumberLabel = new QLabel(infoFrame);
        warrantNumberLabel->setObjectName(QStringLiteral("warrantNumberLabel"));
        warrantNumberLabel->setGeometry(QRect(20, 50, 111, 21));
        warrantNumberLabel->setFont(font2);
        sourceLabel = new QLabel(infoFrame);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));
        sourceLabel->setGeometry(QRect(20, 130, 111, 21));
        sourceLabel->setFont(font2);
        fileSizeLabel = new QLabel(infoFrame);
        fileSizeLabel->setObjectName(QStringLiteral("fileSizeLabel"));
        fileSizeLabel->setGeometry(QRect(20, 210, 111, 21));
        fileSizeLabel->setFont(font2);
        dateLabel = new QLabel(infoFrame);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setGeometry(QRect(20, 370, 111, 21));
        dateLabel->setFont(font2);
        label_5 = new QLabel(infoFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 180, 121, 21));
        label_5->setFont(font1);
        backButton = new QPushButton(centralWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 800, 251, 31));
        QFont font3;
        font3.setPointSize(14);
        backButton->setFont(font3);
        SearchWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SearchWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1250, 22));
        menuCanopy_Search = new QMenu(menuBar);
        menuCanopy_Search->setObjectName(QStringLiteral("menuCanopy_Search"));
        SearchWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SearchWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SearchWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SearchWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SearchWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCanopy_Search->menuAction());

        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SearchWindow)
    {
        SearchWindow->setWindowTitle(QApplication::translate("SearchWindow", "SearchWindow", 0));
        suspectPortrait->setText(QApplication::translate("SearchWindow", "No image", 0));
        suspectNameLabel->setText(QApplication::translate("SearchWindow", "Unknown Suspect", 0));
        label_10->setText(QApplication::translate("SearchWindow", "Date Imported", 0));
        label_3->setText(QApplication::translate("SearchWindow", "Source", 0));
        emailCountLabel->setText(QApplication::translate("SearchWindow", "###", 0));
        label->setText(QApplication::translate("SearchWindow", "Warrant", 0));
        label_8->setText(QApplication::translate("SearchWindow", "# of Emails", 0));
        warrantNumberLabel->setText(QApplication::translate("SearchWindow", "###", 0));
        sourceLabel->setText(QApplication::translate("SearchWindow", "Gmail", 0));
        fileSizeLabel->setText(QApplication::translate("SearchWindow", "## GB", 0));
        dateLabel->setText(QApplication::translate("SearchWindow", "02/27/2019", 0));
        label_5->setText(QApplication::translate("SearchWindow", "Size", 0));
        backButton->setText(QApplication::translate("SearchWindow", "Back", 0));
        menuCanopy_Search->setTitle(QApplication::translate("SearchWindow", "Canopy Search", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
