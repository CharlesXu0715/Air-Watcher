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
    
    
//----------------------------------------------------- Constructeurs

	Cleaner();

    Cleaner(string unelatitude,string unelongitude,string uncleanerID, struct tm* unedateFin, struct tm* unedateDebut);

    

//----------------------------------------------------- Destructeur
	virtual ~Cleaner();

//----------------------------------------------------- Méthodes publiques
	//getters
    string getID();
    string getLatitude();
    string getLongitude();
    struct tm* getDateDebut();
    struct tm* getDateFin();

    //setters
    void setID(string uncleanerID);
    void setLatitute(string uneLatitute);
    void setLongitude(string uneLongitude);
    void setDateDebut(struct tm* uneDateDebut);
    void setDateFin(struct tm* uneDateFin);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   
    string latitude;
    string longitude;
    string cleanerID;
    struct tm* dateFin; //date de desinstallation du Cleaner
    struct tm* dateDebut; //date d'installation du Cleaner
    string providerID;
   
  
    
};

//-------------------------------- Autres définitions dépendantes de <TypeMesure>

#endif // TypeMesure_H
