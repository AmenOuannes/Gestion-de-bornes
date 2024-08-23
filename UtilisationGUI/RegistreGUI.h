
/* 
 * File:   RegistreGUI.h
* \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 Avril 2024
 */

#ifndef _REGISTREGUI_H
#define _REGISTREGUI_H
#include "ui_RegistreGUI.h"
#include"RegistreBorne.h"
#include"Borne.h"

/**
 * \class RegistreGUI
 * \brief Fenêtre principale de l'interface graphique du registre.
 */
class RegistreGUI : public QMainWindow
{
  Q_OBJECT
public:
  RegistreGUI ();
  virtual ~RegistreGUI ();

  private slots:
    void fenetre_fontaine();
    void fenetre_stationnement();
    void fenetre_supprimer();
private:
  Ui::RegistreGUI widget;
  //const std::string& name = "test";
  tp2::RegistreBorne MonRegistre;
  //std::unique_ptr<tp2::RegistreBorne> MonRegistre;

};

#endif /* _REGISTREGUI_H */
