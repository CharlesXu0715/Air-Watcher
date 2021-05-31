
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
#include <math.h> 
#include<cstring>
#include <math.h>
#include <time.h>
using namespace std;



//------------------------------------------------------ Include personnel
#include "Analyse.h"


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
Analyse::Analyse(vector<Attribut> listAttribut,vector<Mesure> listMesure,vector<Capteur> listCapteur,vector<Cleaner> listCleaner,vector<Fournisseur> listProvider,vector<UtilisateurPrive> listUP)
{
	collectionCapteur=listCapteur;
    collectionMesure=listMesure;
    collectionFournisseur=listProvider;
    collectionCleaner=listCleaner;
    collectionUtilisateurPrive=listUP;
    collectionAttribut=listAttribut;
}
Analyse::Analyse ( const Analyse & uneAnalyse )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)


/*
void Analyse::setListeAttribut(vector<Attribut> l){
	vector<Attribut>::iterator it;
	for (it=l.begin();it!=l.end();it++)
		{
			collectionAttribut.push_back(*it);
		}
}
*/

vector<Attribut> & Analyse::getListeAttribut(){
	return  collectionAttribut;
}

vector<Capteur> & Analyse::getListeCapteur(){
	return collectionCapteur;
}

vector<Mesure> & Analyse::getListeMesure(){
	return collectionMesure;
}

vector<Fournisseur> & Analyse::getListeFournisseur(){
	return collectionFournisseur;
}

vector<Cleaner> & Analyse::getListeCleaner(){
	return collectionCleaner;
}

vector<UtilisateurPrive> & Analyse::getListeUtilisateurPrive(){
	return collectionUtilisateurPrive;
}

void Analyse::QualitePointMoment(double longitude, double latitude, int annee, int mois, int jour){
	double rayon =2;
	clock_t debut,fin;
	debut=clock();
	vector<Capteur> listCapt(capteurDansLaZone(longitude,latitude,rayon));
	fin=clock();
	float duree=((double) (fin-debut))/CLOCKS_PER_SEC;
	
	cout<<endl;
	cout<<"******* Test unitaire de la sous méthode capteurDansLaZone ********"<<endl;
	cout<<endl;
	cout<<"Cette sous methode a pris "<<duree<<" secondes"<<endl;
	cout<<endl;
	cout<<"Liste des capteurs présents à la position mentionné avec un rayon de 2"<<endl;
	cout<<endl;
	afficherCapteur(listCapt);
	cout<<endl;
	
	
	if(listCapt.empty()==true){
		cout<<"Aucun Capteur dans la zone reessayer avec d'autres positions"<<endl;
	
	}else{
		clock_t debut2,fin2;
		debut2=clock();
		CalculeQualiteAir(latitude,longitude,rayon,annee,mois,jour,true);
		fin2=clock();
		float duree2=((double) (fin2-debut2))/CLOCKS_PER_SEC;
		cout<<endl;
		cout<<"La sous methode CalculerQualiteAir a pris "<<duree2<<" secondes"<<endl;
		cout<<endl;
		
		
	}

}

void Analyse::QualitePointMoment(string capteurID, int annee, int mois, int jour){
	double rayon =2;
	bool capteurTrouve = false;
	double longitude;
	double latitude;

	vector<Capteur>::iterator it;
	
	for (it=collectionCapteur.begin();it!=collectionCapteur.end();it++)
		{
			if(it->getCapteurID()==capteurID){
				longitude=stof(it->getLongitude());
				latitude=stof(it->getLatitude());
				capteurTrouve=true;
				break;
			}
		}
	if(capteurTrouve==false){
		cout<<"CapteurID introuvable ou inexistant, retour au menu"<<endl;
	} else {
		clock_t debut,fin;
		debut=clock();
		vector<Capteur> listCapt(capteurDansLaZone(longitude,latitude,rayon));
		fin=clock();
		float duree=((double) (fin-debut))/CLOCKS_PER_SEC;
		cout<<endl;
		cout<<"******* Test unitaire de la sous méthode capteurDansLaZone ********"<<endl;
		cout<<endl;
		cout<<"Cette sous methode a pris "<<duree<<" secondes"<<endl;
		cout<<endl;
		cout<<"Liste des capteurs présents à la position mentionné avec un rayon de 2"<<endl;
		cout<<endl;
		afficherCapteur(listCapt);
		cout<<endl;
	
		if(listCapt.empty()==true){
			cout<<"Aucun Capteur dans la zone reessayer avec d'autres positions"<<endl;
	
		}else{
			clock_t debut2,fin2;
			debut2=clock();
			CalculeQualiteAir(latitude,longitude,rayon,annee,mois,jour,true);
			fin2=clock();
			float duree2=((double) (fin2-debut2))/CLOCKS_PER_SEC;
			cout<<endl;
			cout<<"La sous methode CalculerQualiteAir a pris "<<duree2<<" secondes"<<endl;
			cout<<endl;
			
		}
	}

}

void Analyse::AfficherCapteurs(){
	vector<Capteur>::iterator it;
	
		for (it=collectionCapteur.begin();it!=collectionCapteur.end();it++)
			{
				cout<<it->getCapteurID()<<" ; Latitude: "<<it->getLatitude()<<" ; Longitude: "<<it->getLongitude()<<endl;
			}
}

vector<Capteur>  Analyse::capteurDansLaZone(double longitude, double latitude, double rayon){
	vector<Capteur> listRep;
	vector<Capteur>::iterator it;
	
		for (it=collectionCapteur.begin();it!=collectionCapteur.end();it++)
			{
				
				if (sqrt( (latitude-atof((it->getLatitude()).c_str()))*(latitude-atof((it->getLatitude()).c_str())) + (longitude-atof((it->getLongitude()).c_str()))*(longitude-atof((it->getLongitude()).c_str())) ) < rayon && it->getDefaillant()!=true)
				{
					listRep.push_back(*it);
					
				}
			}
	return listRep;
}

void Analyse::afficherCapteur(vector<Capteur> list){
	vector<Capteur>::iterator it;
	
		for (it=list.begin();it!=list.end();it++)
			{
				cout<<it->getCapteurID()<<" ; Latitude: "<<it->getLatitude()<<" ; Longitude: "<<it->getLongitude()<<endl;
			}
	
}

/*double Analyse::CalculeQualiteAir(vector<Capteur> listCapt,string date){
	
	
	double O3=0.0;
	double NO2=0.0;
	double SO2=0.0;
	double PM10=0.0;
	double moyenne=0.0;
	int atmo =0;
	vector<Capteur>::iterator it3;
	vector<Mesure>::iterator it4;
	tm time=gettimem(date);
	
		for (it3=listCapt.begin();it3!=listCapt.end();it3++)
		{
			
				for (it4=it3->getListeMesure().begin();it4!=it3->getListeMesure().end();it4++)
				{
					
					if(it4->getTime()==time){
						moyenne++;
						if(it4->getAttributeID()=="O3"){
						O3+=atof((it4->getValue()).c_str());
						}else if(it4->getAttributeID()=="NO2"){
						
						
						NO2+=atof((it4->getValue()).c_str());
						
						}else if(it4->getAttributeID()=="SO2"){
						
						SO2+=atof((it4->getValue()).c_str());
						}else if(it4->getAttributeID()=="PM10"){
						
						
						PM10+=atof((it4->getValue()).c_str());
						
						}
					}
				}
		}
		moyenne=moyenne/4;
		O3=O3/moyenne;
		NO2=NO2/moyenne;
		SO2=SO2/moyenne;
		PM10=PM10/moyenne; 
		cout<<"O3 :"<<O3<<endl;
		cout<<"NO2 :"<<NO2<<endl;
		cout<<"SO2 :"<<SO2<<endl;
		cout<<"PM10 :"<<PM10<<endl;
		
		if ((0<O3 && O3< 29) || (0<SO2 && SO2<39) || (0<NO2 && NO2<29) || (0<PM10 && PM10<6)){
		 atmo=1;
			}

		if ((30<O3 && O3< 54) || (40<SO2 && SO2<79) || (30<NO2 && NO2< 54 )|| (7<PM10 && PM10<13)){
				atmo=2;
			}
			
		if ((55<O3 && O3< 79) || (80<SO2 && SO2<119) || (55<NO2 && NO2<84) || (14<PM10 && PM10<20)){
			atmo=3;
		}
		
		if ((80<O3 && O3< 104) || (120<SO2 && SO2<159) || (85<NO2 && NO2<109) || (21<PM10 && PM10<27)){
			atmo=4;
		}

		if (( 105<O3 && O3< 129) || (160<SO2 && SO2<199) || (110<NO2 && NO2<134) || (28<PM10 && PM10<34)){
			atmo=5;
		}

		if ((130<O3 && O3< 149) || (200<SO2 && SO2<249) || (135<NO2 && NO2<164) || (35< PM10 && PM10<41)){
			atmo=6;
		}

		if ((150<O3 && O3< 179) || (250<SO2 && SO2<299) || (165<NO2 && NO2<199) || (42<PM10 && PM10<49)){
			atmo=7;
		}

		if ((180<O3 && O3< 209) || (300<SO2 && SO2<399) || (200<NO2 && NO2<274) || (50<PM10 && PM10<64)){
			atmo=8;
		}
		
		if ((210<O3 && O3< 239) || (400<SO2 && SO2<499) || (275<NO2 && NO2<399) || (65<PM10 && PM10<79)){
			atmo=9;
		}

		if (240<=O3 || 500<=SO2 || 400<=NO2 || 80<=PM10){
			atmo=10;
		}
	return atmo;
}*/
int Analyse::CalculeQualiteAir(double lat, double lon, double rayon, int annee,int mois, int jour, bool affichage){
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
	vector<Capteur> sensorsDansZone=capteurDansLaZone(lon,lat,rayon);
	
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
			
			if((annee == m->getTime().tm_year)&&(mois == m->getTime().tm_mon+1)&&(jour == m->getTime().tm_mday))
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

	if(affichage) {
	//Affichage des resultats
	cout << "----Get Aggregate Infomation Algorithm----\n";
	if(totalMesuresPM10 == 0 || totalMesuresSO2 == 0 || totalMesuresO3 == 0 || totalMesuresNO2 == 0 ){
	cout << "Aucune Mesure ce jour la \n";
	}else{
	cout << "PM10 : " <<  moyPM10   << "\n";
	cout << "SO2 : " <<  moySO2   << "\n";
	cout << "O3 : " <<  moyO3   << "\n";
	cout << "NO2 : " <<  moyNO2   << "\n";
	cout << "Indice de qualite de l'air : " <<  indiceAtmo   << "\n";
	if(indiceAtmo <= 2){
	  cout << "Niveau : Tres bon\n";
	}else if(indiceAtmo <= 4){
	  cout << "Niveau : Bon\n";
	}else if(indiceAtmo <= 5){
	  cout << "Niveau : Moyen\n";
	}else if(indiceAtmo <= 7){
	  cout << "Niveau : Mediocre\n";
	}else if(indiceAtmo <= 9){
	  cout << "Niveau : Mauvais\n";
	}else if(indiceAtmo <= 10){
	  cout << "Niveau : Tres Mauvais\n";
	}
	}

	}
	return indiceAtmo;
}





Analyse::~Analyse ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

