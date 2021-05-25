/*************************************************************************
                           LectureFichier  -  description
                             -------------------
    copyright            : (C) XU Yuantao, WU Chenya, Nicolas, Pierre-Louis
*************************************************************************/

//---- Interface de la classe <LectureFichier> (fichier LectureFichier.h) ----------
#if !defined(Lecturefichier_H)
#define Lecturefichier_H

//--------------------------------------------------- Interfaces utilisees
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <time.h>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe <LectureFichier>
// La classe LectureFichier permet de lire une liste a partir d'un fichier
// ...

//------------------------------------------------------------------------

class LectureFichier
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Methodes publiques
    
	static void loadAttribut(ifstream &input, list<Attribut>& listAttribut);
	
	static void loadProvider(ifstream &input, list<Provider>& listProvider);
	
	static void loadCleaner(ifstream &input, list<Cleaner>& listCleaner);
	
	static void loadSensor(ifstream &input, list<Sensor>& listSensor);
	
	static void loadUser(ifstream &input, list<UtilisateurPrive>& listUP);
	
	static void loadMesurement(ifstream &input, list<Mesure>& listMesure, const list<Attribut>& listAttribut, list<UtilisateurPrive>& listUP);


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Methodes protegees

    //----------------------------------------------------- Attributs proteges
};

#endif // Lecturefichier_H
