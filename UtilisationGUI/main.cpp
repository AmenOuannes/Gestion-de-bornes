/**
 * \file main.cpp
 * \brief Implémentation de la classe RegistreBorne
 * \author Amenallah Massarra Ouannes - Rayen Somai
 * \date 21 Avril 2024
 */


#include <QApplication>
#include "RegistreGUI.h"

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  RegistreGUI FenetrePrincipal;
  FenetrePrincipal.show();
  return app.exec ();
}
