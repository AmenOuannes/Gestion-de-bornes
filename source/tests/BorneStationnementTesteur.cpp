#include"BorneStationnement.h"
#include"ContratException.h"
#include<gtest/gtest.h>
#include<sstream>
using namespace tp2;
/**
 * \class BorneStationnementTest
 * \brief Test fixture pour les méthodes de la classe BorneStationnement
 */
class BorneStationnementTest : public ::testing::Test{
  public:
    BorneStationnement F_MaBorneStationnement1;
    BorneStationnement F_MaBorneStationnement2;
    BorneStationnementTest() : F_MaBorneStationnement1(202, "2275", "Rue de l'Université", 1.0, 2.5, 1000, "N"),
    F_MaBorneStationnement2(202, "2275", "Rue de l'Université", 1.0, 2.5, 2200, "S"){}
  
};
 /* \brief Test du constructeur BorneStationnement
 *  Cas valide : La BorneStationnement est bien crée et lance les exceptions lorsque nécessaire (Manque un champ ou une condition)
 *  Cas invalide : Une Exception est lancé lorsque non nécessaire, ou aucune exception n'est lancé lorsque nécessaire.
 */
  TEST_F(BorneStationnementTest, ConstructeurValide){
  ASSERT_NO_THROW(F_MaBorneStationnement1);
}

TEST(BorneStationnement, ConstructeurInvalideNumBorne){
  ASSERT_THROW(BorneStationnement(202, "2275", "Rue de l'Université", 1.0, 2.5, -1, "N"),PreconditionException);
}
TEST(BorneStationnement, ConstructeurInvalideCote){
  ASSERT_THROW(BorneStationnement(202, "2275", "Rue de l'Université", 1.0, 2.5, 1000, "t"),PreconditionException);
}
/**
 * \brief test des accesseurs
 * Cas Valide : Toute les valeurs retourné sont ceux entrées
 * Cas Invalide : une des valeur retourné n'est pas la bonne
 */
TEST_F(BorneStationnementTest, reqNumBorne){
  ASSERT_EQ(F_MaBorneStationnement1.reqNumBorne(), 1000);
}
TEST_F(BorneStationnementTest, reqCoteRue){
  ASSERT_EQ(F_MaBorneStationnement1.reqCoteRue(), "N");
}
/**
 * \brief test de l'operateur ==
 * Cas Valide : L'operateur fonctionne
 * Cas Invalide : L'opérateur ne fait pas la différence entre une BorneStationnement qui est pas pareil à l'autre
 */
TEST_F(BorneStationnementTest, BorneStationnementEgal){
  BorneStationnement Instance_egal(202, "2275", "Rue de l'Université", 1.0, 2.5, 2200, "S");
  ASSERT_EQ(Instance_egal, F_MaBorneStationnement2);

}
/**
 * \brief test de la méthode augmentée de BorneFormate
 * Cas Valide : l'affichage est correct
 * Cas Invalide : l'affichage est erroné
 */
TEST_F(BorneStationnementTest, BorneStationnementFormate) {
  std::ostringstream os;
  os<<"Borne de stationnement"<<std::endl<<"----------------------------------------------"<<std::endl;
  os<<"Identifiant de la borne\t:"<<F_MaBorneStationnement2.reqIdentifiant ()<<"\n Voie publique\t\t:"<<F_MaBorneStationnement2.reqVoiepublique ()<<"\n Nom topographique\t:"
          <<F_MaBorneStationnement2.reqNomtopographique ()<<"\n Latitude\t\t:"<<F_MaBorneStationnement2.reqLatitude ()<<"\n Longitude\t\t:"<<F_MaBorneStationnement2.reqLongitude ()
          <<"\nNumero de la borne\t:"<<F_MaBorneStationnement2.reqNumBorne () <<std::endl<<"Cote de la rue\t\t:"<<F_MaBorneStationnement2.reqCoteRue ()<<std::endl;
  ASSERT_EQ(os.str(),F_MaBorneStationnement2.reqBorneFormate ());
  
}
/**
 * \brief test de la méthode de clone
 * Cas Valide : le clonage est correct
 * Cas Invalide : le clonage est erroné
 */
TEST_F(BorneStationnementTest, Clone_CreatesCorrectCopy) {
    auto clone = F_MaBorneStationnement1.clone();
    ASSERT_EQ(*clone, F_MaBorneStationnement1);
}
