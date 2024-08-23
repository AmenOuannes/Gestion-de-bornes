
/**
 * \file   BorneStationnement.h
 * \brief Interface de la classe BorneStationnement
 * \Author Amenallah Massarra Ouannes et Rayen Somai
 *
 * \date  21 Avril 2024
 */

#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H
#include"Borne.h"
#include<string>
#include <cassert>
#include <stdexcept>
#include <memory>
#include<sstream>
#include "ContratException.h"


namespace tp2{
  /**
   * \class BorneStationnement
   * \brief La classe BorneStationnement représente les bornes de stationnement de la ville de Québec.
   * 
   */
  class BorneStationnement: public Borne
  {
  public:
    BorneStationnement(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude , double p_latitude, int p_numBorne, const std::string& p_coteRue);
    virtual ~BorneStationnement();
    int reqNumBorne()const;
    const std::string& reqCoteRue()const;
    virtual std::unique_ptr<Borne> clone()const;
    bool operator==(const BorneStationnement& p_BorneStationnement)const;
    virtual std::string reqBorneFormate()const;
    
  private:
    int m_identifiant; //entier strictement positif
    std::string m_identifiantVoiePublique;
    std::string m_nomTopographique;
    double m_longitude;
    double m_latitude;
    int m_numBorne;
    std::string m_coteRue;
  //Méthode utilitaire
    void verifieInvariant() const; //Théorie du contrat

  };
}/*namespace tp2*/


#endif /* BORNESTATIONNEMENT_H */

