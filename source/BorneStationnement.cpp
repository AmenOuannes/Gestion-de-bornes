/**
 * \file   BorneStationnement.cpp
 * \brief Implémentation de la classe BorneStationnement 
* \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 Avril 2024
 */
#include"BorneStationnement.h"
#include"validationFormat.h"
namespace tp2{
  /**
 * \brief Constructeur de BorneStationnement
 * \param[in] p_identifiant int Le numéro de la borne. 
 * \param[in] p_identifiantVoiePublique string Le côté du centre de chaussé ou l'intersection dans le cas t'un terre-plein.
 * \param[in] p_nomTopographique string Le nom topographique(générique,liaison,spécifique,direction) du centre de la chaussée.
 * \param[in] p_longitude double La longitude de la borne
 * \param[in] p_latitude double La latitude de la borne
 * \param[in] p_numBorne int numero de la borne 
 * \param[in] p_coteRue string la cote de la rue 
 * \pre p_numBorne entre 0 et 9999
 * \pre p_coteRue (S,O,E,N)
 * \post vérification de l'assignation
  * \return un objet BorneStationnement
 */
  BorneStationnement::BorneStationnement(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude , double p_latitude, int p_numBorne, const std::string& p_coteRue):
  Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude), m_numBorne(p_numBorne), m_coteRue(p_coteRue){
    PRECONDITION(p_numBorne>=0 && p_numBorne<=9999);
    PRECONDITION(util::validePointCardinal (p_coteRue));
    POSTCONDITION(m_numBorne == p_numBorne);
    POSTCONDITION(m_coteRue == p_coteRue);
    INVARIANTS();
  }
  /**
   * \brief Destructeur de la classe BorneStationnement
   */
  BorneStationnement::~BorneStationnement(){}
  /**
   * \brief accesseur au numero de borne
   * \return int numero de la borne
   */
  int BorneStationnement::reqNumBorne()const{
    return m_numBorne;
  }
  /**
   * \brief accesseur à la cote de la rue
   * \return string cote de la rue
   */  
  const std::string& BorneStationnement::reqCoteRue()const{
    return m_coteRue;
  }
/**
 * \brief Méthode pour cloner un objet BorneStationnement à l'aide d'un pointeur intelligent
  * \return un objet BorneStationnement
 */
  std::unique_ptr<Borne> BorneStationnement::clone() const {
    return std::unique_ptr<Borne>(new BorneStationnement(*this));
  }
  /**
 * \brief Méthode augmenté de la classe Borne.
 * \return booléen de l'égalité entre deux instances de BorneStationnement.
 */
  bool BorneStationnement::operator==(const BorneStationnement& p_BorneStationnement)const{
    /*Borne Borne1(this->reqIdentifiant (), this->reqVoiepublique (), this->reqNomtopographique (), this->reqLongitude (), this->reqLatitude ());
    Borne Borne2(p_BorneStationnement.reqIdentifiant (), p_BorneStationnement.reqVoiepublique (),p_BorneStationnement.reqNomtopographique (), p_BorneStationnement.reqLongitude (), p_BorneStationnement.reqLatitude ());*/
    return Borne::operator ==(p_BorneStationnement) && this->reqNumBorne()== p_BorneStationnement.reqNumBorne () && this->reqCoteRue() == p_BorneStationnement.reqCoteRue ();
  }
  /**
 * \brief Méthode augmenté de la classe Borne.
 * \return une string formaté des Bornes Stationnement.
 */
  std::string BorneStationnement::reqBorneFormate()const{
    std::ostringstream os;
    os<<"Borne de stationnement"<<std::endl<<"----------------------------------------------"<<std::endl
          <<Borne::reqBorneFormate ()<<"Numero de la borne\t:"<<this->reqNumBorne () <<std::endl<<"Cote de la rue\t\t:"<<this->reqCoteRue()<<std::endl;
    return os.str();
  }
  void BorneStationnement::verifieInvariant() const{
    INVARIANT(m_numBorne>=0 && m_numBorne<=9999);
    INVARIANT(util::validePointCardinal (m_coteRue));
  }
}/*Namespace tp2*/