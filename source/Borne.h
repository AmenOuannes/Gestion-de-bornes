/**
 * \file Borne.h
 * \brief Interface de la classe Borne
 * \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 avril 2024
 */

#ifndef BORNES_H
#define BORNES_H
#include<string>
#include <cassert>
#include <stdexcept>
#include<sstream>
#include<memory>
#include "ContratException.h"

namespace tp2{
/**
 * \class Borne
 * \brief une classe qui permet de modéliser tous les types de bornes présents dans la ville de Québec.
 */
class Borne
{
public:
  Borne(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude , double p_latitude);
  virtual ~Borne();
  int reqIdentifiant() const;
  std::string reqVoiepublique() const;
  std::string reqNomtopographique() const;
  double reqLongitude() const;
  double reqLatitude() const;
  void asgNomtopographique(const std::string& p_nomTopographique);
  bool operator==(const Borne & p_bornes)const;
  virtual std::unique_ptr<Borne> clone() const = 0;
   virtual std::string reqBorneFormate()const;
  
private:
  int m_identifiant; //entier strictement positif
  std::string m_identifiantVoiePublique;
  std::string m_nomTopographique;
  double m_longitude;
  double m_latitude;
  //Méthode utilitaire
  void verifieInvariant() const; //Théorie du contrat
  

};
}//namespace tp2

#endif /* BORNES_H */

