/*************************************************************************
                           Attribut  -  description
                             -------------------
    copyright            : (C) XU Yuantao
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Attribut::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut ( string unit, string description, string id )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribut>" << endl;
#endif

this->unit=unit;
this->description=description;
this->attributeID=id;
} //----- Fin de Attribut (constructeur de copie)


Attribut::Attribut ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribut>" << endl;
#endif
this->unit="";
this->description="";
this->attributeID="";
} //----- Fin de Attribut

string Attribut::getUnit(){
    return this->unit;
}

string Attribut::getID()
{
    return this->attributeID;
}

void Attribut::setUnit(string unit){
    this->unit=unit;
}

string Attribut::getDescription(){
    return this->description;
}

void Attribut::setDescription(string description){
    this->description=description;
}


Attribut::~Attribut ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribut>" << endl;
#endif
} //----- Fin de ~Attribut


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
