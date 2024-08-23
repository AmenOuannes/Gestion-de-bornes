/**
 * \file BorneFontaine.cpp
 * \brief Implémentation de la classe BorneFontaine
* \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 Avril 2024
 */
#include"BorneFontaine.h"
#include"ContratException.h"

#include<sstream>
namespace tp2{

/**
 * \brief Constructeur de BorneFontaine
 * \param[in] p_identifiant int Le numéro de la borne. 
 * \param[in] p_identifiantVoiePublique string Le côté du centre de chaussé ou l'intersection dans le cas t'un terre-plein.
 * \param[in] p_nomTopographique string Le nom topographique(générique,liaison,spécifique,direction) du centre de la chaussée.
 * \param[in] p_longitude double La longitude de la borne
 * \param[in] p_latitude double La latitude de la borne
 * \param[in] p_ville string Le nom de la ville 
 * \param[in] p_arrondissement string L'arrondissement 
 * \pre p_ville non vide
 * \pre p_arrondissement non vide si p_ville  est Québec
 * \post vérification de l'assignation
  * \return un objet BorneFontaine
 */
BorneFontaine::BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude , double p_latitude , const std::string& p_ville, const std::string& p_arrondissement):
Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude),m_ville(p_ville), m_arrondissement(p_arrondissement)
{

  PRECONDITION(!p_ville.empty());
  PRECONDITION(!(p_ville == "Québec" && p_arrondissement.empty()));
  POSTCONDITION(!m_ville.empty());
  POSTCONDITION(!(m_ville == "Québec" && m_arrondissement.empty()));
  INVARIANTS();
}
/**
 *\brief destructeur de la classe BorneFontaine
 */
BorneFontaine::~BorneFontaine(){}
/**
 * \brief Accesseur pour string m_ville
 * \return m_ville
 */
const std::string& BorneFontaine::reqVille()const{
  return m_ville;
}
/**
 * \brief Accesseur pour string m_arrondissement
 * \return m_arrondissement
 */
const std::string& BorneFontaine::reqArrondissement()const{
  return m_arrondissement;
}
/**
 * \brief Méthode pour cloner un objet BorneFontaine à l'aide d'un pointeur intelligent
  * \return un objet BorneFontaine
 */
std::unique_ptr<Borne> BorneFontaine::clone() const{
  return std::unique_ptr < Borne > (new BorneFontaine (*this));
}
/**
 * \brief Méthode augmenté de la classe Borne.
 * \return une string formaté des Bornes Fontaines.
 */
std::string BorneFontaine::reqBorneFormate()const{
  std::ostringstream os;
  os<<"Borne-fontaine"<<std::endl<<"----------------------------------------------"<<std::endl
          <<Borne::reqBorneFormate ()<<"ville\t\t\t:"<<this->reqVille () <<std::endl<<"Arrondissement\t\t:"<<this->reqArrondissement ()<<std::endl;
  return os.str();
}
/**
 * \brief Méthode augmenté de la classe Borne.
 * \return booléen de l'égalité entre deux instances de BorneFontaine.
 */
bool BorneFontaine::operator==(const BorneFontaine& p_BorneFontaine)const{
  //Borne Borne1(this->reqIdentifiant (), this->reqVoiepublique (), this->reqNomtopographique (), this->reqLongitude (), this->reqLatitude ());
  //Borne Borne2(p_BorneFontaine.reqIdentifiant (), p_BorneFontaine.reqVoiepublique (),p_BorneFontaine.reqNomtopographique (), p_BorneFontaine.reqLongitude (), p_BorneFontaine.reqLatitude ());
  return this->m_ville==p_BorneFontaine.m_ville &&
          this->m_arrondissement == p_BorneFontaine.m_arrondissement &&
          Borne::operator ==(p_BorneFontaine);
}
/**
 * \brief Méthode qui verifie tous les invariants de BorneFontaine
 */
void BorneFontaine::verifieInvariant()const{

  INVARIANT(!m_ville.empty());
  INVARIANT(!(m_ville == "Quebec" && m_arrondissement.empty())); 
}
}/*namespace tp2*/
