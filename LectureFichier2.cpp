/*************************************************************************
                           LectureFichier  -  description
                             -------------------
    copyright            : (C) XU Yuantao, WU Chenya, Nicolas, Pierre-Louis
*************************************************************************/

// - Realisation de la classe <LectureFichier> (fichier LectureFichier.cpp) --
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
#include <fstream>
#include <iostream>
#include <utility>
#include <iterator>
#include <list>
//#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LectureFichier.h"

void LectureFichier::loadAttribut(ifstream &input, list<Attribut>& listAttribut)
{
	int i=0;
	string title;
	string eol;
	std:getline(input,title);
	string AttributeID;
    string Unit;
    string Description;
	while (!input.eof())
	{
		i++;
		AttributeID.clear();
		Unit.clear();
		Description.clear();
		std:getline(input,AttributID,';');
		std:getline(input,Unit,';');
		std:getline(input,Description,';');
		std:getline(input,eol);
		if (AttributID=="" || Unit=="" || Description=="")
		{
			break;
		}
		Attribut a(AttributID,Unit,Description);
		listAttribut.push_back(a);
	}
}
	
static void loadProvider(ifstream &input, list<Provider>& listProvider)
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
		std:getline(input,ProviderID,';');
		std:getline(input,CleanerID,';');
		std:getline(input,eol);
		if (CleanerID=="" || ProviderID=="")
		{
			break;
		}
		Provider p(ProviderID,CleanerID);
		listProvider.push_back(p);
	}
}

static void loadCleaner(ifstream &input, list<Cleaner>& listCleaner)
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
		std:getline(input,CleanerID,';');
		std:getline(input,Latitude,';');
		std:getline(input,Longitude,';');
		std:getline(input,TimeStart,';');
		std:getline(input,TimeStop,';');
		std:getline(input,eol);
		if (CleanerID=="" || Latitude=="" || Longitude=="" || TimeStart=="" || TimeStop=="")
		{
			break;
		}
		Cleaner c(CleanerID,Latitude,Longitude,TimeStart,TimeStop);
		listCleaner.push_back(c);
	}
}
	
static void loadSensor(ifstream &input, list<Sensor>& listSensor)
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
		std:getline(input,SensorID,';');
		std:getline(input,Latitude,';');
		std:getline(input,Longitude,';');
		std:getline(input,eol);
		if (SensorID=="" || Latitude=="" || Longitude=="")
		{
			break;
		}
		Sensor s(SensorID,Latitude,Longitude);
		listSensor.push_back(s);
	}
}
	
static void loadUser(ifstream &input, list<UtilisateurPrive>& listUP)
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
		std:getline(input,UserID,';');
		std:getline(input,SensorID,';');
		std:getline(input,eol);
		if (UserID=="" || SensorID=="")
		{
			break;
		}
		UtilisateurPrive u(UserID,SensorID);
		listUP.push_back(u);
	}
}

static void loadMesurement(ifstream &input, list<Mesure>& listMesure, const list<Attribut>& listAttribut, list<UtilisateurPrive>& listUP)
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
		std:getline(input,Timestamp,';');
		std:getline(input,SensorID,';');
		std:getline(input,AttributeID,';');
		std:getline(input,Value,';');
		std:getline(input,eol);
		float value=atof(Value);
		if (Timestamp=="" || SensorID=="" || AttributeID=="" || Value=="")
		{
			break;
		}
		list<UtilisateurPrive>::iterator it;
		for (it=listUP.begin();it!=listUP.end();it++)
		{
			if (SensorID==it->getSensor())
			{
				it->setNbPoints(it->getNbPoints()+1);
			}
		}
		Mesure m(Timestamp,SensorID,AttributeID,value);
		listMesure.push_back(m);
	}
}
