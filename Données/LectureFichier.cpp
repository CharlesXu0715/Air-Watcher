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

void LectureFichier::lectureMesure(ifstream &input, vector<Mesure> & listMesure,vector<Attribut> listAttribut)
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
		tm timestamp=gettimem(Timestamp);
		for(Attribut mt : listAttribut)
            {
                if (mt.getID().compare(AttributeID)==0){
                    Mesure m(timestamp, value, mt, SensorID);
                    listMesure.push_back(m);
                    break;
            }
          }
		/*Mesure m(timestamp,value,AttributeID,SensorID);
		listMesure.push_back(m);*/
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
		tm* dD = new tm();
		*dD=gettimem(TimeStart);
		tm* dF = new tm();
		*dF=gettimem(TimeStop);
		Cleaner c(CleanerID,Latitude,Longitude,dD,dF);
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
		
		
		vector<Cleaner>::iterator it;
		for (it=listCleaner.begin();it!=listCleaner.end();it++)
			{
				if (CleanerID==it->getID())
				{
					Fournisseur p(ProviderID,*it);
					listProvider.push_back(p);
					break;
				}
			}
		//listProvider.push_back(p);
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

tm LectureFichier::gettimem(string time){//methode qui renvoie un mt a partir d'un string
    int count=0;

    //les chaines de caractères contenant les dates ont toutes le même format donc on recupere des sous chaines
    string syear=time.substr(0,4);

    string smonth=time.substr(5,2);

    string sday=time.substr(8,2);

    string shour=time.substr(11,2);

    string smin=time.substr(14,2);

    string ssec=time.substr(17,2);



    int year=stoi(syear);
    int month=stoi(smonth);
    int day=stoi(sday);
    int hour=stoi(shour);
    int min=stoi(smin);
    int sec=stoi(ssec);

    tm timestamp;
    timestamp.tm_year=year-1900; //l'annee dans les tm correspond aux nombres d'annes depuis 1900
    timestamp.tm_mon=month-1; //les mois correspondent au nombre de mois depuis janvier
    timestamp.tm_hour=hour;
    timestamp.tm_mday=day;
    timestamp.tm_sec=sec;
    timestamp.tm_min=min;

    return timestamp;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


