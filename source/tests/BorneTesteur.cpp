/**
 * \file BorneTesteur.cpp
 * \brief Fichier de Test pour tester Borne
 * \author Amenallah Massarra Ouannes
 * \date 24 Mars 2024
 */

#include"Borne.h"
#include"ContratException.h"
#include<gtest/gtest.h>
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
 /* \brief Test du constructeur Borne
 *  Cas valide : La Borne est bien créer et lance les exceptions lorsque nécessaire (Manque un champ ou une condition)
 *  Cas invalide : Une Exception est lancé lorsque non nécessaire, ou aucune exception n'est lancé lorsque nécessaire.
 */
TEST(BorneDeTest, ConstructeurValide){   
  ASSERT_NO_THROW(BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5));
}
TEST(BorneDeTest, ConstructeurValideVide){
   ASSERT_NO_THROW(BorneDeTest Borne1(202,"","Rue de l'Université",1.0,2.5));
}


TEST(BorneDeTest, ConstructeurInvalideIdNegatif){
  ASSERT_THROW(BorneDeTest Borne1(-202,"t","Rue de l'Université",1.0,2.5), ContratException);
  /**try
    {BorneDeTest unBorne(-202,"1","Rue de l'universite",1.2,2.5);}
  catch (PreconditionException& erreur)
    {std::cout << erreur.reqTexteException () << std::endl;}*/

  
}
TEST(BorneDeTest, ConstructeurInvalideVoieAlpha){
  ASSERT_THROW(BorneDeTest Borne1(202,"t","Rue de l'Université",1.0,2.5), ContratException);
    /*try
    {BorneDeTest unBorne(202,"t","Rue de l'universite",1.2,2.5);}
  catch (PreconditionException& erreur)
    {std::cout << erreur.reqTexteException () << std::endl;}*/
}
TEST(BorneDeTest, ConstructeurInvalideTopographiqueVide){
  ASSERT_THROW(BorneDeTest Borne1(202,"","",1.0,2.5), ContratException);
   /* try
    {BorneDeTest unBorne(202,"1","",1.2,2.5);}
  catch (PreconditionException& erreur)
    {std::cout << erreur.reqTexteException () << std::endl;}*/
}

/**
 * \brief test de l'assignateur de Borne
 * Cas Valide : La nouvelle adresse a bien été sauvegardée
 * Cas Invalide : La nouvelle adresse n'a pas été sauvegardée
 */
TEST(BorneDeTest, BorneAssgNomtopographique)
{
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  Borne1.asgNomtopographique ("1re Avenue");
  ASSERT_EQ("1re Avenue", Borne1.reqNomtopographique ());
}
/**
 * \brief test de l'operateur ==
 * Cas Valide : L'operateur fonctionne
 * Cas Invalide : L'opérateur ne fait pas la différence entre une borne qui est pas pareil à l'autre
 */
TEST(BorneDeTest ,BornesEgal)
{
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  BorneDeTest Borne2(202,"2275","1re Avenue",1.0,2.5);
  ASSERT_FALSE(Borne2 == Borne1);
  Borne2.asgNomtopographique ("Rue de l'Université");
  ASSERT_EQ(Borne2,Borne1);
}
/**
 * \brief test des accesseurs
 * Cas Valide : Toute les valeurs retourné sont ceux entrées
 * Cas Invalide : une des valeur retourné n'est pas la bonne
 */
TEST(BorneDeTest, BornesReqIdentifiant)
{
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  ASSERT_EQ(202,Borne1.reqIdentifiant ());   
}

TEST(BorneDeTest, BorneReqTopographique){
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  ASSERT_EQ("Rue de l'Université", Borne1.reqNomtopographique ());
}

TEST(BorneDeTest, BorneReqVoie){
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  ASSERT_EQ("2275" ,Borne1.reqVoiepublique ());
}
TEST(BorneDeTest, BorneReqLatitude){
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  ASSERT_EQ(2.5, Borne1.reqLatitude ());
}
TEST(BorneDeTest, BorneReqLongitude){
  BorneDeTest Borne1(202,"2275","Rue de l'Université",1.0,2.5);
  ASSERT_EQ(1.0, Borne1.reqLongitude ());
}
/**
 * \brief test de BorneFormate
 * Cas Valide : l'affichage est correct
 * Cas Invalide : l'affichage est erroné
 */
TEST(Borne, BorneFormate) {
  std::ostringstream os;
  BorneDeTest MaBorne(202, "2275", "Rue de l'Université", 1.0, 2.5);
  os<<"Identifiant de la borne\t:"<<MaBorne.reqIdentifiant ()<<"\n Voie publique\t\t:"<<MaBorne.reqVoiepublique ()<<"\n Nom topographique\t:"
          <<MaBorne.reqNomtopographique ()<<"\n Latitude\t\t:"<<MaBorne.reqLatitude ()<<"\n Longitude\t\t:"<<MaBorne.reqLongitude ()<<std::endl;
  ASSERT_EQ(os.str(), MaBorne.reqBorneFormate());
}
