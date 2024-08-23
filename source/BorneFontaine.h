/**
 * \file BorneFontaine.h
 * \brief Interface de la classe BorneFontaine
 * \Author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 avril 2024
 */

#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H
#include "Borne.h"
#include <memory>


namespace tp2{
  /**
 * \class BorneFontaine
 * \brief une classe qui permet de représenter les bornes-fontaines de la ville de Québec
 */
  class BorneFontaine: public Borne
  { public:
    BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude , double p_latitude , const std::string& p_ville, const std::string& p_arrondissement);
    virtual ~BorneFontaine();
    const std::string& reqVille()const;
    const std::string& reqArrondissement()const;
    virtual std::unique_ptr<Borne> clone() const;
    bool operator==(const BorneFontaine& p_BorneFontaine)const;
    
    virtual std::string reqBorneFormate()const;
    
  private:
    int p_identifiant;
    std::string p_identifiantVoiePublique;
    std::string p_nomTopographique;
    double m_longitude ;
    double m_latitude ;
    std::string m_ville;
    std::string m_arrondissement;
    
    void verifieInvariant() const; 
    
  };
}/*Namespace tp2*/


#endif /* BORNEFONTAINE_H */

