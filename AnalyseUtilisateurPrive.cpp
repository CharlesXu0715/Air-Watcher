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
#include "AnalyseUtilisateurPrive.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
AnalyseUtilisateurPrive::AnalyseUtilisateurPrive ( const AnalyseUtilisateurPrive & uneAnalyse )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)


AnalyseUtilisateurPrive::AnalyseUtilisateurPrive ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif

   
    
} //----- Fin de Analyse


AnalyseUtilisateurPrive::~AnalyseUtilisateurPrive ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


