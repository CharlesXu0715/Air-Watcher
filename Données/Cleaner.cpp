/*************************************************************************
                           Analyse  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Analyse> (fichier Analyse.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <stdio.h>
#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;



//------------------------------------------------------ Include personnel
#include "Cleaner.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string & Cleaner::getCapteurID(){
	return capteurID;
}

string & Cleaner::getLatitude(){
	return latitude;
}

string & Cleaner::getLongitude(){
	return longitude;
}

string & Cleaner::getDateDebut(){
	return dateDebut;
}

string & Cleaner::getDateFin(){
	return dateFin;
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
	capteurID=unCleaner.capteurID;
   latitude=unCleaner.latitude;
   longitude=unCleaner.longitude;
   dateDebut=unCleaner.dateDebut;
   dateFin=unCleaner.dateFin;

} //----- Fin de Analyse (constructeur de copie)


Cleaner::Cleaner (string a,string b,string c,string d, string e)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif
   capteurID=a;
   latitude=b;
   longitude=c;
   dateDebut=d;
   dateFin=e;
   
    
} //----- Fin de Analyse


Cleaner::~Cleaner ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


