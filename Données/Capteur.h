/*************************************************************************
                           TypeMesure  -  description
                             -------------------
    début                : 20.10.2020
    copyright            : (C) 2020 par Julien BOUVIER
    e-mail               : julien.bouvier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ----------------
#if ! defined ( CAPTEUR_H )
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "Mesure.h"

#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeMesure>
//
//
//------------------------------------------------------------------------

class Capteur 
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    string getCapteurID();
    string getLatitude();
    string getLongitude();
    bool getDefaillant();
    vector<Mesure> getListeMesure();
    void setLatitude(string unLatitude);
    void setLongitude(string unLongitude);
    void setDefaillant(bool unLabel);
    void setCaptureID(string unID);
//----------------------------------------------------- Constructeurs
Capteur(string,string,string);


Capteur ( const Capteur & unTypeMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



//----------------------------------------------------- Destructeur
~Capteur();

//----------------------------------------------------- Méthodes publiques
 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   
   string capteurID;
   string latitude;
   string longitude;
   bool defaillant;
   vector<Mesure> collectionMesure;
  
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
