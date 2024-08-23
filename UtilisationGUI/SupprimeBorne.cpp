/**
 * \file SupprimeBorne.cpp
 * \brief Implémentation de la classe SupprimeBorne
 * \author Amenallah Massarra Ouannes - Rayen Somai
 * \date 21 Avril 2024
 */

#include "SupprimeBorne.h"
#include "BorneStationnement.h"
#include <QMessageBox>

/**
 * \brief Constructeur de la classe SupprimeBorne.
 */
SupprimeBorne::SupprimeBorne() {
  widget.setupUi(this);
}

/**
 * \brief Destructeur de la classe SupprimeBorne.
 */
SupprimeBorne::~SupprimeBorne() {}

/**
 * \brief Accesseur de l'identifiant.
 * \return L'identifiant de la borne à supprimer.
 */
int SupprimeBorne::reqId() const {
  return widget.case_id->value();
}

/**
 * \brief Validation de la suppression de la borne.
 * Affiche une boîte de dialogue pour confirmer la suppression.
 * Si l'utilisateur confirme la suppression, la méthode accepte.
 * Sinon, rien ne se passe.
 */
void SupprimeBorne::valider() {
  if (reqId() <= 0) {
    QString message("Saisir un identifiant valide!");
    QMessageBox::information(this, "Erreur!", message);
    return;
  }

  QMessageBox msgBox;
  msgBox.setText("Voulez-vous supprimer la borne?");
  msgBox.setIcon(QMessageBox::Warning);
  msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msgBox.setDefaultButton(QMessageBox::Yes);
  int ret = msgBox.exec();
  switch (ret) {
    case QMessageBox::Yes:
      // Save was clicked
      accept();
      break;
    case QMessageBox::No:
      // retour au formulaire de suppression de borne
      break;
    default:
      // Ce cas n'est pas supposé se produire
      break;
  }

  accept();
}