#include <string>
#include "Capteur.h"
#include "Mesure.h"
#include "Fournisseur.h"
#include "Cleaner.h"
#include "UtilisateurPrive.h"
#include "Analyse.h"
#include "AnalyseGouverneur.h"
#include "LectureFichier.h"
#include "Gouverneur.h"
#include <iostream>
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
#include <fstream>





int main(int argc,char* argv[]){
	
	
	
	AnalyseGouverneur * ana = new AnalyseGouverneur();
	LectureFichier lec;
	ifstream fic("attributes.csv");
	lec.lectureAttribut(fic,ana->getListeAttribut());
	ifstream fic2("measurements.csv");
	lec.lectureMesure(fic2,ana->getListeMesure());
	ifstream fic3("sensors.csv");
	lec.lectureCapteur(fic3,ana->getListeCapteur(),ana->getListeMesure());
	ifstream fic4("cleaners.csv");
	lec.lectureCleaner(fic4,ana->getListeCleaner());
	ifstream fic5("providers.csv");
	lec.lectureFournisseur(fic5,ana->getListeFournisseur(),ana->getListeCleaner());
	ifstream fic6("users.csv");
	lec.lectureUtilisateurPrive(fic6,ana->getListeUtilisateurPrive(),ana->getListeCapteur());
	
	Gouverneur* gouvernement= new Gouverneur("10",ana->getListeCapteur(),ana->getListeCleaner());
	
	/*
	string buffer;
	
	vector<Attribut>::iterator it;
	
	
		for (it=ana->getListeAttribut().begin();it!=ana->getListeAttribut().end();it++)
		{
			buffer=it->getAttributID();
			if(buffer==""){
				cout<<"vide"<<endl;
			}
			
			cout<<buffer<<endl;
		}
		
	vector<Mesure>::iterator it2;
	
	
		for (it2=ana->getListeMesure().begin();it2!=ana->getListeMesure().end();it2++)
		{
			buffer=it2->getDate()+" "+it2->getCapteurID()+" "+it2->getAttributeID()+" "+it2->getValue();
			if(buffer==""){
				cout<<"vide"<<endl;
			}
			
			cout<<buffer<<endl;
		}
		
		vector<Capteur>::iterator it3;
		vector<Mesure>::iterator it4;
	
		for (it3=ana->getListeCapteur().begin();it3!=ana->getListeCapteur().end();it3++)
		{
			buffer=it3->getCapteurID()+" "+it3->getLongitude()+" "+it3->getLatitude();
			if(buffer==""){
				cout<<"vide"<<endl;
			}
			cout<<buffer<<endl;
				for (it4=it3->getListeMesure().begin();it4!=it3->getListeMesure().end();it4++)
				{
					buffer="     "+it4->getDate()+" "+it4->getCapteurID()+" "+it4->getAttributeID()+" "+it4->getValue();
					cout<<buffer<<endl;
				}
		
		}
		
		vector<Cleaner>::iterator it5;
		for (it5=ana->getListeCleaner().begin();it5!=ana->getListeCleaner().end();it5++)
		{
			buffer=it5->getCapteurID()+" "+it5->getLatitude()+" "+it5->getLongitude()+" "+it5->getDateDebut()+" "+it5->getDateFin();
			if(buffer==""){
				cout<<"vide"<<endl;
			}
			
			cout<<buffer<<endl;
		}
		
		
		vector<Fournisseur>::iterator it6;
		vector<Cleaner>::iterator it7;
		
		for (it6=ana->getListeFournisseur().begin();it6!=ana->getListeFournisseur().end();it6++)
		{
			buffer=it6->getFournisseurID();
			if(buffer==""){
				cout<<"vide"<<endl;
			}
			cout<<buffer<<endl;
			
				for (it7=it6->getListeCleaner().begin();it7!=it6->getListeCleaner().end();it7++)
				{
					buffer="    "+it7->getCapteurID()+" "+it7->getLatitude()+" "+it7->getLongitude()+" "+it7->getDateDebut()+" "+it7->getDateFin();
					cout<<buffer<<endl;
				}
				
		}
		
		vector<UtilisateurPrive>::iterator it8;
		vector<Capteur>::iterator it9;
		vector<Mesure>::iterator it10;
		
		for (it8=ana->getListeUtilisateurPrive().begin();it8!=ana->getListeUtilisateurPrive().end();it8++)
		{
			buffer=it8->getUtilisateurID();
			if(buffer==""){
				cout<<"vide"<<endl;
			}
			cout<<buffer<<endl;
				for (it9=it8->getListeCapteur().begin();it9!=it8->getListeCapteur().end();it9++)
				{
					buffer="    "+it9->getCapteurID()+" "+it9->getLongitude()+" "+it9->getLatitude();;
					cout<<buffer<<endl;
					
					for (it10=it9->getListeMesure().begin();it10!=it9->getListeMesure().end();it10++)
					{
						buffer="         "+it10->getDate()+" "+it10->getCapteurID()+" "+it10->getAttributeID()+" "+it10->getValue();
						cout<<buffer<<endl;
					}
					
				}
		
		}
		*/
		int select = 0;;
	string ID;
	double latitude;
	double longitude;
	double rayon;
	string date;
	string date1;
	string heure1;
	string date2;
	string heure2;
	bool gouv=false;
	bool util=false;
	bool four=false;
	string chemin;
	string cleanerID;
	string capteurID;

cout<<endl;
cout<<endl;
while(1){
	while(select<1||select>4){
	cout<<"Bienvenue sur AirWatcher! Entrez le numéro correspondant et appuyez sur Entrée."<<endl;
	cout<<"Quel type d'utilisateur êtes-vous?"<<endl;
	cout<<"1 - Gouvernement"<<endl;
	cout<<"2 - Utilisateur privé"<<endl;
	cout<<"3 - Fournisseur"<<endl;
	cout<<"4 - Quiter"<<endl;
	cin>>select;
	cout<<endl;
	cout<<endl;
	}
	switch(select){

		case 1:
		gouv=true;
		while(gouv){
		select = 0;
			while(select<1||select>7){
			cout<<"Que voulez-vous faire? Entrez le numéro correspondant et appuyez sur Entrée."<<endl;
			cout<<"1 - Identifier les capteurs défaillants"<<endl;
			cout<<"2 - Identifier les capteurs privés défaillants"<<endl;
			cout<<"3 - Produire des statistiques"<<endl;
			cout<<"4 - Tester la similarité"<<endl;
			cout<<"5 - Tester l'efficacité d'un Air'Cleaner"<<endl;
			cout<<"6 - Mesurer la qualité de l'air en un point"<<endl;
			cout<<"7 - Retour"<<endl;
			cin>>select;
			cout<<endl;
			cout<<endl;
			}
			switch(select){

				case 1:
				select = 0;
				break;

				case 2:
				select = 0;
				break;

				case 3:
				select=0;
					while(select<1||select>3){
					cout<<"Quel genre de statistique souhaitez-vous faire?"<<endl;
					cout<<"1 - Calculer la moyenne de qualité de l'air d'une zone à un instant donné"<<endl;
					cout<<"2 - Calculer la moyenne de qualité de l'air d'une zone sur une période donnée"<<endl;
					cout<<"3 - Retour"<<endl;
					cin>>select;
					cout<<endl;
					cout<<endl;
					}
					
					switch(select){

						case 1:
						cout<<"nous allons déterminer la zone circulaire de recherche, entrez la latitude de centre de la zone"<<endl;
						cin>>latitude;
						cout<<"nous allons déterminer la zone circulaire de recherche, entrez la longiude de centre de la zone"<<endl;
						cin>>longitude;
						cout<<"nous allons déterminer la zone circulaire de recherche, entrez le rayon de centre de la zone"<<endl;
						cin>>rayon;
						cout<<"Entrez la date de recherche au format aaaa-mm-jj"<<endl;
						cin>>date1;
						cout<<"Entrez l'heure de recherche au format hh:mm:ss"<<endl;
						cin>>heure1;

						cout<<endl;
						cout<<endl;
						select = 0;
						break;


						case 2:
						cout<<"nous allons déterminer la zone circulaire de recherche, entrez la latitude de centre de la zone"<<endl;
						cin>>latitude;
						cout<<"nous allons déterminer la zone circulaire de recherche, entrez la longiude de centre de la zone"<<endl;
						cin>>longitude;
						cout<<"nous allons déterminer la zone circulaire de recherche, entrez le rayon de centre de la zone"<<endl;
						cin>>rayon;
						cout<<"Entrez la date de recherche au format aaaa-mm-jj"<<endl;
						cin>>date1;
						cout<<"Entrez l'heure de recherche au format hh:mm:ss"<<endl;
						cin>>heure1;
						cout<<"Entrez la date de recherche au format aaaa-mm-jj"<<endl;
						cin>>date2;
						cout<<"Entrez l'heure de recherche au format hh:mm:ss"<<endl;
						cin>>heure2;

						cout<<endl;
						cout<<endl;
						select = 0;
						break;

						case 3:
						cout<<endl;
						cout<<endl;
						select = 0;
						break;

					}

				select = 0;
				break;

				case 4:
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

				case 5:
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

				case 6:
					cout<<"nous allons déterminer le point de recherche, entrez la latitude de ce point"<<endl;
					cin>>latitude;
					cout<<"nous allons déterminer le point de recherche, entrez la longiude de ce point"<<endl;
					cin>>longitude;
					cout<<"Entrez la date de recherche au format aaaa-mm-jj"<<endl;
					cin>>date1;
					cout<<"Entrez l'heure de recherche au format hh:mm:ss"<<endl;
					cin>>heure1;
					date=date1;
					date=date+" ";
					date= date+ heure1;
					cout<<"la qualité de l'air à "<<to_string(longitude)<<" "+to_string(latitude)<<" à "<<date<<" est :"<<endl;
					ana->QualitePointMoment(longitude, latitude, date);
					cout<<endl;
					cout<<endl;
				select = 0;
				break;

				case 7:
				gouv = false;
				cout<<endl;
				cout<<endl;
				select = 0;
				break;
			}
			}
		break;

		case 2:
			cout<<"Entrez votre identifiant"<<endl;
			cin>>ID;cout<<endl;
			cout<<endl;
			cout<<endl;
			util = true;
			while(util){
			select=0;
			while(select<1||select>5){
				cout<<"Bienvenue "<<ID<<"Que voulez-vous faire? Entrez le numéro correspondant et appuyez sur Entrée."<<endl;
				cout<<"1 - Fournir mon capteur privé"<<endl;
				cout<<"2 - Mettre à jour les données de mon capteur"<<endl;
				cout<<"3 - Supprimer un de mes capteurs"<<endl;
				cout<<"4 - Consulter mes points"<<endl;
				cout<<"5 - Retour"<<endl;
				cin>>select;
				cout<<endl;
				cout<<endl;
			}

			switch(select){

				case 1:
				cout<<"Entrez le chemin entier de fotre fichier type <<mesure.csv>> "<<endl;
				cin>>chemin;
				cout<<"Entrez la latitude de votre capteur"<<endl;
				cin>>latitude;
				cout<<"Entrez la longitude de votre capteur"<<endl;
				cin>>longitude;
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

				case 2:
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

				case 3:
				cout<<"Entrez le nom de votre capteur à supprimer "<<endl;
				cin>>cleanerID;
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

				case 4:
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

				case 5:
				util= false;
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

			}
			}

		select = 0;
		break;

		case 3:
			cout<<"Entrez votre identifiant"<<endl;
			cin>>ID;
			cout<<endl;
			cout<<endl;
			four = true;
			while(four){
			select=0;
			while(select<1||select>5){
				cout<<"Bienvenue "<<ID<<" Que voulez-vous faire? Entrez le numéro correspondant et appuyez sur Entrée."<<endl;
				cout<<"1 - Fournir mon Air'Cleaner privé"<<endl;
				cout<<"2 - Supprimer un de mes Air'Cleaners"<<endl;
				cout<<"3 - Entrer la date de fin de fonctionnement d'un de mes Air'Cleaners"<<endl;
				cout<<"4 - Calculer la qualité de l'air autour d'un de mes Air'Cleaners"<<endl;
				cout<<"5 - Retour"<<endl;
				cin>>select;
				cout<<endl;
				cout<<endl;
			}

			switch(select){

				case 1:
				cout<<"Entrez le nom de votre Air'Cleaner "<<endl;
				cin>>cleanerID;
				cout<<"Entrez la latitude de votre Air'Cleaner"<<endl;
				cin>>latitude;
				cout<<"Entrez la longitude de votre Air'Cleaner"<<endl;
				cin>>longitude;
				cout<<"Entrez la date de début de fontionnement au format aaaa-mm-jj"<<endl;
				cin>>date1;
				cout<<"Entrez l'heure de début de fontionnement au format hh:mm:ss"<<endl;
				cin>>heure1;
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

				case 2:
				cout<<"Entrez le nom de votre Air'Cleaner à supprimer "<<endl;
				cin>>cleanerID;
				select = 0;
				cout<<endl;
				cout<<endl;
				break;

				case 3:
				cout<<"Entrez le nom de votre Air'Cleaner "<<endl;
				cin>>cleanerID;
				cout<<"Entrez la date de fin de fontionnement au format aaaa-mm-jj"<<endl;
				cin>>date1;
				cout<<"Entrez l'heure de fin de fontionnement au format hh:mm:ss"<<endl;
				cin>>heure1;
				select = 0;
				break;

				case 4:
				cout<<"Entrez le nom de votre Air'Cleaner "<<endl;
				cin>>cleanerID;
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

				case 5:
				four= false;
				cout<<endl;
				cout<<endl;
				select = 0;
				break;

			}
			}

		select = 0;
		break;

	}

	if(select==4){
		cout<<"Merci d'avoir utilisé AirWatcher"<<endl;
		cout<<endl;
		cout<<endl;
		break;
	}
}
	
		
		
		
	return 0;
}
