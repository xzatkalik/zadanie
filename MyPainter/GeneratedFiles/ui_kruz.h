/********************************************************************************
** Form generated from reading UI file 'kruz.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KRUZ_H
#define UI_KRUZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_kruz
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label;
    QSpinBox *spinBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;

    void setupUi(QDialog *kruz)
    {
        if (kruz->objectName().isEmpty())
            kruz->setObjectName(QStringLiteral("kruz"));
        kruz->resize(557, 406);
        verticalLayout = new QVBoxLayout(kruz);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_3 = new QPushButton(kruz);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(kruz);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBox = new QSpinBox(kruz);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(3);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox);

        label = new QLabel(kruz);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        spinBox_2 = new QSpinBox(kruz);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(10);
        spinBox_2->setMaximum(999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_2);

        radioButton = new QRadioButton(kruz);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, radioButton);

        radioButton_2 = new QRadioButton(kruz);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        formLayout->setWidget(4, QFormLayout::FieldRole, radioButton_2);

        pushButton = new QPushButton(kruz);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton);


        horizontalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_3 = new QLabel(kruz);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(kruz);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        spinBox_3 = new QSpinBox(kruz);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(999);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBox_3);

        pushButton_4 = new QPushButton(kruz);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pushButton_4);


        horizontalLayout->addLayout(formLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_2 = new QPushButton(kruz);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(kruz);
        QObject::connect(pushButton, SIGNAL(clicked()), kruz, SLOT(kresli()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), kruz, SLOT(close()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), kruz, SLOT(farba()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), kruz, SLOT(kreslikruznicu()));

        QMetaObject::connectSlotsByName(kruz);
    } // setupUi

    void retranslateUi(QDialog *kruz)
    {
        kruz->setWindowTitle(QApplication::translate("kruz", "kruz", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("kruz", "Zvol farbu", Q_NULLPTR));
        label_2->setText(QApplication::translate("kruz", "Pocet bodov: ", Q_NULLPTR));
        label->setText(QApplication::translate("kruz", "Polomer kruznice:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("kruz", "DDA", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("kruz", "Bresenhamov algoritmus", Q_NULLPTR));
        pushButton->setText(QApplication::translate("kruz", "Kresli", Q_NULLPTR));
        label_3->setText(QApplication::translate("kruz", "Rasterizacia kruznice", Q_NULLPTR));
        label_4->setText(QApplication::translate("kruz", "polomer kruznice", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("kruz", "Kresli", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("kruz", "koniec", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class kruz: public Ui_kruz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KRUZ_H
