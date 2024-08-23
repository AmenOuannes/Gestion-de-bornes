/**
 * \file RegistreBorne.cpp
 * \brief Implémentation de la classe RegistreBorne
 * \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 Avril 2024
 */
#include"RegistreBorne.h"
#include"ContratException.h"
#include"BorneException.hpp"
#include<iostream>

namespace tp2{
  /**
 * \brief Constructeur de RegistreBorne
 * \param[in] p_nomRegistreBorne  string le nom du registre
 * \pre p_nomRegistreBorne no vide

 * \post vérification que le nom du registre contient une valeur valide
 * \return un objet RegistreBorne
 */
  RegistreBorne::RegistreBorne(const std::string& p_nomRegistreBorne):m_nomRegistreBorne(p_nomRegistreBorne){
    PRECONDITION(!p_nomRegistreBorne.empty());
    POSTCONDITION(m_nomRegistreBorne == p_nomRegistreBorne);
    INVARIANTS();
    
            
  }
    /**
   * \brief Constructeur de copie de RegistreBorne
   * \param[in] p_registreBorne L'objet RegistreBorne à copier.
   */
  RegistreBorne::RegistreBorne(const RegistreBorne& p_registreBorne){
    for ( auto & borne : p_registreBorne.m_bornes){
        ajouteBorne (*borne);
      }
    
  }
    /**
   * \brief Surcharge de l'opérateur d'assignation pour RegistreBorne.
   * \param[in] p_registreBorne L'objet RegistreBorne à assigner.
   * \return Une référence sur l'objet RegistreBorne assigné.
   */
  const RegistreBorne & RegistreBorne::operator=(const RegistreBorne & p_registreBorne){
    if (!(this==&p_registreBorne))
      {
        m_nomRegistreBorne = p_registreBorne.m_nomRegistreBorne;
        m_bornes.clear();
        for ( auto & borne : p_registreBorne.m_bornes)
        {
        ajouteBorne (*borne);
        }
    POSTCONDITION(m_nomRegistreBorne == p_registreBorne.m_nomRegistreBorne);
                
      }
    INVARIANTS();
    return *this;
  }                                                                             
  /**
   * \brief destructeur de RegistreBorne
   */
   RegistreBorne::~RegistreBorne(){}
  const std::string& RegistreBorne::reqNom()const{
    return m_nomRegistreBorne;
  }
  /**
   * \brief accesseur de la taille
   * \return taille int
   */
  int RegistreBorne::reqTaille()const{
    return m_bornes.size();
  }
  /***/
  bool RegistreBorne::borneExiste(const Borne & p_borne)const{
    for (auto & borne : m_bornes){
        if( *borne == p_borne){
            return true;
          }
      }
    return false;
  }
  /**
   * \brief methode d'ajout de borne au registre
   * \param p_borne
   *
   */
  void RegistreBorne::ajouteBorne(const Borne& p_borne){
    int size = this->reqTaille ();
    if (!this->borneExiste (p_borne))
        m_bornes.push_back(p_borne.clone());
    else
      throw BorneDejaPresenteException(p_borne.reqBorneFormate ());
    POSTCONDITION(this->reqTaille () == size +1);
      
  }
  /**
   * \brief methode de suppression d'une borne
   * @param p_identifiant
   */
  void RegistreBorne::supprimeBorne(int p_identifiant){
    int size = this->reqTaille ();
    auto iter = std::find_if(m_bornes.begin(), m_bornes.end(),  [p_identifiant](const auto& borne) {return borne->reqIdentifiant() == p_identifiant;});
    if (iter != m_bornes.end())
      m_bornes.erase (iter);
    else 
      throw BorneAbsenteException();
    
    POSTCONDITION(this->reqTaille () == size -1);    
    INVARIANTS();
    
  }
  /**
  * \brief Méthode de string formate.
  * \return une string formaté qui represente toutes les bornes dans le registre.
  */
  std::string RegistreBorne::reqRegistreBorneFormate()const{
    std::ostringstream os;
    os<<"Registre:"<<this->reqNom ()<<std::endl;
    for(auto & element:this->m_bornes){
        os<<element-> reqBorneFormate()<<std::endl;
      }
    return os.str();
    
  }
  void RegistreBorne::verifieInvariant() const {
   
    INVARIANT(!m_nomRegistreBorne.empty());
}
  }/*Namespace tp2*/