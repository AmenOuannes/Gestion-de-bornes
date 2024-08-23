/********************************************************************************
** Form generated from reading UI file 'AjoutFontaine.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTFONTAINE_H
#define UI_AJOUTFONTAINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutFontaine
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *case_voiepublique;
    QLineEdit *case_topographique;
    QLineEdit *case_ville;
    QLineEdit *case_arrondissement;
    QPushButton *button_confirmer;
    QSpinBox *case_identifiant;
    QDoubleSpinBox *case_longitude;
    QDoubleSpinBox *case_latitude;
    QPushButton *abandonner_btn;

    void setupUi(QDialog *AjoutFontaine)
    {
        if (AjoutFontaine->objectName().isEmpty())
            AjoutFontaine->setObjectName(QString::fromUtf8("AjoutFontaine"));
        AjoutFontaine->resize(1002, 791);
        label = new QLabel(AjoutFontaine);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 80, 211, 31));
        label_2 = new QLabel(AjoutFontaine);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 140, 171, 41));
        label_3 = new QLabel(AjoutFontaine);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 220, 191, 31));
        label_4 = new QLabel(AjoutFontaine);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 290, 191, 31));
        label_5 = new QLabel(AjoutFontaine);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 360, 191, 31));
        label_6 = new QLabel(AjoutFontaine);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 410, 191, 31));
        label_7 = new QLabel(AjoutFontaine);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 490, 191, 31));
        case_voiepublique = new QLineEdit(AjoutFontaine);
        case_voiepublique->setObjectName(QString::fromUtf8("case_voiepublique"));
        case_voiepublique->setGeometry(QRect(390, 150, 481, 31));
        case_topographique = new QLineEdit(AjoutFontaine);
        case_topographique->setObjectName(QString::fromUtf8("case_topographique"));
        case_topographique->setGeometry(QRect(390, 220, 481, 31));
        case_ville = new QLineEdit(AjoutFontaine);
        case_ville->setObjectName(QString::fromUtf8("case_ville"));
        case_ville->setGeometry(QRect(390, 420, 481, 31));
        case_arrondissement = new QLineEdit(AjoutFontaine);
        case_arrondissement->setObjectName(QString::fromUtf8("case_arrondissement"));
        case_arrondissement->setGeometry(QRect(390, 490, 481, 31));
        button_confirmer = new QPushButton(AjoutFontaine);
        button_confirmer->setObjectName(QString::fromUtf8("button_confirmer"));
        button_confirmer->setGeometry(QRect(400, 657, 141, 31));
        case_identifiant = new QSpinBox(AjoutFontaine);
        case_identifiant->setObjectName(QString::fromUtf8("case_identifiant"));
        case_identifiant->setGeometry(QRect(430, 80, 221, 26));
        case_identifiant->setMaximum(1000000000);
        case_longitude = new QDoubleSpinBox(AjoutFontaine);
        case_longitude->setObjectName(QString::fromUtf8("case_longitude"));
        case_longitude->setGeometry(QRect(440, 300, 211, 26));
        case_longitude->setMaximum(999999.989999999990687);
        case_latitude = new QDoubleSpinBox(AjoutFontaine);
        case_latitude->setObjectName(QString::fromUtf8("case_latitude"));
        case_latitude->setGeometry(QRect(440, 370, 211, 26));
        case_latitude->setMaximum(999999.989999999990687);
        abandonner_btn = new QPushButton(AjoutFontaine);
        abandonner_btn->setObjectName(QString::fromUtf8("abandonner_btn"));
        abandonner_btn->setGeometry(QRect(400, 720, 141, 31));

        retranslateUi(AjoutFontaine);
        QObject::connect(button_confirmer, SIGNAL(clicked()), AjoutFontaine, SLOT(valider()));
        QObject::connect(abandonner_btn, SIGNAL(clicked()), AjoutFontaine, SLOT(reject()));

        QMetaObject::connectSlotsByName(AjoutFontaine);
    } // setupUi

    void retranslateUi(QDialog *AjoutFontaine)
    {
        AjoutFontaine->setWindowTitle(QCoreApplication::translate("AjoutFontaine", "AjoutFontaine", nullptr));
        label->setText(QCoreApplication::translate("AjoutFontaine", "Numero de la borne fontaine:", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutFontaine", "Identifiant voie publique:", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutFontaine", "Nom topographique:", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutFontaine", "Longitude:", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutFontaine", "Latitude:", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutFontaine", "Ville:", nullptr));
        label_7->setText(QCoreApplication::translate("AjoutFontaine", "Arrondissement:", nullptr));
        button_confirmer->setText(QCoreApplication::translate("AjoutFontaine", "Confirmer", nullptr));
        abandonner_btn->setText(QCoreApplication::translate("AjoutFontaine", "Abandonner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutFontaine: public Ui_AjoutFontaine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTFONTAINE_H
