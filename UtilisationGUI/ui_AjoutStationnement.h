/********************************************************************************
** Form generated from reading UI file 'AjoutStationnement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTSTATIONNEMENT_H
#define UI_AJOUTSTATIONNEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutStationnement
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *case_voie;
    QLineEdit *case_topo;
    QLineEdit *case_cote;
    QSpinBox *case_id;
    QDoubleSpinBox *case_long;
    QDoubleSpinBox *case_lat;
    QSpinBox *case_numborne;
    QPushButton *confirmer_btn;
    QPushButton *Abandonner_btn;

    void setupUi(QDialog *AjoutStationnement)
    {
        if (AjoutStationnement->objectName().isEmpty())
            AjoutStationnement->setObjectName(QString::fromUtf8("AjoutStationnement"));
        AjoutStationnement->resize(834, 563);
        label_2 = new QLabel(AjoutStationnement);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 231, 16));
        label_3 = new QLabel(AjoutStationnement);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 140, 231, 16));
        label_4 = new QLabel(AjoutStationnement);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 210, 231, 16));
        label_5 = new QLabel(AjoutStationnement);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 270, 231, 16));
        label_6 = new QLabel(AjoutStationnement);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 330, 231, 16));
        label_7 = new QLabel(AjoutStationnement);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 390, 231, 16));
        label_8 = new QLabel(AjoutStationnement);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 450, 231, 16));
        case_voie = new QLineEdit(AjoutStationnement);
        case_voie->setObjectName(QString::fromUtf8("case_voie"));
        case_voie->setGeometry(QRect(400, 130, 301, 31));
        case_topo = new QLineEdit(AjoutStationnement);
        case_topo->setObjectName(QString::fromUtf8("case_topo"));
        case_topo->setGeometry(QRect(400, 210, 301, 31));
        case_cote = new QLineEdit(AjoutStationnement);
        case_cote->setObjectName(QString::fromUtf8("case_cote"));
        case_cote->setGeometry(QRect(400, 450, 301, 31));
        case_id = new QSpinBox(AjoutStationnement);
        case_id->setObjectName(QString::fromUtf8("case_id"));
        case_id->setGeometry(QRect(410, 60, 101, 26));
        case_id->setMaximum(100000);
        case_long = new QDoubleSpinBox(AjoutStationnement);
        case_long->setObjectName(QString::fromUtf8("case_long"));
        case_long->setGeometry(QRect(410, 270, 62, 26));
        case_long->setMaximum(9999999999.000000000000000);
        case_lat = new QDoubleSpinBox(AjoutStationnement);
        case_lat->setObjectName(QString::fromUtf8("case_lat"));
        case_lat->setGeometry(QRect(410, 330, 62, 26));
        case_lat->setMaximum(99999.990000000005239);
        case_numborne = new QSpinBox(AjoutStationnement);
        case_numborne->setObjectName(QString::fromUtf8("case_numborne"));
        case_numborne->setGeometry(QRect(410, 390, 91, 26));
        case_numborne->setMaximum(1000000);
        confirmer_btn = new QPushButton(AjoutStationnement);
        confirmer_btn->setObjectName(QString::fromUtf8("confirmer_btn"));
        confirmer_btn->setGeometry(QRect(210, 510, 111, 31));
        Abandonner_btn = new QPushButton(AjoutStationnement);
        Abandonner_btn->setObjectName(QString::fromUtf8("Abandonner_btn"));
        Abandonner_btn->setGeometry(QRect(450, 510, 121, 31));

        retranslateUi(AjoutStationnement);
        QObject::connect(confirmer_btn, SIGNAL(clicked()), AjoutStationnement, SLOT(valider()));
        QObject::connect(Abandonner_btn, SIGNAL(clicked()), AjoutStationnement, SLOT(reject()));

        QMetaObject::connectSlotsByName(AjoutStationnement);
    } // setupUi

    void retranslateUi(QDialog *AjoutStationnement)
    {
        AjoutStationnement->setWindowTitle(QCoreApplication::translate("AjoutStationnement", "AjoutStationnement", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutStationnement", "identifiant de la borne stationnement:", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutStationnement", "identifiant voie publique :", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutStationnement", "nom topographique:", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutStationnement", "Longitude:", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutStationnement", "latitude:", nullptr));
        label_7->setText(QCoreApplication::translate("AjoutStationnement", "Numero de la borne", nullptr));
        label_8->setText(QCoreApplication::translate("AjoutStationnement", "Cote de la rue:", nullptr));
        confirmer_btn->setText(QCoreApplication::translate("AjoutStationnement", "Confirmer", nullptr));
        Abandonner_btn->setText(QCoreApplication::translate("AjoutStationnement", "Abandonner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutStationnement: public Ui_AjoutStationnement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTSTATIONNEMENT_H
