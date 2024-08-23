#include"BorneFontaine.h"
#include"ContratException.h"
#include<gtest/gtest.h>
#include<sstream>
using namespace tp2;


/**
 * \class BorneFontaineValide
 * \brief Test fixture pour les méthodes de la classe BorneFontaine
 */
class BorneFontaineTest : public ::testing::Test{
  public:
    BorneFontaine F_MaBorneFontaine1;
    BorneFontaine F_MaBorneFontaine2;
    BorneFontaineTest() : F_MaBorneFontaine1(202, "2275", "Rue de l'Université", 1.0, 2.5, "t", "t"),
    F_MaBorneFontaine2(202, "2275", "Rue de l'Université", 1.0, 2.5, "Québec", "La Haute-Saint-Charles"){}
  
};
 /* \brief Test du constructeur BorneFontaine
 *  Cas valide : La BorneFontaine est bien créer et lance les exceptions lorsque nécessaire (Manque un champ ou une condition)
 *  Cas invalide : Une Exception est lancé lorsque non nécessaire, ou aucune exception n'est lancé lorsque nécessaire.
 */
TEST_F(BorneFontaineTest, ConstructeurValide){
  ASSERT_NO_THROW(F_MaBorneFontaine1);
}
TEST_F(BorneFontaineTest, ConstructeurValideQuébec){
  ASSERT_NO_THROW(F_MaBorneFontaine2);
}
TEST(BorneFontaine, ConstructeurInvalideQuébec){
  ASSERT_THROW(BorneFontaine(202, "2275", "Rue de l'Université", 1.0, 2.5, "Québec", ""),PreconditionException);

}
TEST(BorneFontaine, ConstructeurInvalideVille){
  ASSERT_THROW(BorneFontaine(202, "2275", "Rue de l'Université", 1.0, 2.5, "", "t"),PreconditionException);
}
/**
 * \brief test des accesseurs
 * Cas Valide : Toute les valeurs retourné sont ceux entrées
 * Cas Invalide : une des valeur retourné n'est pas la bonne
 */
TEST_F(BorneFontaineTest, reqVille){
  
  ASSERT_EQ(F_MaBorneFontaine1.reqVille(), "t");
}
TEST_F(BorneFontaineTest, reqArrondissement){
  ASSERT_EQ(F_MaBorneFontaine1.reqArrondissement(), "t");
}
/**
 * \brief test de l'operateur ==
 * Cas Valide : L'operateur fonctionne
 * Cas Invalide : L'opérateur ne fait pas la différence entre une BorneFontaine qui est pas pareil à l'autre
 */
TEST_F(BorneFontaineTest, BorneFontaineEgal){
  BorneFontaine Instance_egal(202, "2275", "Rue de l'Université", 1.0, 2.5, "Québec", "La Haute-Saint-Charles");
  ASSERT_EQ(Instance_egal, F_MaBorneFontaine2);

}
/**
 * \brief test de la méthode augmentée de BorneFormate
 * Cas Valide : l'affichage est correct
 * Cas Invalide : l'affichage est erroné
 */
TEST_F(BorneFontaineTest, BorneFontaineFormate) {
  std::ostringstream os;
  os<<"Borne-fontaine"<<std::endl<<"----------------------------------------------"<<std::endl;
  os<<"Identifiant de la borne\t:"<<F_MaBorneFontaine1.reqIdentifiant ()<<"\n Voie publique\t\t:"<<F_MaBorneFontaine1.reqVoiepublique ()<<"\n Nom topographique\t:"
          <<F_MaBorneFontaine1.reqNomtopographique ()<<"\n Latitude\t\t:"<<F_MaBorneFontaine1.reqLatitude ()<<"\n Longitude\t\t:"<<F_MaBorneFontaine1.reqLongitude ()
          <<"\nville\t\t\t:"<<F_MaBorneFontaine1.reqVille () <<std::endl<<"Arrondissement\t\t:"<<F_MaBorneFontaine1.reqArrondissement ()<<std::endl;
  ASSERT_EQ(os.str(),F_MaBorneFontaine1.reqBorneFormate ());
  
}
/**
 * \brief test de la méthode de clone
 * Cas Valide : le clonage est correct
 * Cas Invalide : le clonage est erroné
 */
TEST_F(BorneFontaineTest, Clone_CreatesCorrectCopy) {
    auto clone = F_MaBorneFontaine1.clone();
    ASSERT_EQ(*clone, F_MaBorneFontaine1);
}