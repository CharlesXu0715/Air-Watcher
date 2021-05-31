/*************************************************************************
                           TypeMesure  -  description
                             -------------------
    début                : 20.10.2020
    copyright            : (C) 2020 par Julien BOUVIER
    e-mail               : julien.bouvier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ----------------
#if ! defined ( ANALYSE_H )
#define ANALYSE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "../Données/Capteur.h"
#include "../Données/Mesure.h"
#include "../Données/Fournisseur.h"
#include "../Données/Cleaner.h"
#include "../Données/UtilisateurPrive.h"
#include "../Données/Attribut.h"
#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeMesure>
//
//
//------------------------------------------------------------------------

class Analyse 
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
   
//----------------------------------------------------- Constructeurs
Analyse(vector<Attribut> listAttribut,vector<Mesure> listMesure,vector<Capteur> listCapteur,vector<Cleaner> listCleaner,vector<Fournisseur> listProvider,vector<UtilisateurPrive> listUP);


Analyse ( const Analyse & unAnalyse );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



//----------------------------------------------------- Destructeur
~Analyse();

//----------------------------------------------------- Méthodes publiques

vector<Capteur> & getListeCapteur();
vector<Mesure> & getListeMesure();
vector<Fournisseur> & getListeFournisseur();
vector<Cleaner> & getListeCleaner();
vector<UtilisateurPrive> & getListeUtilisateurPrive();
vector<Attribut> & getListeAttribut();

void QualitePointMoment(double longitude, double latitude, int annee, int mois, int jour);
void QualitePointMoment(string capteurID, int annee, int mois, int jour);
vector<Capteur>  capteurDansLaZone(double longitude, double latitude, double rayon);
int CalculeQualiteAir(double lat, double lon, double rayon, int annee, int mois, int jour, bool affichage);
void AfficherCapteurs();
void afficherCapteur(vector<Capteur> list);


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    vector<Capteur> collectionCapteur;
    vector<Mesure> collectionMesure;
    vector<Fournisseur> collectionFournisseur;
    vector<Cleaner> collectionCleaner;
    vector<UtilisateurPrive> collectionUtilisateurPrive;
    vector<Attribut> collectionAttribut;
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
