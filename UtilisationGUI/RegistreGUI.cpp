/**
 * \file RegistreGUI.cpp
 * \brief Implémentation de la classe RegistreGUI
 * \author Amenallah Massarra Ouannes - Rayen Somai
 * \date 21 Avril 2024
 */

#include "RegistreGUI.h"
#include "AjoutFontaine.h"
#include "BorneFontaine.h"
#include "AjoutStationnement.h"
#include "BorneStationnement.h"
#include "BorneException.hpp"
#include "SupprimeBorne.h"
#include <QMessageBox>
#include <iostream>

using namespace tp2;

/**
 * \brief Constructeur de la classe RegistreGUI.
 * Initialise le registre avec le nom "Ville de Québec".
 */
RegistreGUI::RegistreGUI(): MonRegistre("Ville de Québec") {
  widget.setupUi(this);
}

/**
 * \brief Destructeur de la classe RegistreGUI.
 */
RegistreGUI::~RegistreGUI() {}

/**
 * \brief Ouvre la fenêtre d'ajout d'une fontaine.
 * Crée une nouvelle fontaine et l'ajoute au registre.
 */
void RegistreGUI::fenetre_fontaine() {
  AjoutFontaine newFontaine;
  if (newFontaine.exec()) {
    try {
      BorneFontaine newBorne(newFontaine.reqId(), newFontaine.reqVoie().toStdString(), 
                             newFontaine.reqTopo().toStdString(), newFontaine.reqLong(), 
                             newFontaine.reqLat(), newFontaine.reqVille().toStdString(), 
                             newFontaine.reqArr().toStdString());
      this->MonRegistre.ajouteBorne(newBorne);
      widget.affichage->setText(MonRegistre.reqRegistreBorneFormate().c_str());
    } catch (const BorneDejaPresenteException& e) {
      QString message = "La borne est déjà présente dans le registre";
      message.append(e.what());
      QMessageBox::warning(this, "La borne est déjà présente!", message);    
    }
  }
}

/**
 * \brief Ouvre la fenêtre d'ajout d'un stationnement.
 * Crée un nouveau stationnement et l'ajoute au registre.
 */
void RegistreGUI::fenetre_stationnement() {
  AjoutStationnement newStationnement;
  if (newStationnement.exec()) {
    try {
      BorneStationnement newBorne(newStationnement.reqId(), newStationnement.reqVoie().toStdString(), 
                                  newStationnement.reqTopo().toStdString(), newStationnement.reqLong(), 
                                  newStationnement.reqLat(), newStationnement.reqNumBorne(), 
                                  newStationnement.reqCote().toStdString());
      this->MonRegistre.ajouteBorne(newBorne);
      widget.affichage->setText(MonRegistre.reqRegistreBorneFormate().c_str()); 
    } catch (const BorneDejaPresenteException& e) {
      QString message = "La borne est déjà présente dans le registre";
      message.append(e.what());
      QMessageBox::warning(this, "La borne est déjà présente!", message);    
    }
  }
}

/**
 * \brief Ouvre la fenêtre de suppression d'une borne.
 * Supprime une borne du registre.
 */
void RegistreGUI::fenetre_supprimer() {
  SupprimeBorne lostborne;
  if (lostborne.exec()) {
    try {
      this->MonRegistre.supprimeBorne(lostborne.reqId());
    } catch (const BorneAbsenteException& e) {
      QMessageBox::warning(this, "Erreur", e.what());     
    }
    widget.affichage->setText(MonRegistre.reqRegistreBorneFormate().c_str());
  }
}