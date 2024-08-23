/********************************************************************************
** Form generated from reading UI file 'RegistreGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTREGUI_H
#define UI_REGISTREGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistreGUI
{
public:
    QAction *actionBorne_Fontaine;
    QAction *actionBorne_Stationnement;
    QAction *actionSupprimer_une_Borne;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_une_Borne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegistreGUI)
    {
        if (RegistreGUI->objectName().isEmpty())
            RegistreGUI->setObjectName(QString::fromUtf8("RegistreGUI"));
        RegistreGUI->resize(800, 600);
        actionBorne_Fontaine = new QAction(RegistreGUI);
        actionBorne_Fontaine->setObjectName(QString::fromUtf8("actionBorne_Fontaine"));
        actionBorne_Stationnement = new QAction(RegistreGUI);
        actionBorne_Stationnement->setObjectName(QString::fromUtf8("actionBorne_Stationnement"));
        actionSupprimer_une_Borne = new QAction(RegistreGUI);
        actionSupprimer_une_Borne->setObjectName(QString::fromUtf8("actionSupprimer_une_Borne"));
        actionQuitter = new QAction(RegistreGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(RegistreGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(60, 40, 661, 441));
        RegistreGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegistreGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_une_Borne = new QMenu(menuMenu);
        menuAjouter_une_Borne->setObjectName(QString::fromUtf8("menuAjouter_une_Borne"));
        RegistreGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(RegistreGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RegistreGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_une_Borne->menuAction());
        menuMenu->addAction(actionSupprimer_une_Borne);
        menuMenu->addAction(actionQuitter);
        menuAjouter_une_Borne->addAction(actionBorne_Fontaine);
        menuAjouter_une_Borne->addAction(actionBorne_Stationnement);

        retranslateUi(RegistreGUI);
        QObject::connect(actionQuitter, SIGNAL(triggered()), RegistreGUI, SLOT(close()));
        QObject::connect(actionBorne_Fontaine, SIGNAL(triggered()), RegistreGUI, SLOT(fenetre_fontaine()));
        QObject::connect(actionBorne_Stationnement, SIGNAL(triggered()), RegistreGUI, SLOT(fenetre_stationnement()));
        QObject::connect(actionSupprimer_une_Borne, SIGNAL(triggered()), RegistreGUI, SLOT(fenetre_supprimer()));

        QMetaObject::connectSlotsByName(RegistreGUI);
    } // setupUi

    void retranslateUi(QMainWindow *RegistreGUI)
    {
        RegistreGUI->setWindowTitle(QCoreApplication::translate("RegistreGUI", "RegistreGUI", nullptr));
        actionBorne_Fontaine->setText(QCoreApplication::translate("RegistreGUI", "Borne Fontaine", nullptr));
        actionBorne_Stationnement->setText(QCoreApplication::translate("RegistreGUI", "Borne Stationnement", nullptr));
        actionSupprimer_une_Borne->setText(QCoreApplication::translate("RegistreGUI", "Supprimer une Borne", nullptr));
        actionQuitter->setText(QCoreApplication::translate("RegistreGUI", "Quitter", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("RegistreGUI", "Menu", nullptr));
        menuAjouter_une_Borne->setTitle(QCoreApplication::translate("RegistreGUI", "Ajouter une Borne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistreGUI: public Ui_RegistreGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTREGUI_H
