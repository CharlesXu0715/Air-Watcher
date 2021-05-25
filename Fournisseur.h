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
    //methode pour ajouter un nouveau cleaner a la liste
    void ajouterCleaner(Cleaner unCleaner);

    //methode pour supprimer un cleaner existant dans la liste
    void supprimerCleaner(string cleanerId, struct tm* dateFin);

    //getters
    string getID();

    vector<Cleaner> getListeCleaner();

    //setters

    void setID(string unproviderID);
//----------------------------------------------------- Constructeurs
Fournisseur(string providerID, Cleaner unCleaner);


Fournisseur ( const Fournisseur & unFournisseur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



//----------------------------------------------------- Destructeur
virtual ~Fournisseur();

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
