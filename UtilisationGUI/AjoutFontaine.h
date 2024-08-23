/* 
 * File:   AjoutFontaine.h
* \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 Avril 2024
 */
#ifndef _AJOUTFONTAINE_H
#define _AJOUTFONTAINE_H

#include "ui_AjoutFontaine.h"
/**
 * \class AjoutFontaine
 * \brief Fenêtre de dialogue pour ajouter une fontaine.
 */
class AjoutFontaine : public QDialog
{
  Q_OBJECT
public:
  AjoutFontaine ();
  virtual ~AjoutFontaine ();
  
  int reqId()const;
  QString reqVoie()const;
  QString reqTopo()const;
  double reqLong()const;
  double reqLat()const;
  QString reqVille()const;
  QString reqArr()const;
  
  private slots:
    void valider();
private:
  Ui::AjoutFontaine widget;
};

#endif /* _AJOUTFONTAINE_H */
