/*************************************************************************
                           TypeMesure  -  description
                             -------------------
    début                : 20.10.2020
    copyright            : (C) 2020 par Julien BOUVIER
    e-mail               : julien.bouvier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ----------------
#if ! defined ( ANALYSEGOUVERNEUR_H )
#define ANALYSEGOUVERNEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Analyse.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeMesure>
//
//
//------------------------------------------------------------------------

class AnalyseGouverneur : public Analyse
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    
//----------------------------------------------------- Constructeurs
AnalyseGouverneur();


AnalyseGouverneur ( const AnalyseGouverneur & unTypeMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



//----------------------------------------------------- Destructeur
~AnalyseGouverneur();

//----------------------------------------------------- Méthodes publiques
 
void sensorsSimilairs(string lat, string lon, float rayonEnKm, int dureeEnMois, float precision);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
