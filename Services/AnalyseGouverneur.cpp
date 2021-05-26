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
#include "AnalyseGouverneur.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void AnalyseGouverneur::sensorsSimilairs(string capteurID, int annee, int mois){

  //sensorsSimilaires.clear();
  //const float earthRadiusInKm = 6371;
 
/*
  //obtenir temps actuel
	time_t rawtime;
	struct tm * now;
	time (&rawtime);
	now = localtime (&rawtime); //right now in tm

	//obtenir nombre de mois et nombre d'annees de mesure
	int nbAnnees = (int)dureeEnMois/12+1;
	int nbMois = dureeEnMois%12;*/

	vector<Capteur>::iterator it;
	Capteur c;
	for (it=collectionCapteur.begin();it!=collectionCapteur.end();it++)
	{
		if (it->getCapteurID()==capteurID)
		{
			c=*it;
		}
	}
	int q=CalculeQualiteAir(c,annee,mois);
	double lat=atof(c.getLatitude().c_str());
	double lon=atof(c.getLongitude().c_str());
	Capteur* listCapteur=new Capteur[10];
	int* qualite=new int[10];
	double* distance=new double[10];
	double a,b;
	int n=0;
	int d=0;
	//cout<<collectionCapteur.size()<<endl;
	while (n<=9&&n<collectionCapteur.size()-1)
	{
		for (it=collectionCapteur.begin();it!=collectionCapteur.end();it++)
		{
			if (abs(CalculeQualiteAir(*it,annee,mois)-q)==d&&it->getCapteurID()!=capteurID)
			{
				listCapteur[n]=*it;
				qualite[n]=CalculeQualiteAir(*it,annee,mois);
				a=abs(lat-atof((it->getLatitude()).c_str()));
				b=abs(lon-atof((it->getLongitude()).c_str()));
				distance[n]=sin(a/2)*sin(a/2)*sin(b/2)*sin(b/2)*cos(lat)*cos(atof((it->getLatitude()).c_str()));
				n++;
				//cout<<n<<endl;
			}
			if (n==10) break;
		}
		d++;
	}
	//cout<<"bon"<<endl;
	for (int i=0;i<9;i++)
	{
		for (int j=i+1;j<=9;j++)
		{
			if (qualite[i]==qualite[j]&&distance[i]>distance[j])
			{
				swap(distance[i],distance[j]);
				swap(listCapteur[i],listCapteur[j]);
			}
		}
	}
	cout<<"Le qualite d'air autour de ce capteur (represente par indice): "<<q<<endl;
	cout << "----Liste des capteurs similaires----"<<endl;
	cout<<endl;
	for (int i=0;i<=n-1;i++)
	{
		cout<<i+1<<". ID:"<<listCapteur[i].getCapteurID()<<"  Lat:"<<listCapteur[i].getLatitude()<<"  Lon:"<<listCapteur[i].getLongitude()<<"  Qualite:"<<qualite[i]<<endl;
	}
/*  //obtenir rayon de mesure
  float radiusDegrees = rtod(rayonEnKm/earthRadiusInKm); //demi-taille de l'intervalle de lat/lon en degres
  float latitude = stof(lat);//string to float
  float longitude = stof(lon);*/
  //map<Sensor, pair<float, unsigned int>, sensCompare> meanBySensor; //map des sensors avec leur moyenne de valeur et le nombre de valeurs ajoutees
                                                       //(pour diviser apres), je profite de la boucle qui parcours deja les sensors
  /*for(Capteur s : collectionCapteur)
  {
    //si sensor dans la bonne zone
    if((stof(s.getLatitude())<(latitude+radiusDegrees) && stof(s.getLatitude())>(latitude-radiusDegrees)) && (stof(s.getLongitude())<(longitude+radiusDegrees) && stof(s.getLongitude())>(longitude-radiusDegrees)))
    {
      pair<float, unsigned int> p = make_pair((float)0.0, (unsigned int)0);
      meanBySensor.insert({s, p});
    }
    
  }
  float mean=0;
  int totalMesures=0;
  for(Measure m : collectionMesure)
  {
    if((now->tm_year-nbAnnees <= m.getTime().tm_year)&&(now->tm_mon-nbMois <= m.getTime().tm_mon)) //si la mesure a ete faite dans la duree predeterminee
    {
      ++totalMesures;
      mean+=m.getValue(); //ajouter sa valeur a la moyenne
      map<Sensor, pair<float, unsigned int>>::iterator it;
      for(it=meanBySensor.begin(); it!=meanBySensor.end(); ++it)
      {
        if(it->first.getID() == m.getSensorID()){
          it->second.first+=m.getValue();//on ajoute sa valeur a la moyenne du sensor
          ++it->second.second;//on incremente le nombre de mesures de ce sensor
        }
      }
    }
  }
  mean=mean/totalMesures;
  map<Sensor, pair<float, unsigned int>>::iterator it;
  for(it=meanBySensor.begin(); it!=meanBySensor.end(); ++it)
  {
    it->second.first/=it->second.second;
    if(it->second.first<mean*(1.0+precision) && it->second.first>mean*(1.0-precision))
    {
      sensorsSimilaires.push_back(it->first);
    }
  }*/
 return;
}
int AnalyseGouverneur::CalculeQualiteAir(Capteur unCapteur, int annee,int mois){
	annee = annee - 1900;
	/*const float earthRadiusInKm = 6371.0;
	const float rayonEnKm = 150.0;
	float radiusDegrees = rtod(rayonEnKm/earthRadiusInKm); //on calcule l'intervalle de coordonnees a considérer
	float latitude = stof(lat);
	float longitude = stof(lon);

	list <string> sensorsDansZone; //liste des sensors qui sont dans la zone choisie, seulement leurs ID sont dans la liste
	for(Sensor s : listSensor)
	{
	  //si sensor dans la bonne zone
	  if((stof(s.getLatitude())<(latitude+radiusDegrees) && stof(s.getLatitude())>(latitude-radiusDegrees)) && (stof(s.getLongitude())<(longitude+radiusDegrees) && stof(s.getLongitude())>(longitude-radiusDegrees)))
	  {
		sensorsDansZone.push_back(s.getID());
	  }
	}*/
	double lon=atof(unCapteur.getLongitude().c_str());
	double lat=atof(unCapteur.getLatitude().c_str());
	vector<Capteur> sensorsDansZone=capteurDansLaZone(lon,lat,0.001);
	
	float moyPM10=0;
	float moySO2=0;
	float moyO3=0;
	float moyNO2=0;
	int totalMesuresPM10=0;
	int totalMesuresSO2=0;
	int totalMesuresO3=0;
	int totalMesuresNO2=0;
	vector<Mesure> listMeasure;
	vector<Capteur>::iterator it;
	vector<Mesure>::iterator m;
	for(it=sensorsDansZone.begin();it!=sensorsDansZone.end();it++){
		for(m=it->getListeMesure().begin();m!=it->getListeMesure().end();m++){          
	  //si la mesure a ete faite dans la duree predeterminee
			
			if((annee == m->getTime().tm_year)&&(mois == m->getTime().tm_mon+1))
				{
					  if(m->getAttribut().getID().compare("PM10") == 0){
							totalMesuresPM10++;
							moyPM10 = moyPM10 + m->getValue();
					  }else if(m->getAttribut().getID().compare("SO2") == 0){
							totalMesuresSO2++;
							moySO2 = moySO2 + m->getValue();
					  }else if(m->getAttribut().getID().compare("O3") == 0){
							totalMesuresO3++;
							moyO3 = moyO3 + m->getValue();
					  }else if(m->getAttribut().getID().compare("NO2") == 0){
							totalMesuresNO2++;
							moyNO2 = moyNO2 + m->getValue();
					  } 
				}
		}
	}
	//on calcule les moyennes
	moyPM10 = moyPM10/totalMesuresPM10;
	moySO2 = moySO2/totalMesuresSO2;
	moyO3 = moyO3/totalMesuresO3;
	moyNO2 = moyNO2/totalMesuresNO2;
	
	


	//Standard ATMO introduit par le prof
	int indicePM10;
	int indiceSO2;
	int indiceO3;
	int indiceNO2;
	if(moyPM10 <= 6){
	  indicePM10 = 1;
	}else if (moyPM10 <= 13){
	  indicePM10 = 2;
	}else if (moyPM10 <= 20){
	  indicePM10 = 3;
	}else if (moyPM10 <= 27){
	  indicePM10 = 4;
	}else if (moyPM10 <= 34){
	  indicePM10 = 5;
	}else if (moyPM10 <= 41){
	  indicePM10 = 6;
	}else if (moyPM10 <= 49){
	  indicePM10 = 7;
	}else if (moyPM10 <= 64){
	  indicePM10 = 8;
	}else if (moyPM10 <= 79){
	  indicePM10 = 9;
	}else if (moyPM10 >= 80){
	  indicePM10 = 10;
	}

	if(moySO2 <= 39){
	  indiceSO2 = 1;
	}else if (moySO2 <= 79){
	  indiceSO2 = 2;
	}else if (moySO2 <= 119){
	  indiceSO2 = 3;
	}else if (moySO2 <= 159){
	  indiceSO2 = 4;
	}else if (moySO2 <= 199){
	  indiceSO2 = 5;
	}else if (moySO2 <= 249){
	  indiceSO2 = 6;
	}else if (moySO2 <= 299){
	  indiceSO2 = 7;
	}else if (moySO2 <= 399){
	  indiceSO2 = 8;
	}else if (moySO2 <= 499){
	  indiceSO2 = 9;
	}else if (moySO2 >= 500){
	  indiceSO2 = 10;
	}

	 if(moyO3 <= 29){
	  indiceO3 = 1;
	}else if (moyO3 <= 54){
	  indiceO3 = 2;
	}else if (moyO3 <= 79){
	  indiceO3 = 3;
	}else if (moyO3 <= 104){
	  indiceO3 = 4;
	}else if (moyO3 <= 129){
	  indiceO3 = 5;
	}else if (moyO3 <= 149){
	  indiceO3 = 6;
	}else if (moyO3 <= 179){
	  indiceO3 = 7;
	}else if (moyO3 <= 209){
	  indiceO3 = 8;
	}else if (moyO3 <= 239){
	  indiceO3 = 9;
	}else if (moyO3 >= 240){
	  indiceO3 = 10;
	}

	if(moyNO2 <= 29){
	  indiceNO2 = 1;
	}else if (moyNO2 <= 54){
	  indiceNO2 = 2;
	}else if (moyNO2 <= 84){
	  indiceNO2 = 3;
	}else if (moyNO2 <= 109){
	  indiceNO2 = 4;
	}else if (moyNO2 <= 134){
	  indiceNO2 = 5;
	}else if (moyNO2 <= 164){
	  indiceNO2 = 6;
	}else if (moyNO2 <= 199){
	  indiceNO2 = 7;
	}else if (moyNO2 <= 274){
	  indiceNO2 = 8;
	}else if (moyNO2 <= 399){
	  indiceNO2 = 9;
	}else if (moyNO2 >= 400){
	  indiceNO2 = 10;
	}

	int indiceAtmo = 1; //il est defini comme le plus grand des sous-indices calcule pour le dioxyde de soufre, le dioxyde d'azote, l'ozone et les particules fines
	indiceAtmo = (indicePM10 > indiceAtmo)?  indicePM10:indiceAtmo;
	indiceAtmo = (indiceSO2 > indiceAtmo)?  indiceSO2:indiceAtmo;
	indiceAtmo = (indiceO3 > indiceAtmo)?  indiceO3:indiceAtmo;
	indiceAtmo = (indiceNO2 > indiceAtmo)?  indiceNO2:indiceAtmo;

	return indiceAtmo;
}

AnalyseGouverneur::AnalyseGouverneur (vector<Attribut> listAttribut,vector<Mesure> listMesure,vector<Capteur> listCapteur,vector<Cleaner> listCleaner,vector<Fournisseur> listProvider,vector<UtilisateurPrive> listUP):Analyse(listAttribut,listMesure,listCapteur,listCleaner,listProvider,listUP)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif

   
    
} //----- Fin de Analyse


AnalyseGouverneur::~AnalyseGouverneur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


