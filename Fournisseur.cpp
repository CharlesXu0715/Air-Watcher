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
#include "Fournisseur.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string & Fournisseur::getFournisseurID(){
	return fournisseurID;
}

vector<Cleaner> & Fournisseur::getListeCleaner(){
	return  mesCleaners;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Fournisseur::Fournisseur ( const Fournisseur & unFournisseur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
fournisseurID=unFournisseur.fournisseurID;
mesCleaners=unFournisseur.mesCleaners;

} //----- Fin de Analyse (constructeur de copie)


Fournisseur::Fournisseur (string a)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif
fournisseurID=a;
   
    
} //----- Fin de Analyse


Fournisseur::~Fournisseur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

