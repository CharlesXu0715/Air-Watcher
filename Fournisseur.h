/*************************************************************************
                           TypeMesure  -  description
                             -------------------
    début                : 20.10.2020
    copyright            : (C) 2020 par Julien BOUVIER
    e-mail               : julien.bouvier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ----------------
#if ! defined ( FOURNISSEUR_H )
#define FOURNISSEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

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

class Fournisseur 
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    string & getFournisseurID();
    vector<Cleaner> & getListeCleaner();
//----------------------------------------------------- Constructeurs
Fournisseur(string a);


Fournisseur ( const Fournisseur & unTypeMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



//----------------------------------------------------- Destructeur
~Fournisseur();

//----------------------------------------------------- Méthodes publiques
 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   string fournisseurID;
   vector<Cleaner> mesCleaners;
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
