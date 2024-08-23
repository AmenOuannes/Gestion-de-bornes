/**
 * \file Borne.cpp
 * \brief Implementation de la classe Borne
 * \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 Avril 2024
 */

#include "Borne.h"
#include<algorithm>
#include "validationFormat.h"

namespace tp2{
/**
 * \brief Constructeur de Borne
 * \param[in] p_identifiant int Le numéro de la borne.
 * \param[in] p_identifiantVoiePublique string la voie publique sur laquelle la borne est située.
 * \param[in] p_nomTopographique string Le nom topographique(générique,liaison,spécifique,direction) du centre de la chaussée.
 * \param[in] p_longitude double La longitude de la borne 
 * \param[in] p_latitude double La latitude de la borne 
 * \pre p_identifiant doit être positif
 * \pre p_identifiantVoiePublique doit etre vide ou numerique
 * \pre p_nomTopographique doit être non vide
 * \post vérification que tout les attribute nécessaire contienne des valeurs valides
 * \return un objet Borne
 */
Borne::Borne(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude):m_identifiant(p_identifiant),
        m_identifiantVoiePublique(p_identifiantVoiePublique), m_nomTopographique(p_nomTopographique), m_longitude(p_longitude), m_latitude(p_latitude){
 
  PRECONDITION(p_identifiant > 0 );
  PRECONDITION(std::all_of(p_identifiantVoiePublique.begin(), p_identifiantVoiePublique.end(), ::isdigit) ||  p_identifiantVoiePublique=="");
  PRECONDITION(p_nomTopographique!="");
  POSTCONDITION(m_identifiant == p_identifiant );
  POSTCONDITION(m_identifiantVoiePublique == p_identifiantVoiePublique);
  POSTCONDITION(m_nomTopographique == p_nomTopographique);
  INVARIANTS();

}
/*
 * \brief accesseur pour l'identifiant entier 
 * \return m_identifiant
 */
int Borne::reqIdentifiant()const{
  return m_identifiant;
}
/*
 * \brief accesseur pour la voie publique string
 * \return m_identifiantVoiePublique
 */
std::string Borne::reqVoiepublique()const{
  
  return m_identifiantVoiePublique;
}
/*
 * \brief accesseur pour le nom topographique string
 * \return m_nomTopographique
 */
std::string Borne::reqNomtopographique()const{
  
  return m_nomTopographique;
}
/*
 * \brief accesseur pour la longitude double
 * \return m_longitude
 */
double Borne::reqLongitude()const{
  
  return m_longitude;
}
/*
 * \brief accesseur pour la latitude double
 * \return m_latitude
 */
double Borne::reqLatitude()const{
  
  return m_latitude;
}
/**
 * \brief Mutateur pour NomTopographique, modifie m_nomTopographique
 * \param[in] p_nomTopographique Le nom topographique(générique,liaison,spécifique,direction) du centre de la chaussée.
 * \pre nouveau Nom Topographique doit être non vide
 * \post vérifie que l'attribut m_nomTopographique contient le nouveau nom courant.
 */
void Borne::asgNomtopographique(const std::string& p_nomTopographique){
  PRECONDITION(p_nomTopographique != "");
  this->m_nomTopographique = p_nomTopographique;
  POSTCONDITION (m_nomTopographique == p_nomTopographique);
  INVARIANTS();
}
/**
 * \brief Opérateur d'égalité. Si une seule propriété n'est pas identique, les bornes ne sont pas identique.
 * \param[in] p_borne un objet de type Borne
 * \return booleen
 */
bool Borne::operator==(const Borne & p_bornes)const{
  
  return (this->m_identifiant==p_bornes.m_identifiant) && (this->m_identifiantVoiePublique==p_bornes.m_identifiantVoiePublique) && (this->m_latitude==p_bornes.m_latitude)
          && (this->m_longitude == p_bornes.m_longitude) &&(this->m_nomTopographique == p_bornes.m_nomTopographique);
}
/**
 * \brief Accesseur pour string de Borne formatté
 * \return borneFormate
 */
std::string Borne::reqBorneFormate()const{
  std::ostringstream p_os;
  p_os<<"Identifiant de la borne\t:"<<this->reqIdentifiant ()<<"\n Voie publique\t\t:"<<this->reqVoiepublique ()<<"\n Nom topographique\t:"
          <<this->reqNomtopographique ()<<"\n Latitude\t\t:"<<this->reqLatitude ()<<"\n Longitude\t\t:"<<this->reqLongitude ()<<std::endl;
  return p_os.str();
}
/**
 * \brief Méthode qui verifie tous les invariants de Borne
 */
void Borne::verifieInvariant()const{
  INVARIANT(m_identifiant > 0);
  INVARIANT(std::all_of(m_identifiantVoiePublique.begin(), m_identifiantVoiePublique.end(), ::isdigit) ||  m_identifiantVoiePublique=="");
  INVARIANT(m_nomTopographique !="");
}
/**
 * \brief Destructeur de Borne
 */
Borne::~Borne (){}
}/*Namespace tp2*/