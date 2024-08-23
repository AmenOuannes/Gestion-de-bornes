/**
 * \file RegistreBorne.cpp
 * \brief Implémentation de la classe RegistreBorne
 * \author Amenallah Massarra Ouannes - Rayen Somai
 * \date 21 Avril 2024
 */


#include "AjoutStationnement.h"
#include <QMessageBox>

#include "validationFormat.h"
/**
 * \brief Constructeur de la classe AjoutStationnement.
 */
AjoutStationnement::AjoutStationnement ()
{
  widget.setupUi (this);
}
/**
 * \brief Destructeur de la classe AjoutStationnement.
 */
AjoutStationnement::~AjoutStationnement () { }

/**
 * \brief Accesseur de l'identifiant.
 * \return L'identifiant du stationnement.
 */
 int AjoutStationnement::reqId()const{
    return widget.case_id->value();
  }
 /**
 * \brief Accesseur de la voie.
 * \return La voie du stationnement.
 */
  QString AjoutStationnement::reqVoie()const{
    return widget.case_voie->text();
  }
  /**
 * \brief Accesseur du nom topographique.
 * \return Le nom topographique du stationnement.
 */
  QString AjoutStationnement::reqTopo()const{
    return widget.case_topo->text();
  }
  /**
 * \brief Accesseur de la longitude.
 * \return La longitude du stationnement.
 */
  double AjoutStationnement::reqLong()const{
    return widget.case_long->value();
  }
  /**
 * \brief Accesseur de la latitude.
 * \return La latitude du stationnement.
 */
double AjoutStationnement::reqLat() const {
  return widget.case_lat->value();
}

/**
 * \brief Accesseur du numéro de borne.
 * \return Le numéro de la borne du stationnement.
 */
int AjoutStationnement::reqNumBorne() const {
  return widget.case_numborne->value();
}

/**
 * \brief Accesseur du côté de la rue.
 * \return Le côté de la rue du stationnement.
 */
QString AjoutStationnement::reqCote() const {
  return widget.case_cote->text();
}

/**
 * \brief Validation des données du stationnement.
 * Vérifie les contraintes sur les données du stationnement et affiche une boîte de dialogue en cas d'erreur.
 */
void AjoutStationnement::valider() {
  if (reqId() <= 0) {
    QString message("L'identifiant doit être positif!");
    QMessageBox::information(this, "Erreur!", message);
    return;
  }

  std::string voie = reqVoie().toStdString();

  if (!std::all_of(voie.begin(), voie.end(), ::isdigit) && !reqVoie().isEmpty()) {
    QString message("L'identifiant de voie doit être un chiffre ou vide!");
    QMessageBox::information(this, "Erreur!", message);
    return;
  }

  if (reqTopo().isEmpty()) {
    QString message("Le nom topographique ne doit pas être vide!");
    QMessageBox::information(this, "Erreur!", message);
    return;
  }

  if (!(reqNumBorne() >= 0 && reqNumBorne() <= 9999)) {
    QString message("Le numéro de la borne est composé d'un maximum de 4 chiffres!");
    QMessageBox::information(this, "Erreur!", message);
    return;
  }

  std::string cote = reqCote().toStdString();
  if (!util::validePointCardinal(cote)) {
    QString message("Entrez le côté de la rue (N, S, E, O)");
    QMessageBox::information(this, "Erreur!", message);
    return;
  }

  accept();
}