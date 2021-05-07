/*************************************************************************
                           TypeMesure  -  description
                             -------------------
    début                : 20.10.2020
    copyright            : (C) 2020 par Julien BOUVIER
    e-mail               : julien.bouvier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ----------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeMesure>
//
//
//------------------------------------------------------------------------

class Cleaner 
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    string & getCapteurID();
    string & getLatitude();
    string & getLongitude();
    string & getDateDebut();
    string & getDateFin();
//----------------------------------------------------- Constructeurs
Cleaner(string a,string b,string c,string d, string e);


Cleaner ( const Cleaner & unTypeMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



//----------------------------------------------------- Destructeur
~Cleaner();

//----------------------------------------------------- Méthodes publiques
 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   
   string capteurID;
   string latitude;
   string longitude;
   string dateDebut;
   string dateFin;
   
  
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
