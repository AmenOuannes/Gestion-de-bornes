#include"RegistreBorne.h"
#include"BorneFontaine.h"
#include"BorneStationnement.h"
#include"ContratException.h"
#include<gtest/gtest.h>
#include<memory>

#include<vector>
#include<sstream>
#include"Borne.h" 
using namespace tp2;
/**
 * \class BorneDeTest
 * \brief implémntation de la classe abstraite borne
 */
class BorneDeTest: public Borne
{
  public:
    BorneDeTest(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude):
    Borne(p_identifiant,p_identifiantVoiePublique,p_nomTopographique,p_longitude,p_latitude){}
    virtual std::unique_ptr<Borne> clone() const{return std::unique_ptr<Borne>(new BorneDeTest(*this));}
};
 /* \brief Test du constructeur RegistreBorne
 *  Cas valide : Le registre est bien crée et lance les exceptions lorsque nécessaire (Manque un champ ou une condition)
 *  Cas invalide : Une Exception est lancé lorsque non nécessaire, ou aucune exception n'est lancé lorsque nécessaire.
 */
TEST(RegistreBorne, ConstructeurValide){
  ASSERT_NO_THROW(RegistreBorne MonRegistre("Ville de Québec"));
}
TEST(RegistreBorne, ConstructeurInvalideVide){
  ASSERT_THROW(RegistreBorne MonRegistre(""), PreconditionException);
}
/**
 * \brief test des accesseurs
 * Cas Valide : Toute les valeurs retourné sont ceux entrées
 * Cas Invalide : une des valeur retourné n'est pas la bonne
 */
TEST(RegistreBorne, reqTaille){
  RegistreBorne MonRegistre("Ville de Québec");
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  BorneDeTest Borne2(100, "2235", "Rue de la Terrasse", 1.0, 2.5);
  MonRegistre.ajouteBorne(Borne1);
  MonRegistre.ajouteBorne(Borne2);
  ASSERT_EQ(MonRegistre.reqTaille (), 2);
}
TEST(RegistreBorne, reqNom){
    RegistreBorne MonRegistre("Ville de Québec");
    ASSERT_EQ("Ville de Québec", MonRegistre.reqNom ());
}
/*
 * \brief teste de l'ajout de borne
 * 
 */
TEST(RegistreBorne, AjouteBorne){
  RegistreBorne MonRegistre("Ville de Québec");
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  MonRegistre.ajouteBorne(Borne1);
  ASSERT_TRUE(MonRegistre.reqTaille() == 1);
}
TEST(RegistreBorne , SupprimeBorne){
  RegistreBorne MonRegistre("Ville de Québec");
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  MonRegistre.ajouteBorne(Borne1);
  MonRegistre.supprimeBorne (Borne1.reqIdentifiant ());
  ASSERT_TRUE(MonRegistre.reqTaille() == 0);  
}
TEST(RegistreBorne, BorneExiste){
  RegistreBorne MonRegistre("Ville de Québec");
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  MonRegistre.ajouteBorne(Borne1);
  BorneDeTest Borne2(100, "2235", "Rue de la Terrasse", 1.0, 2.5);
  ASSERT_TRUE(MonRegistre.borneExiste (Borne1) == true);
  ASSERT_TRUE(MonRegistre.borneExiste (Borne2) == false);
  
}
/**
 * \brief test de la méthode  RegistreBorneFormate
 * Cas Valide : l'affichage est correct
 * Cas Invalide : l'affichage est erroné
 */
TEST(RegistreBorne, reqFormate)
{
    RegistreBorne MonRegistre("Mon Registre");
    BorneFontaine MaBorneFontaine(1,"2275","Rue de l'université",1.0,2.5,"Québec","abc");
    BorneStationnement MaBorneStationnement(2,"2275","Rue de l'université",1.0,2.5,1234,"N");
    MonRegistre.ajouteBorne(MaBorneFontaine);
    MonRegistre.ajouteBorne(MaBorneStationnement);

    
    std::ostringstream os;
    os<<"Registre:Mon Registre"<<std::endl;
    os<<MaBorneFontaine.reqBorneFormate ()<<std::endl;
    os<<MaBorneStationnement.reqBorneFormate ()<<std::endl;
    ASSERT_EQ(os.str (), MonRegistre.reqRegistreBorneFormate ());
    

                

}

