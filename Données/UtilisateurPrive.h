/*************************************************************************
                           TypeMesure  -  description
                             -------------------
    début                : 20.10.2020
    copyright            : (C) 2020 par Julien BOUVIER
    e-mail               : julien.bouvier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ----------------
#if ! defined ( UTILISATEURPRIVE_H )
#define UTILISATEURPRIVE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Capteur.h"


#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeMesure>
//
//
//------------------------------------------------------------------------

class UtilisateurPrive 
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs

//----------------------------------------------------- Constructeurs
UtilisateurPrive(string a);


UtilisateurPrive ( const UtilisateurPrive & unUtilisateurPrive );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



//----------------------------------------------------- Destructeur
~UtilisateurPrive();

//----------------------------------------------------- Méthodes publiques
 
int getNbPoints();

void setNbPoints(int unNbPoints);

void ajouterCapteur(Capteur unCapteur);

vector<Capteur> getListeCapteur();

string getUtilisateurID();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   
   string utilisateurID;
   vector<Capteur> mesCapteurs;
   int nbPoints;
   
  
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
