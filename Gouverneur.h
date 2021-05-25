/*************************************************************************
                           TypeMesure  -  description
                             -------------------
    début                : 20.10.2020
    copyright            : (C) 2020 par Julien BOUVIER
    e-mail               : julien.bouvier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ----------------
#if ! defined ( GOUVERNEUR_H )
#define GOUVERNEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Capteur.h"

#include "Cleaner.h"

#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeMesure>
//
//
//------------------------------------------------------------------------

class Gouverneur 
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    string getGouverneurID();
    vector<Capteur> getListeCapteur();
    vector<Cleaner> getListeCleaner();
//----------------------------------------------------- Constructeurs
Gouverneur(string a,vector<Capteur> listCapt,vector<Cleaner> listClean);


Gouverneur ( const Gouverneur & unGouverneur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



//----------------------------------------------------- Destructeur
~Gouverneur();

//----------------------------------------------------- Méthodes publiques
 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   
   string gouverneurID;
   vector<Capteur> tousLesCapteurs;
   vector<Cleaner> tousLesCleaners;
  
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
