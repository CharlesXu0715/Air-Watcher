
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
#include "Mesure.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
tm Mesure::getTime(){
    return this->Timestamp;
}

string Mesure::getCapteurID(){
    return this->capteurID;
}

Attribut Mesure::getAttribut(){
    return this->mt;
}

float Mesure::getValue(){
    return this->value;
}

void Mesure::setTime(tm time){
    this->Timestamp=time;
}

void Mesure::setValue(float value){
    this->value=value;
}

void Mesure::setAttribut(Attribut mt)
{
    this->mt=mt;
}
//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
Mesure::Mesure(tm Timestamp, float value, Attribut mt, string sensId)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measure>" << endl;
#endif
  //  this->measureID=CSVgetLastID()+1; //il faut creer une fonction dans gestion csv pour recup le dernier ID
    this->Timestamp=Timestamp;
    this->value=value;
    this->mt=mt;
    this->capteurID=sensId;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure ( const Mesure & uneMesure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif

	Timestamp=uneMesure.Timestamp;
	value=uneMesure.value;
	mt=uneMesure.mt;
	capteurID=uneMesure.capteurID;


} //----- Fin de Analyse (constructeur de copie)




Mesure::~Mesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

