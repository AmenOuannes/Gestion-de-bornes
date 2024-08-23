/********************************************************************************
** Form generated from reading UI file 'SupprimeBorne.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMEBORNE_H
#define UI_SUPPRIMEBORNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SupprimeBorne
{
public:
    QPushButton *annuler_btn;
    QPushButton *supprime_btn;
    QLabel *label;
    QSpinBox *case_id;

    void setupUi(QDialog *SupprimeBorne)
    {
        if (SupprimeBorne->objectName().isEmpty())
            SupprimeBorne->setObjectName(QString::fromUtf8("SupprimeBorne"));
        SupprimeBorne->resize(836, 451);
        annuler_btn = new QPushButton(SupprimeBorne);
        annuler_btn->setObjectName(QString::fromUtf8("annuler_btn"));
        annuler_btn->setGeometry(QRect(490, 280, 90, 28));
        supprime_btn = new QPushButton(SupprimeBorne);
        supprime_btn->setObjectName(QString::fromUtf8("supprime_btn"));
        supprime_btn->setGeometry(QRect(230, 280, 90, 28));
        label = new QLabel(SupprimeBorne);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 150, 281, 16));
        case_id = new QSpinBox(SupprimeBorne);
        case_id->setObjectName(QString::fromUtf8("case_id"));
        case_id->setGeometry(QRect(430, 140, 101, 26));
        case_id->setMaximum(1000000000);

        retranslateUi(SupprimeBorne);
        QObject::connect(supprime_btn, SIGNAL(clicked()), SupprimeBorne, SLOT(valider()));
        QObject::connect(annuler_btn, SIGNAL(clicked()), SupprimeBorne, SLOT(reject()));

        QMetaObject::connectSlotsByName(SupprimeBorne);
    } // setupUi

    void retranslateUi(QDialog *SupprimeBorne)
    {
        SupprimeBorne->setWindowTitle(QCoreApplication::translate("SupprimeBorne", "SupprimeBorne", nullptr));
        annuler_btn->setText(QCoreApplication::translate("SupprimeBorne", "annuler", nullptr));
        supprime_btn->setText(QCoreApplication::translate("SupprimeBorne", "supprimer", nullptr));
        label->setText(QCoreApplication::translate("SupprimeBorne", "Donner l'identifiant de la borne \303\240 supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimeBorne: public Ui_SupprimeBorne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMEBORNE_H
