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
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <iterator>
#include <vector>
using namespace std;



//------------------------------------------------------ Include personnel
#include "LectureFichier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void LectureFichier::lectureAttribut(ifstream &input,vector<Attribut> & listAttribut)
{
	
	int i=0;
	string title;
	string eol;
	getline(input,title);
	string AttributID;
    string Unit;
    string Description;
	while (!input.eof())
	{
		i++;
		AttributID.clear();
		Unit.clear();
		Description.clear();
		getline(input,AttributID,';');
		
		getline(input,Unit,';');
		getline(input,Description,';');
		getline(input,eol);
		if (AttributID=="" || Unit=="" || Description=="")
		{
			break;
		}
		listAttribut.push_back(Attribut (AttributID,Unit,Description));	
	}
}

void LectureFichier::lectureMesure(ifstream &input, vector<Mesure> & listMesure)
{
	int i=0;
	string eol;
	string Timestamp;
	string SensorID;
	string AttributeID;
	string Value;
	while (!input.eof())
	{
		i++;
		Timestamp.clear();
		SensorID.clear();
		AttributeID.clear();
		Value.clear();
		getline(input,Timestamp,';');
		getline(input,SensorID,';');
		getline(input,AttributeID,';');
		getline(input,Value,';');
		getline(input,eol);
		double value=atof(Value.c_str());
		if (Timestamp=="" || SensorID=="" || AttributeID=="" || Value=="")
		{
			break;
		}
		//cout<<Timestamp<<" "<<SensorID<< " "<<AttributeID<<" "<<value<<endl;
		Mesure m(Timestamp,SensorID,AttributeID,Value);
		listMesure.push_back(m);
	}
}

void LectureFichier::lectureCapteur(ifstream &input, vector<Capteur>& listSensor,vector<Mesure> & listMesure)
{
	int i=0;
	string eol;
	string SensorID;
    string Latitude;
    string Longitude;
	while (!input.eof())
	{
		i++;
		SensorID.clear();
		Latitude.clear();
		Longitude.clear();
		getline(input,SensorID,';');
		getline(input,Latitude,';');
		getline(input,Longitude,';');
		getline(input,eol);
		if (SensorID=="" || Latitude=="" || Longitude=="")
		{
			break;
		}
		Capteur s(SensorID,Latitude,Longitude);
		
		vector<Mesure>::iterator mes;
		for (mes=listMesure.begin();mes!=listMesure.end();mes++)
			{
				if (SensorID==mes->getCapteurID())
				{
					s.getListeMesure().push_back(*mes);
				}
			}
		listSensor.push_back(s);
	}
	
}

void LectureFichier::lectureCleaner(ifstream &input, vector<Cleaner>& listCleaner)
{
	int i=0;
	string eol;
	string CleanerID;
    string Latitude;
    string Longitude;
    string TimeStart;
    string TimeStop;
	while (!input.eof())
	{
		i++;
		CleanerID.clear();
		Latitude.clear();
		Longitude.clear();
		TimeStart.clear();
		TimeStop.clear();
		getline(input,CleanerID,';');
		getline(input,Latitude,';');
		getline(input,Longitude,';');
		getline(input,TimeStart,';');
		getline(input,TimeStop,';');
		getline(input,eol);
		if (CleanerID=="" || Latitude=="" || Longitude=="" || TimeStart=="" || TimeStop=="")
		{
			break;
		}
		Cleaner c(CleanerID,Latitude,Longitude,TimeStart,TimeStop);
		listCleaner.push_back(c);
	}
}

void LectureFichier::lectureFournisseur(ifstream &input, vector<Fournisseur>& listProvider,vector<Cleaner>& listCleaner)
{
	int i=0;
	string eol;
	string ProviderID;
	string CleanerID;
	while (!input.eof())
	{
		i++;
		ProviderID.clear();
		CleanerID.clear();
		getline(input,ProviderID,';');
		getline(input,CleanerID,';');
		getline(input,eol);
		if (CleanerID=="" || ProviderID=="")
		{
			break;
		}
		Fournisseur p(ProviderID);
		
		vector<Cleaner>::iterator it;
		for (it=listCleaner.begin();it!=listCleaner.end();it++)
			{
				if (CleanerID==it->getCapteurID())
				{
					p.getListeCleaner().push_back(*it);
				}
			}
		listProvider.push_back(p);
	}
}

void LectureFichier::lectureUtilisateurPrive(ifstream &input, vector<UtilisateurPrive>& listUP,vector<Capteur>& listSensor)
{
	int i=0;
	string eol;
	string UserID;
	string SensorID;
	while (!input.eof())
	{
		i++;
		UserID.clear();
		SensorID.clear();
		getline(input,UserID,';');
		getline(input,SensorID,';');
		getline(input,eol);
		if (UserID=="" || SensorID=="")
		{
			break;
		}
		UtilisateurPrive u(UserID);
		vector<Capteur>::iterator it;
		for (it=listSensor.begin();it!=listSensor.end();it++)
			{
				if (SensorID==it->getCapteurID())
				{
					u.getListeCapteur().push_back(*it);
				}
			}
		listUP.push_back(u);
	}
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
LectureFichier::LectureFichier ( const LectureFichier & uneAnalyse )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)


LectureFichier::LectureFichier ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif

   
    
} //----- Fin de Analyse


LectureFichier::~LectureFichier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


