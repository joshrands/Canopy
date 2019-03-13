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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QFrame *frame;
    QLabel *label_2;
    QPushButton *searchButton;
    QPushButton *inButton;
    QPushButton *outButton;
    QFrame *emailFrame;
    QVBoxLayout *verticalLayout;
    QFrame *titleFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QScrollArea *emailHeaderList;
    QWidget *emailScrollArea;
    QFrame *searchFrame;
    QLabel *label_4;
    QLineEdit *keywordInput;
    QLabel *label_6;
    QDateEdit *startDate;
    QLabel *label_7;
    QDateEdit *endDate;
    QPushButton *addKeywordButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *doSearchButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *keywordBank;
    QFormLayout *formLayout;
    QFrame *freqFrame;
    QLabel *freqTitle;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QScrollArea *freqCountScrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_13;
    QLineEdit *wordFreqFilter;
    QPushButton *closeButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QMenuBar *menuBar;
    QMenu *menuCanopy_Search;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QStringLiteral("SearchWindow"));
        SearchWindow->resize(1308, 891);
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
        label->setGeometry(QRect(20, 20, 221, 21));
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
        backButton->setGeometry(QRect(134, 800, 121, 31));
        QFont font3;
        font3.setPointSize(14);
        backButton->setFont(font3);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(260, 10, 751, 51));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 50, 50));
        QFont font4;
        font4.setPointSize(27);
        label_2->setFont(font4);
        label_2->setAlignment(Qt::AlignCenter);
        searchButton = new QPushButton(frame);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(50, 5, 481, 41));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        searchButton->setFont(font5);
        inButton = new QPushButton(frame);
        inButton->setObjectName(QStringLiteral("inButton"));
        inButton->setGeometry(QRect(544, 5, 101, 41));
        inButton->setFont(font5);
        outButton = new QPushButton(frame);
        outButton->setObjectName(QStringLiteral("outButton"));
        outButton->setGeometry(QRect(645, 5, 101, 41));
        outButton->setFont(font5);
        emailFrame = new QFrame(centralWidget);
        emailFrame->setObjectName(QStringLiteral("emailFrame"));
        emailFrame->setGeometry(QRect(260, 60, 751, 771));
        emailFrame->setFrameShape(QFrame::StyledPanel);
        emailFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(emailFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titleFrame = new QFrame(emailFrame);
        titleFrame->setObjectName(QStringLiteral("titleFrame"));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(titleFrame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_9 = new QLabel(titleFrame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font3);

        horizontalLayout->addWidget(label_9);

        label_11 = new QLabel(titleFrame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font3);

        horizontalLayout->addWidget(label_11);

        label_12 = new QLabel(titleFrame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font3);

        horizontalLayout->addWidget(label_12);


        verticalLayout->addWidget(titleFrame);

        emailHeaderList = new QScrollArea(emailFrame);
        emailHeaderList->setObjectName(QStringLiteral("emailHeaderList"));
        emailHeaderList->setWidgetResizable(true);
        emailScrollArea = new QWidget();
        emailScrollArea->setObjectName(QStringLiteral("emailScrollArea"));
        emailScrollArea->setGeometry(QRect(0, 0, 729, 701));
        emailHeaderList->setWidget(emailScrollArea);

        verticalLayout->addWidget(emailHeaderList);

        searchFrame = new QFrame(centralWidget);
        searchFrame->setObjectName(QStringLiteral("searchFrame"));
        searchFrame->setGeometry(QRect(260, 60, 751, 771));
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(searchFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 16, 141, 31));
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        keywordInput = new QLineEdit(searchFrame);
        keywordInput->setObjectName(QStringLiteral("keywordInput"));
        keywordInput->setGeometry(QRect(170, 10, 481, 41));
        keywordInput->setFont(font2);
        label_6 = new QLabel(searchFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 60, 141, 31));
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        startDate = new QDateEdit(searchFrame);
        startDate->setObjectName(QStringLiteral("startDate"));
        startDate->setGeometry(QRect(170, 55, 251, 41));
        label_7 = new QLabel(searchFrame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 105, 141, 31));
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        endDate = new QDateEdit(searchFrame);
        endDate->setObjectName(QStringLiteral("endDate"));
        endDate->setGeometry(QRect(170, 100, 251, 41));
        addKeywordButton = new QPushButton(searchFrame);
        addKeywordButton->setObjectName(QStringLiteral("addKeywordButton"));
        addKeywordButton->setGeometry(QRect(660, 10, 81, 41));
        layoutWidget = new QWidget(searchFrame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 150, 731, 331));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(300, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        doSearchButton = new QPushButton(layoutWidget);
        doSearchButton->setObjectName(QStringLiteral("doSearchButton"));

        horizontalLayout_4->addWidget(doSearchButton);

        horizontalSpacer_2 = new QSpacerItem(300, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        formLayout_2->setLayout(1, QFormLayout::SpanningRole, horizontalLayout_4);

        keywordBank = new QFrame(layoutWidget);
        keywordBank->setObjectName(QStringLiteral("keywordBank"));
        keywordBank->setFrameShape(QFrame::StyledPanel);
        keywordBank->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(keywordBank);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setContentsMargins(-1, 6, -1, -1);

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, keywordBank);

        freqFrame = new QFrame(centralWidget);
        freqFrame->setObjectName(QStringLiteral("freqFrame"));
        freqFrame->setGeometry(QRect(1010, 10, 291, 811));
        freqFrame->setFrameShape(QFrame::StyledPanel);
        freqFrame->setFrameShadow(QFrame::Raised);
        freqTitle = new QLabel(freqFrame);
        freqTitle->setObjectName(QStringLiteral("freqTitle"));
        freqTitle->setGeometry(QRect(10, 7, 271, 41));
        QFont font6;
        font6.setPointSize(18);
        freqTitle->setFont(font6);
        freqTitle->setAlignment(Qt::AlignCenter);
        frame_5 = new QFrame(freqFrame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(5, 48, 281, 41));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_14 = new QLabel(frame_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_14);

        label_15 = new QLabel(frame_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_15);

        label_16 = new QLabel(frame_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_16);

        freqCountScrollArea = new QScrollArea(freqFrame);
        freqCountScrollArea->setObjectName(QStringLiteral("freqCountScrollArea"));
        freqCountScrollArea->setGeometry(QRect(5, 94, 281, 681));
        freqCountScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 279, 679));
        freqCountScrollArea->setWidget(scrollAreaWidgetContents);
        label_13 = new QLabel(freqFrame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(19, 783, 67, 17));
        QFont font7;
        font7.setPointSize(13);
        label_13->setFont(font7);
        wordFreqFilter = new QLineEdit(freqFrame);
        wordFreqFilter->setObjectName(QStringLiteral("wordFreqFilter"));
        wordFreqFilter->setGeometry(QRect(84, 780, 201, 25));
        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(10, 800, 121, 31));
        closeButton->setFont(font3);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        SearchWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        searchFrame->raise();
        suspectFrame->raise();
        infoFrame->raise();
        backButton->raise();
        frame->raise();
        emailFrame->raise();
        freqFrame->raise();
        closeButton->raise();
        menuBar = new QMenuBar(SearchWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1308, 22));
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
        label->setText(QApplication::translate("SearchWindow", "Warrant Number", 0));
        label_8->setText(QApplication::translate("SearchWindow", "# of Emails", 0));
        warrantNumberLabel->setText(QApplication::translate("SearchWindow", "###", 0));
        sourceLabel->setText(QApplication::translate("SearchWindow", "Gmail", 0));
        fileSizeLabel->setText(QApplication::translate("SearchWindow", "## GB", 0));
        dateLabel->setText(QApplication::translate("SearchWindow", "02/27/2019", 0));
        label_5->setText(QApplication::translate("SearchWindow", "Size", 0));
        backButton->setText(QApplication::translate("SearchWindow", "Back", 0));
        label_2->setText(QApplication::translate("SearchWindow", "O", 0));
        searchButton->setText(QApplication::translate("SearchWindow", "OPEN SEARCH", 0));
        inButton->setText(QApplication::translate("SearchWindow", "IN", 0));
        outButton->setText(QApplication::translate("SearchWindow", "OUT", 0));
        label_9->setText(QApplication::translate("SearchWindow", "Email", 0));
        label_11->setText(QApplication::translate("SearchWindow", "Subject Header", 0));
        label_12->setText(QApplication::translate("SearchWindow", "Date", 0));
        label_4->setText(QApplication::translate("SearchWindow", "Keyword/User:", 0));
        label_6->setText(QApplication::translate("SearchWindow", "Start Date:", 0));
        label_7->setText(QApplication::translate("SearchWindow", "End Date:", 0));
        addKeywordButton->setText(QApplication::translate("SearchWindow", "ADD", 0));
        doSearchButton->setText(QApplication::translate("SearchWindow", "SEARCH", 0));
        freqTitle->setText(QApplication::translate("SearchWindow", "Frequency", 0));
        label_14->setText(QApplication::translate("SearchWindow", "Rank", 0));
        label_15->setText(QApplication::translate("SearchWindow", "Word", 0));
        label_16->setText(QApplication::translate("SearchWindow", "Frequency", 0));
        label_13->setText(QApplication::translate("SearchWindow", "Search:", 0));
        closeButton->setText(QApplication::translate("SearchWindow", "Close", 0));
        menuCanopy_Search->setTitle(QApplication::translate("SearchWindow", "Canopy Search", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
