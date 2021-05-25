
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
#include <math.h>
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
Analyse::Analyse ( const Analyse & uneAnalyse )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)


Analyse::Analyse ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif

   
    
} //----- Fin de Analyse
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

void Analyse::QualitePointMoment(double longitude, double latitude, string date){
	double rayon =2;
	vector<Capteur> listCapt (capteurDansLaZone(longitude,latitude,rayon));
	if(listCapt.empty()==true){
		cout<<"Aucun Capteur dans la zone reessayer avec d'autres positions"<<endl;
	}else{
		cout<<CalculeQualiteAir(listCapt,date)<<endl;
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

double Analyse::CalculeQualiteAir(vector<Capteur> listCapt,string date){
	
	
	double O3=0.0;
	double NO2=0.0;
	double SO2=0.0;
	double PM10=0.0;
	double moyenne=0.0;
	double atmo =0.0;
	vector<Capteur>::iterator it3;
	vector<Mesure>::iterator it4;
	
		for (it3=listCapt.begin();it3!=listCapt.end();it3++)
		{
			
				for (it4=it3->getListeMesure().begin();it4!=it3->getListeMesure().end();it4++)
				{
					
					if(it4->getDate()==date){
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

