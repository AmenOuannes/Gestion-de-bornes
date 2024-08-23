
/* 
 * File:   SupprimeBorne.h
* \author Amenallah Massarra Ouannes et Rayen Somai
 * \date 21 Avril 2024
 */

#ifndef _SUPPRIMEBORNE_H
#define _SUPPRIMEBORNE_H

#include "ui_SupprimeBorne.h"
/**
 * \class SupprimeBorne
 * \brief Fenêtre de dialogue pour supprimer une borne.
 */
class SupprimeBorne : public QDialog
{
  Q_OBJECT
public:
  SupprimeBorne ();
  virtual ~SupprimeBorne ();
  int reqId()const;
  private slots:
    void valider();
private:
  Ui::SupprimeBorne widget;
};

#endif /* _SUPPRIMEBORNE_H */
