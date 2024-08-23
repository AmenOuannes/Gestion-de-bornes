#ifndef VALIDATION_FORMAT_H
#define VALIDATION_FORMAT_H

#include<iostream>
#include<stdbool.h> //pour l'usage des booléens
#include<string>   //pour manipuler les string
#include<sstream>  //pour l'usage de istringstream
#include<fstream>    //pour l'ouverture des fichiers
#include<algorithm> // pour l'usage de all_of
using namespace std;
namespace util{
    bool validePointCardinal(const std::string& p_cardinalite);
    bool valideLigneCVSBorneStationnement (const std::string& p_ligne);
    bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement);
}

#endif