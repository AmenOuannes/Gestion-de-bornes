#include"validationFormat.h"

namespace util{
    bool validePointCardinal(const std::string& p_cardinalite){
        bool test = false;
        if (p_cardinalite=="" || p_cardinalite=="N" || p_cardinalite=="S" || p_cardinalite=="E" || p_cardinalite=="O")
            test = true;
        return test;
    }
    bool valideLigneCVSBorneStationnement (const std::string& p_ligne){
        bool test = false; 
        istringstream chaine_cvs(p_ligne);
        string ID,NO_BORNE,COTE_RUE,ID_VOIE_PUBLIQUE,NOM_TOPOGRAPHIQUE,LONGITUDE,LATITUDE;
        int count =0;
        for(char c:p_ligne){
            if(c==',')
            count++; //s'assurer que ma ligne contient 7 variables séparés par des ','
        }
        if(count==6){
        getline(chaine_cvs, ID,',');
        getline(chaine_cvs, NO_BORNE,',');
        getline(chaine_cvs, COTE_RUE,',');
        getline(chaine_cvs, ID_VOIE_PUBLIQUE,',');
        getline(chaine_cvs, NOM_TOPOGRAPHIQUE,',');
        getline(chaine_cvs, LONGITUDE,',');
        getline(chaine_cvs, LATITUDE);
        
        if (ID!="" && NO_BORNE!="" && NOM_TOPOGRAPHIQUE!=""){
            if (stoi(LATITUDE)==46 && stoi(LONGITUDE)==-71){
                if (ID_VOIE_PUBLIQUE==""||std::all_of(ID_VOIE_PUBLIQUE.begin(), ID_VOIE_PUBLIQUE.end(), ::isdigit)) //emploi de isdigit tout au long de la chaine  pour confirmer qu'elle s'agit d'un entier
                test = validePointCardinal(COTE_RUE);
            }
          }}
        return test;

    }
    bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement){
        string ligne;
        bool test = false;
        getline(p_fluxBornesStationnement, ligne);
        
        if (ligne=="ID,NO_BORNE,COTE_RUE,ID_VOIE_PUBLIQUE,NOM_TOPOGRAPHIQUE,LONGITUDE,LATITUDE"){//s'assurer que la  première ligne contient l'entête
            test = true;
            while(getline(p_fluxBornesStationnement, ligne) && test==true){   //vérifier ligne par ligne et s'arrêter une fois que la ligne vide ou ligne invalide est trouvée
                if(ligne.empty())
                    {break;}
                if(!valideLigneCVSBorneStationnement(ligne))
                    {test = false;
                    
                    }
            }
        }
        return test;
            
        
    }
}