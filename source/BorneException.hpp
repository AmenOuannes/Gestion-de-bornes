/**
 * \file BorneException.h
 * \brief implémentation des exceptions
 * \Author Amenallah Massarra Ouannes et Rayen Somai 
 * \date 21 Avril 2024,
 */
#ifndef BORNEEXCEPTION_HPP
#define BORNEEXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace tp2{
  /**
   * \class BorneException
   * \brief Classe de base pour les exceptions liées aux bornes.
   */
class BorneException : public std::runtime_error {
public:
   /**
     * \brief Constructeur de BorneException.
     * \param p_raison La raison de l'exception.
     */
     BorneException(const std::string& p_raison)
        : std::runtime_error(p_raison) {}
};

 /**
   * \class BorneDejaPresenteException
   * \brief Exception indiquant qu'une borne est déjà présente.
   */
class BorneDejaPresenteException : public BorneException {
public:
  /**
     * \brief Constructeur de BorneDejaPresenteException.
     * \param p_raison La raison de l'exception. Par défaut : "Borne déjà présente!".
     */
    
    BorneDejaPresenteException(const std::string& p_raison = "Borne déjà présente!")
        : BorneException(p_raison) {}
};

  /**
   * \class BorneAbsenteException
   * \brief Exception indiquant qu'une borne n'existe pas.
   */
class BorneAbsenteException : public BorneException {
public:
   /**
     * \brief Constructeur de BorneAbsenteException.
     * \param p_raison La raison de l'exception. Par défaut : "Borne n'existe pas".
     */
     BorneAbsenteException(const std::string& p_raison = "Borne n'existe pas")
        : BorneException(p_raison) {}
};

#endif // BORNEEXCEPTION_HPP
}/*Namespace tp2*/