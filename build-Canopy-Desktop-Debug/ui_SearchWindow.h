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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QStringLiteral("SearchWindow"));
        SearchWindow->resize(400, 300);
        menuBar = new QMenuBar(SearchWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SearchWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SearchWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SearchWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(SearchWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SearchWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SearchWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SearchWindow->setStatusBar(statusBar);

        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SearchWindow)
    {
        SearchWindow->setWindowTitle(QApplication::translate("SearchWindow", "SearchWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
