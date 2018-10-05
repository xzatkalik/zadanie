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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
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
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEffects;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyPainterClass)
    {
        if (MyPainterClass->objectName().isEmpty())
            MyPainterClass->setObjectName(QStringLiteral("MyPainterClass"));
        MyPainterClass->resize(576, 396);
        actionOpen = new QAction(MyPainterClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MyPainterClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
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

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(groupBox);


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
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 290, 333));
        scrollArea->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout->addWidget(scrollArea);


        horizontalLayout_2->addLayout(horizontalLayout);

        MyPainterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyPainterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 576, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEffects = new QMenu(menuBar);
        menuEffects->setObjectName(QStringLiteral("menuEffects"));
        MyPainterClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MyPainterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyPainterClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEffects->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuEffects->addAction(actionRotate_left);
        menuEffects->addAction(actionRotate_right);

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

        QMetaObject::connectSlotsByName(MyPainterClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyPainterClass)
    {
        MyPainterClass->setWindowTitle(QApplication::translate("MyPainterClass", "MyPainter", Q_NULLPTR));
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
        groupBox->setTitle(QString());
        menuFile->setTitle(QApplication::translate("MyPainterClass", "File", Q_NULLPTR));
        menuEffects->setTitle(QApplication::translate("MyPainterClass", "Effects", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyPainterClass: public Ui_MyPainterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPAINTER_H
