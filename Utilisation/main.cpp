/**
 * \file main.cpp
 * \brief programme interactif minimaliste pour manipuler les classes crées
 * \author Amenallah Massarra Ouannes
 * \date 10 Avril 2024
 */
#include"Borne.h"
#include"BorneFontaine.h"
#include"BorneStationnement.h"
#include"RegistreBorne.h"
#include"validationFormat.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
//void saisie(int p_identifiant, string p_identifiantVoiePublique, string p_nomTopographique, double p_longitude, double p_latitude);
int identif();
string voie();
string topo();
using namespace std;
using namespace tp2;




int main ()
{ char buffer[256];
  cout<<"Enregistrement d’une borne fontaine :"<<endl;
  int p_identifiant = identif();  
  cin.ignore ();
  string p_identifiantVoiePublique = voie();
  
  string p_nomTopographique = topo();
  double p_longitude, p_latitude;
  cout<<"Entrez la longitude:";
  cin>>p_longitude;
  cout<<"Entrez la latitude:";
  cin>>p_latitude;
  //saisie(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude);
  
  string p_ville, p_Arrondissement;
  cin.ignore ();
  cout<<"Entrez le nom de la ville :";
  cin.getline(buffer,255);
  p_ville = buffer; 
  
   if (p_ville == "Québec") {
        do {
            cout << "Entrez le nom de l'arrondissement :";
            cin.getline(buffer, 255);
            p_Arrondissement = buffer;
        } while (p_Arrondissement.empty()); // Keep asking until a non-empty value is provided
    } else {
        // For cities other than "Québec", an arrondissement can be optional.
        cout << "Entrez le nom de l'arrondissement:";
        cin.getline(buffer, 255);
        p_Arrondissement = buffer;
    }

    
  BorneFontaine MaBorneFontaine(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude, p_ville, p_Arrondissement );
  cout<<"Enregistrement d’une borne de stationnement :"<<endl;
  int p_identifiant1 = identif();
  cin.ignore ();
  string p_identifiantVoiePublique1 = voie(), p_nomTopographique1 = topo();
  double p_longitude1, p_latitude1;
  cout<<"Entrez la longitude:";
  cin>>p_longitude1;
  cout<<"Entrez la latitude:";
  cin>>p_latitude1;  
  
  //saisie(p_identifiant1, p_identifiantVoiePublique1, p_nomTopographique1, p_longitude1, p_latitude1);
  
  int p_numBorne;
  string p_coteRue;
  do {
      cout<<"Entrez le numéro de la borne de stationnement:";
      cin>>p_numBorne;
    }while(!(p_numBorne>=0 && p_numBorne<=9999));
  do {
      cout<<"Entrez le cote de la rue (N, S, E, O) :";
      cin>>p_coteRue;
    }while(!util::validePointCardinal (p_coteRue));
  
    BorneStationnement MaBorneStationnement(p_identifiant1, p_identifiantVoiePublique1, p_nomTopographique1, p_longitude1, p_latitude1,p_numBorne, p_coteRue);
    RegistreBorne MonRegistre(" bornes de l'agglomération de la ville de Québec");
    MonRegistre.ajouteBorne (MaBorneFontaine);
    MonRegistre.ajouteBorne (MaBorneFontaine);
    
    MonRegistre.ajouteBorne(MaBorneStationnement);
    MonRegistre.supprimeBorne (p_identifiant1);
    cout<<MonRegistre.reqRegistreBorneFormate ();
  
  
  return 0;
}
/**
 * \brief methode de saisie de p-identifiant
 * @return int 
 */
int identif(){
  int p_identifiant;
    do {
     cout<<"Entrez l'identifiant de la borne valide: ";
     cin>>p_identifiant;
   } while(p_identifiant<=0);
   return p_identifiant;
}
/**
 * \brief methode de saisie de p-identifiantvoiepublique
 * @return string 
 */
string voie(){
  string p_identifiantVoiePublique;
  char buffer[256];  
  do {
     cout<<"Entrez l'identifiant de la Voie Publique de la borne valide: ";
     cin.getline(buffer,255);
     p_identifiantVoiePublique = buffer;
     
     
   } while(!(std::all_of(p_identifiantVoiePublique.begin(), p_identifiantVoiePublique.end(), ::isdigit) ||  p_identifiantVoiePublique.length() == 0));
   return p_identifiantVoiePublique;
}
/**
 * \brief methode de saisie de p-nomtopgraphique
 * @return string
 */
string topo(){
  string p_nomTopographique;   
  char buffer[256];
     cout<<"Entrez le nom topographique valide: ";
     cin.getline(buffer,255);
     p_nomTopographique = buffer;
    
     while(p_nomTopographique.empty()){
            cout<<"Entrez le nom topographique valide: ";
            cin.getline(buffer,255);
            p_nomTopographique = buffer;
           
       }
     return p_nomTopographique;
}


