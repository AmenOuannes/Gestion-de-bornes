
/* 
 * \File:   RegistreBorne.h
 * \Author  Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 avril 2024
 */

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H
#include"Borne.h"
#include<sstream>
#include<vector>
#include<memory>
#include<algorithm>
namespace tp2{
  /**
   * \class RegistreBorne
   * \brief La classe RegistreBorne permet la gestion des bornes-fontaines et de stationnement.
   */
 class RegistreBorne{
 public:
   RegistreBorne(const std::string& p_nomRegistreBorne);
   RegistreBorne(const RegistreBorne& p_RegistreBorne);
   ~RegistreBorne();
   const RegistreBorne& operator=(const RegistreBorne& p_registreBorne);
   const std::string& reqNom()const;
   int reqTaille()const;
   void ajouteBorne(const Borne& p_borne);
   void supprimeBorne(int p_identifiant);

   std::string reqRegistreBorneFormate()const;
   bool borneExiste(const Borne & p_borne)const;
   
   
   private:
     std::string m_nomRegistreBorne;
     std::vector<std::unique_ptr<Borne>> m_bornes;
     
     
     void verifieInvariant() const;
 }; 
}/*Namespace tp2*/


#endif /* REGISTREBORNE_H */

