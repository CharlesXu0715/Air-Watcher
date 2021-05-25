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
	lec.lectureMesure(fic2,ana->getListeMesure(),ana->getListeAttribut());
	ifstream fic3("sensors.csv");
	lec.lectureCapteur(fic3,ana->getListeCapteur(),ana->getListeMesure());
	ifstream fic4("cleaners.csv");
	lec.lectureCleaner(fic4,ana->getListeCleaner());
	ifstream fic5("providers.csv");
	lec.lectureFournisseur(fic5,ana->getListeFournisseur(),ana->getListeCleaner());
	ifstream fic6("users.csv");
	lec.lectureUtilisateurPrive(fic6,ana->getListeUtilisateurPrive(),ana->getListeCapteur());
	
	Gouverneur* gouvernement= new Gouverneur("10",ana->getListeCapteur(),ana->getListeCleaner());
	
	
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
					//ana->QualitePointMoment(longitude, latitude, date);
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
