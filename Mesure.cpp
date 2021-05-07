
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

//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string & Mesure::getValue(){
	return value;
}
string & Mesure::getDate(){
	return date;
}
string & Mesure::getAttributeID(){
	return attributeID;
}
string & Mesure::getCapteurID(){
	return capteurID;
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

date=uneMesure.date;
capteurID=uneMesure.capteurID;
attributeID=uneMesure.attributeID;
value=uneMesure.value;


} //----- Fin de Analyse (constructeur de copie)


Mesure::Mesure (string a, string b, string c,string d)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif
	date=a;
    capteurID=b;
    attributeID=c;
    value=d;
   
    
} //----- Fin de Analyse


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

