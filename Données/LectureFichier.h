/*************************************************************************
                           TypeMesure  -  description
                             -------------------
    début                : 20.10.2020
    copyright            : (C) 2020 par Julien BOUVIER
    e-mail               : julien.bouvier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ----------------
#if ! defined ( LECTUREFICHIER_H )
#define LECTUREFICHIER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "Attribut.h"
#include "Mesure.h"
#include "Capteur.h"
#include "Cleaner.h"
#include "Fournisseur.h"
#include "UtilisateurPrive.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeMesure>
//
//
//------------------------------------------------------------------------

class LectureFichier 
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    
//----------------------------------------------------- Constructeurs

static vector<Attribut> lectureAttribut(ifstream &input);
static vector<Mesure> lectureMesure(ifstream &input, vector<Attribut> listAttribut);
static vector<Capteur> lectureCapteur(ifstream &input,vector<Mesure> & listMesure);
static vector<Cleaner> lectureCleaner(ifstream &input);
static vector<Fournisseur> lectureFournisseur(ifstream &input,vector<Cleaner>& listCleaner);
static vector<UtilisateurPrive> lectureUtilisateurPrive(ifstream &input,vector<Capteur>& listSensor);
static tm gettimem(string time);

//----------------------------------------------------- Destructeur
~LectureFichier();

//----------------------------------------------------- Méthodes publiques
 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
