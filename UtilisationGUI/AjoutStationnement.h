

/* 
 * File:   AjoutStationnement.h
* \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 Avril 2024
 */
#ifndef _AJOUTSTATIONNEMENT_H
#define _AJOUTSTATIONNEMENT_H

#include "ui_AjoutStationnement.h"
/**
 * \class AjoutStationnement
 * \brief Fenêtre de dialogue pour ajouter un stationnement.
 */
class AjoutStationnement : public QDialog
{
  Q_OBJECT
public:
  AjoutStationnement ();
  virtual ~AjoutStationnement ();
  int reqId()const;
  QString reqVoie()const;
  QString reqTopo()const;
  double reqLong()const;
  double reqLat()const;
  int reqNumBorne()const;
  QString reqCote()const;
  
  private slots:
    void valider();
private:
  Ui::AjoutStationnement widget;
  
};

#endif /* _AJOUTSTATIONNEMENT_H */
