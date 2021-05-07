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
LectureFichier();


LectureFichier ( const LectureFichier & unTypeMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
void lectureAttribut(ifstream &input,vector<Attribut> &);
void lectureMesure(ifstream &input, vector<Mesure> & listMesure);
void lectureCapteur(ifstream &input, vector<Capteur>& listSensor,vector<Mesure> & listMesure);
void lectureCleaner(ifstream &input, vector<Cleaner>& listCleaner);
void lectureFournisseur(ifstream &input, vector<Fournisseur>& listProvider,vector<Cleaner>& listCleaner);
void lectureUtilisateurPrive(ifstream &input, vector<UtilisateurPrive>& listUP,vector<Capteur>& listSensor);

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
