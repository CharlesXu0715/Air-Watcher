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
string Cleaner:: getID() {
	return cleanerID;
}
string Cleaner:: getLatitude() {
	return latitude;
}
string Cleaner::getLongitude() {
	return longitude;
}
struct tm* Cleaner::getDateDebut() {
	return dateDebut;
}
struct tm* Cleaner::getDateFin() {
	return dateFin;
}

void Cleaner::setID(string uncleanerID) {
	cleanerID = uncleanerID;
}
void Cleaner::setLatitute(string uneLatitute) {
	latitude = uneLatitute;
}
void Cleaner::setLongitude(string uneLongitude) {
	longitude = uneLongitude;
}
void Cleaner::setDateDebut(tm* uneDateDebut) {
	dateDebut = uneDateDebut;
}
void Cleaner::setDateFin(tm* uneDateFin) {
	dateDebut = uneDateFin;
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner() {
	latitude="";
	longitude="";
	cleanerID="";
	dateFin = 0;
	dateDebut = 0;
}//----- Fin de Cleaner

Cleaner::Cleaner(string unelatitude, string unelongitude, string uncleanerID, struct tm* unedateDebut, struct tm* unedateFin) {
	latitude = unelatitude;
	longitude = unelongitude;
	cleanerID = uncleanerID;
	dateFin = unedateFin;
	dateDebut = unedateDebut;
}//----- Fin de Cleaner

Cleaner::~Cleaner() {
}//----- Fin de~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


