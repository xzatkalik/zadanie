/********************************************************************************
** Form generated from reading UI file 'mypainter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPAINTER_H
#define UI_MYPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyPainterClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClear;
    QAction *actionNew;
    QAction *actionNegative;
    QAction *actionSlow_Negative;
    QAction *actionMedium_Negative;
    QAction *actionSalt_Pepper;
    QAction *actionMedian_filter;
    QAction *actionRotate_left;
    QAction *actionRotate_right;
    QAction *actionKruznica;
    QAction *actionverzia_1;
    QAction *actionExit;
    QAction *actionAverage_algorithm;
    QAction *actionWeightened;
    QAction *actionGrayscale;
    QAction *actionClose;
    QAction *actionGrayscale_Weightened;
    QAction *actionGrayscale_Desaturation;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QScrollArea *scrollAreaHistogram;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEffects;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MyPainterClass)
    {
        if (MyPainterClass->objectName().isEmpty())
            MyPainterClass->setObjectName(QStringLiteral("MyPainterClass"));
        MyPainterClass->resize(552, 440);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ikonky/resources/icon_application.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MyPainterClass->setWindowIcon(icon);
        actionOpen = new QAction(MyPainterClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/newPrefix/resources/must_have_icon_set/Open/Open_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MyPainterClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/newPrefix/resources/must_have_icon_set/Save/Save_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionClear = new QAction(MyPainterClass);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionNew = new QAction(MyPainterClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionNegative = new QAction(MyPainterClass);
        actionNegative->setObjectName(QStringLiteral("actionNegative"));
        actionSlow_Negative = new QAction(MyPainterClass);
        actionSlow_Negative->setObjectName(QStringLiteral("actionSlow_Negative"));
        actionMedium_Negative = new QAction(MyPainterClass);
        actionMedium_Negative->setObjectName(QStringLiteral("actionMedium_Negative"));
        actionSalt_Pepper = new QAction(MyPainterClass);
        actionSalt_Pepper->setObjectName(QStringLiteral("actionSalt_Pepper"));
        actionMedian_filter = new QAction(MyPainterClass);
        actionMedian_filter->setObjectName(QStringLiteral("actionMedian_filter"));
        actionRotate_left = new QAction(MyPainterClass);
        actionRotate_left->setObjectName(QStringLiteral("actionRotate_left"));
        actionRotate_right = new QAction(MyPainterClass);
        actionRotate_right->setObjectName(QStringLiteral("actionRotate_right"));
        actionKruznica = new QAction(MyPainterClass);
        actionKruznica->setObjectName(QStringLiteral("actionKruznica"));
        actionverzia_1 = new QAction(MyPainterClass);
        actionverzia_1->setObjectName(QStringLiteral("actionverzia_1"));
        actionverzia_1->setCheckable(true);
        actionExit = new QAction(MyPainterClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/newPrefix/resources/must_have_icon_set/Delete/Delete_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionAverage_algorithm = new QAction(MyPainterClass);
        actionAverage_algorithm->setObjectName(QStringLiteral("actionAverage_algorithm"));
        actionAverage_algorithm->setCheckable(true);
        actionWeightened = new QAction(MyPainterClass);
        actionWeightened->setObjectName(QStringLiteral("actionWeightened"));
        actionWeightened->setCheckable(true);
        actionGrayscale = new QAction(MyPainterClass);
        actionGrayscale->setObjectName(QStringLiteral("actionGrayscale"));
        actionGrayscale->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/ikonky/resources/icon_grayscale1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionGrayscale->setIcon(icon4);
        actionClose = new QAction(MyPainterClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionGrayscale_Weightened = new QAction(MyPainterClass);
        actionGrayscale_Weightened->setObjectName(QStringLiteral("actionGrayscale_Weightened"));
        actionGrayscale_Weightened->setCheckable(true);
        actionGrayscale_Weightened->setIcon(icon4);
        actionGrayscale_Desaturation = new QAction(MyPainterClass);
        actionGrayscale_Desaturation->setObjectName(QStringLiteral("actionGrayscale_Desaturation"));
        actionGrayscale_Desaturation->setCheckable(true);
        actionGrayscale_Desaturation->setIcon(icon4);
        centralWidget = new QWidget(MyPainterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(listWidget);

        scrollAreaHistogram = new QScrollArea(centralWidget);
        scrollAreaHistogram->setObjectName(QStringLiteral("scrollAreaHistogram"));
        scrollAreaHistogram->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 260, 128));
        scrollAreaHistogram->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollAreaHistogram);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 260, 326));
        scrollArea->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout->addWidget(scrollArea);


        horizontalLayout_2->addLayout(horizontalLayout);

        MyPainterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyPainterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 552, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEffects = new QMenu(menuBar);
        menuEffects->setObjectName(QStringLiteral("menuEffects"));
        MyPainterClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MyPainterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyPainterClass->setStatusBar(statusBar);
        toolBar = new QToolBar(MyPainterClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MyPainterClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEffects->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuEffects->addAction(actionRotate_left);
        menuEffects->addAction(actionRotate_right);
        menuEffects->addAction(actionGrayscale);
        menuEffects->addAction(actionGrayscale_Weightened);
        menuEffects->addAction(actionGrayscale_Desaturation);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionGrayscale);
        toolBar->addAction(actionGrayscale_Weightened);
        toolBar->addAction(actionGrayscale_Desaturation);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);

        retranslateUi(MyPainterClass);
        QObject::connect(actionOpen, SIGNAL(triggered()), MyPainterClass, SLOT(ActionOpen()));
        QObject::connect(actionSave, SIGNAL(triggered()), MyPainterClass, SLOT(ActionSave()));
        QObject::connect(actionClear, SIGNAL(triggered()), MyPainterClass, SLOT(EffectClear()));
        QObject::connect(actionNew, SIGNAL(triggered()), MyPainterClass, SLOT(ActionNew()));
        QObject::connect(actionNegative, SIGNAL(triggered()), MyPainterClass, SLOT(ActionNegative()));
        QObject::connect(actionSlow_Negative, SIGNAL(triggered()), MyPainterClass, SLOT(ActionBlackWhite()));
        QObject::connect(actionMedium_Negative, SIGNAL(triggered()), MyPainterClass, SLOT(ActionSepiaTone()));
        QObject::connect(actionMedian_filter, SIGNAL(triggered()), MyPainterClass, SLOT(ActionMedian()));
        QObject::connect(actionSalt_Pepper, SIGNAL(triggered()), MyPainterClass, SLOT(ActionSaltPepper()));
        QObject::connect(actionRotate_left, SIGNAL(triggered()), MyPainterClass, SLOT(ActionLeft()));
        QObject::connect(actionRotate_right, SIGNAL(triggered()), MyPainterClass, SLOT(ActionRight()));
        QObject::connect(actionKruznica, SIGNAL(triggered()), MyPainterClass, SLOT(kruznicamenu()));
        QObject::connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MyPainterClass, SLOT(zmena_itemu()));
        QObject::connect(actionExit, SIGNAL(triggered()), MyPainterClass, SLOT(close()));
        QObject::connect(actionGrayscale, SIGNAL(triggered()), MyPainterClass, SLOT(grayscale_ave()));
        QObject::connect(actionClose, SIGNAL(triggered()), MyPainterClass, SLOT(vymaz_item()));
        QObject::connect(actionGrayscale_Desaturation, SIGNAL(triggered()), MyPainterClass, SLOT(grayscale_des()));
        QObject::connect(actionGrayscale_Weightened, SIGNAL(triggered()), MyPainterClass, SLOT(grayscale_wei()));

        QMetaObject::connectSlotsByName(MyPainterClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyPainterClass)
    {
        MyPainterClass->setWindowTitle(QApplication::translate("MyPainterClass", "Projekt", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MyPainterClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MyPainterClass", "Save", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MyPainterClass", "Clear", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MyPainterClass", "New", Q_NULLPTR));
        actionNegative->setText(QApplication::translate("MyPainterClass", "Negative", Q_NULLPTR));
        actionSlow_Negative->setText(QApplication::translate("MyPainterClass", "Black-White", Q_NULLPTR));
        actionMedium_Negative->setText(QApplication::translate("MyPainterClass", "Sepia", Q_NULLPTR));
        actionSalt_Pepper->setText(QApplication::translate("MyPainterClass", "Salt-Pepper", Q_NULLPTR));
        actionMedian_filter->setText(QApplication::translate("MyPainterClass", "Median filter", Q_NULLPTR));
        actionRotate_left->setText(QApplication::translate("MyPainterClass", "Rotate left", Q_NULLPTR));
        actionRotate_right->setText(QApplication::translate("MyPainterClass", "Rotate right", Q_NULLPTR));
        actionKruznica->setText(QApplication::translate("MyPainterClass", "Kruznica", Q_NULLPTR));
        actionverzia_1->setText(QApplication::translate("MyPainterClass", "verzia_1", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MyPainterClass", "Exit", Q_NULLPTR));
        actionAverage_algorithm->setText(QApplication::translate("MyPainterClass", "Average algorithm", Q_NULLPTR));
        actionWeightened->setText(QApplication::translate("MyPainterClass", "Weightened", Q_NULLPTR));
        actionGrayscale->setText(QApplication::translate("MyPainterClass", "Grayscale Average", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MyPainterClass", "Close", Q_NULLPTR));
        actionGrayscale_Weightened->setText(QApplication::translate("MyPainterClass", "Grayscale Weightened", Q_NULLPTR));
        actionGrayscale_Desaturation->setText(QApplication::translate("MyPainterClass", "Grayscale Desaturation", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MyPainterClass", "File", Q_NULLPTR));
        menuEffects->setTitle(QApplication::translate("MyPainterClass", "Effects", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MyPainterClass", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyPainterClass: public Ui_MyPainterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPAINTER_H
