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
#include "Capteur.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Capteur::getCapteurID(){
	return capteurID;
}

string Capteur::getLatitude(){
	return latitude;
}

string Capteur::getLongitude(){
	return longitude;
}

bool Capteur::getDefaillant(){
	return defaillant;
}

vector<Mesure> Capteur::getListeMesure(){
	return  collectionMesure;
}

void Capteur::setCaptureID(string unID) {
    capteurID = unID;
}

void Capteur::setLatitude(string unLatitude) {
    latitude = unLatitude;
}

void Capteur::setLongitude(string unLongitude) {
    longitude = unLongitude;
}

void Capteur::setDefaillant(bool unLabel) {
    defaillant = unLabel;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Capteur::Capteur ( const Capteur & unCapteur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif

	capteurID=unCapteur.capteurID;
   latitude=unCapteur.latitude;
   longitude=unCapteur.longitude;
   defaillant=unCapteur.defaillant;
   collectionMesure=unCapteur.collectionMesure;
} //----- Fin de Analyse (constructeur de copie)


Capteur::Capteur (string a,string b,string c)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif

   capteurID=a;
   latitude=b;
   longitude=c;
   defaillant=false;
    
} //----- Fin de Analyse


Capteur::~Capteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


