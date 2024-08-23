/**
 * \file RegistreBorne.cpp
 * \brief Implémentation de la classe RegistreBorne
 * \author Amenallah Massarra Ouannes - Rayen Somai
 * \date 21 Avril 2024
 */

#include "AjoutFontaine.h"
#include <QMessageBox>
#include <iostream>
#include<algorithm>


/**
 * \brief Constructeur de la classe AjoutFontaine.
 */
AjoutFontaine::AjoutFontaine ()
{
  widget.setupUi (this);
}

/**
 * \brief Destructeur de la classe AjoutFontaine.
 */
AjoutFontaine::~AjoutFontaine () { }
 int AjoutFontaine::reqId()const{
    return widget.case_identifiant->value();
  }
 /**
 * \brief Accesseur de la voie publique.
 * \return La voie publique de la fontaine.
 */
  QString AjoutFontaine::reqVoie()const{
    return widget.case_voiepublique->text();
  }
  /**
 * \brief Accesseur du nom topographique.
 * \return Le nom topographique de la fontaine.
 */
  QString AjoutFontaine::reqTopo()const{
    return widget.case_topographique->text();
  }
  /**
 * \brief Accesseur de la longitude.
 * \return La longitude de la fontaine.
 */
  double AjoutFontaine::reqLong()const{
    return widget.case_longitude->value();
   
  }
  /**
 * \brief Accesseur de la latitude.
 * \return La latitude de la fontaine.
 */
  double AjoutFontaine::reqLat()const{
    return widget.case_latitude->value();

  }
  /**
 * \brief Accesseur de la ville.
 * \return La ville de la fontaine.
 */
  QString AjoutFontaine::reqVille()const
  {
    return widget.case_ville->text();
  }
  /**
 * \brief Accesseur de l'arrondissement.
 * \return L'arrondissement de la fontaine.
 */
  QString AjoutFontaine::reqArr()const{
    return widget.case_arrondissement->text();
  }
  /**
 * \brief Validation des données de la fontaine.
 * Vérifie les contraintes sur les données de la fontaine et affiche une boîte de dialogue en cas d'erreur.
 */
  void AjoutFontaine::valider(){
    
    if(reqId()<=0){
        QString message("l'identifiant doit être positif!");
        QMessageBox::information(this, "Erreur!", message);
        return;
      }
     std::string voie = reqVoie().toStdString();
    
    if ( !std::all_of(voie.begin(), voie.end(), ::isdigit) && !reqVoie().isEmpty ()){
        QString message("l'identifiant de voie doit êre un chiffre ou vide!");
        QMessageBox::information(this, "Erreur!", message);
        return;
      }
    if(reqTopo().isEmpty ()){
        QString message("le nom topographique ne doit pas être vide!");
        QMessageBox::information(this, "Erreur!", message);
        return;        
      }
    if(reqVille().isEmpty ()){
        QString message("le nom de la ville ne doit pas être  vide!");
        QMessageBox::information(this, "Erreur!", message);
        return;
      }
    if((reqVille()== "Québec" && reqArr().isEmpty ()) ){
        QString message("l'arrondissement ne doit pas être vide si la ville est Québec!");
        QMessageBox::information(this, "Erreur!", message);
        return;        
      }
    
    accept();
  }