
//Import de librairies
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

//fonctions servant à l'affichage Terminal
int MenuPrincipal();

int MenuGouv();
int MenuStatGouv();
void MenuMoyZoneMoment();
void MenuMoyZonePeriode();
void MenuQualitePointMoment();

int MenuUtilisateur(string);
void MenuAjouterCapteur();
void MenuSupprimerCapteur();

int MenuFournisseur(string);
void MenuAjouterCleaner();
void MenuSupprimerCleaner();
void MenuFinCleaner();
void MenuQualiteCleaner();


//Variables servant à appeler les fonctions
AnalyseGouverneur * ana = new AnalyseGouverneur();





int main(int argc,char* argv[]){
	
	//Phase de lecture et de stockage de toutes les données contenues dans les fichiers .csv		
	
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
	
	//Variable servant a naviguer dans les switch cases
	int select = 0;
	
	//Booléens indiquant quel type d'utilisateur est en train d'interragir
	bool gouv=false;
	bool util=false;
	bool four=false;

	//Identifiant de l'utilisateur
	string ID;

	//Booléen a "true" tant que le programme est en cours (on le passe a false lorsqu'on l'arrête)
	bool running=true;




	//A partir d'ici, le main est une suite de switch case qui sert a naviguer dans les divers menu du programme.

	while(running){
		select=MenuPrincipal();
	
		switch(select){

//////////////////////////////////// Gouvernement ///////////////////////////////////////////////////////////////

			case 1:
				gouv=true;

				while(gouv){
				select = MenuGouv();

					switch(select){

						case 1:
							//Méthode Capteurs défaillants
							select = 0;
						break;

						case 2:
							//Méthode Capteurs privés défaillants
							select = 0;
						break;

						case 3:
							select=MenuStatGouv();
										
							switch(select){

								case 1:
									MenuMoyZoneMoment();
									select = 0;
								break;


								case 2:
									MenuMoyZonePeriode();
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
							//méthode Similarité
							cout<<endl;
							cout<<endl;
							select = 0;
						break;

						case 5:
							//méthode efficacité air cleaner
							cout<<endl;
							cout<<endl;
							select = 0;
						break;

						case 6:
							MenuQualitePointMoment();
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

///////////////////////////////////// Utilisateur ////////////////////////////////////////////////////////////////////

			case 2:

				cout<<"Entrez votre identifiant"<<endl;
				cin>>ID;cout<<endl;
				cout<<endl;
				cout<<endl;
				util = true;

				while(util){
					select=MenuUtilisateur(ID);
					

					switch(select){

						case 1:
						MenuAjouterCapteur();
						select = 0;
						break;

						case 2:
						//Méthode MAJCapteur
						cout<<endl;
						cout<<endl;
						select = 0;
						break;

						case 3:
						MenuSupprimerCapteur();
						select = 0;
						break;

						case 4:
						//Méthode ConsulterPoints
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


/////////////////////////////////// Fournisseur ////////////////////////////////////////////////////////////////

			case 3:

				cout<<"Entrez votre identifiant"<<endl;
				cin>>ID;
				cout<<endl;
				cout<<endl;
				four = true;

				while(four){

					select=MenuFournisseur(ID);

					switch(select){

						case 1:
							MenuAjouterCleaner();
							select = 0;
						break;

						case 2:
							MenuSupprimerCleaner();
							select = 0;
						break;

						case 3:
							MenuFinCleaner();
							select = 0;
						break;

						case 4:
							MenuQualiteCleaner();
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

			case 4:
				cout<<"Merci d'avoir utilisé AirWatcher"<<endl;
				running = false;
				cout<<endl;
				cout<<endl;
			break;
		
		}
	}
		
	return 0;
}














//Définitions des fonctions d'affichage dans le terminal


int MenuPrincipal(){
	int select=0;
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
	return select;
}

int MenuGouv(){
	int select=0;
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
	return select;
}

int MenuStatGouv(){
	int select=0;
	while(select<1||select>3){
		cout<<"Quel genre de statistique souhaitez-vous faire?"<<endl;
		cout<<"1 - Calculer la moyenne de qualité de l'air d'une zone à un instant donné"<<endl;
		cout<<"2 - Calculer la moyenne de qualité de l'air d'une zone sur une période donnée"<<endl;
		cout<<"3 - Retour"<<endl;
		cin>>select;
		cout<<endl;
		cout<<endl;
	}
	return select;
}

void MenuMoyZoneMoment(){
	double longitude;
	double latitude;
	double rayon;
	string date1;
	string heure1;
	string date;

	cout<<"nous allons déterminer la zone circulaire de recherche, entrez la latitude du centre de la zone"<<endl;
	cin>>latitude;
	cout<<"nous allons déterminer la zone circulaire de recherche, entrez la longitude du centre de la zone"<<endl;
	cin>>longitude;
	cout<<"nous allons déterminer la zone circulaire de recherche, entrez le rayon de la zone"<<endl;
	cin>>rayon;
	cout<<"Entrez la date de recherche au format aaaa-mm-jj"<<endl;
	cin>>date1;
	cout<<"Entrez l'heure de recherche au format hh:mm:ss"<<endl;
	cin>>heure1;
	cout<<endl;
	cout<<endl;
	//Méthode Moy Zone Moment

}

void MenuMoyZonePeriode(){
	double longitude;
	double latitude;
	double rayon;
	string date1;
	string heure1;
	string date2;
	string heure2;
	string date;

	cout<<"nous allons déterminer la zone circulaire de recherche, entrez la latitude du centre de la zone"<<endl;
	cin>>latitude;
	cout<<"nous allons déterminer la zone circulaire de recherche, entrez la longitude du centre de la zone"<<endl;
	cin>>longitude;
	cout<<"nous allons déterminer la zone circulaire de recherche, entrez le rayon de la zone"<<endl;
	cin>>rayon;
	cout<<"Entrez la date de début de recherche au format aaaa-mm-jj"<<endl;
	cin>>date1;
	cout<<"Entrez l'heure de début de recherche au format hh:mm:ss"<<endl;
	cin>>heure1;
	cout<<"Entrez la date de fin de recherche au format aaaa-mm-jj"<<endl;
	cin>>date2;
	cout<<"Entrez l'heure de fin de recherche au format hh:mm:ss"<<endl;
	cin>>heure2;
	cout<<endl;
	cout<<endl;
	//Méthode Moy Zone Periode
}

void MenuQualitePointMoment(){
	double longitude;
	double latitude;
	string date1;
	string heure1;
	string date;

	cout<<"nous allons déterminer le point de recherche, entrez la latitude de ce point"<<endl;
	cin>>latitude;
	cout<<"nous allons déterminer le point de recherche, entrez la longitude de ce point"<<endl;
	cin>>longitude;
	cout<<"Entrez la date de recherche au format aaaa-mm-jj"<<endl;
	cin>>date1;
	cout<<"Entrez l'heure de recherche au format hh:mm:ss"<<endl;
	cin>>heure1;

	cout<<"la qualité de l'air à "<<to_string(longitude)<<" "+to_string(latitude)<<" à "<<date<<" est :"<<endl;
	ana->QualitePointMoment(longitude, latitude, date);
	cout<<endl;
	cout<<endl;
}

int MenuUtilisateur(string ID){
	int select = 0;
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
	return select;
}

void MenuAjouterCapteur(){
	string chemin;
	double latitude;
	double longitude;

	cout<<"Entrez le chemin entier de fotre fichier type <<mesure.csv>> "<<endl;
	cin>>chemin;
	cout<<"Entrez la latitude de votre capteur"<<endl;
	cin>>latitude;
	cout<<"Entrez la longitude de votre capteur"<<endl;
	cin>>longitude;
	cout<<endl;
	cout<<endl;
	//Méthode AjouterCapteur
}

void MenuSupprimerCapteur(){
	string capteurID;
	cout<<"Entrez le nom de votre capteur à supprimer "<<endl;
	cin>>capteurID;
	//Méthode Supprimer capteur
	cout<<endl;
	cout<<endl;
}

int MenuFournisseur(string ID){
	int select = 0;
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
	return select;

}

void MenuAjouterCleaner(){
	string cleanerID;
	double latitude;
	double longitude;
	string date;
	string date1;
	string heure1;

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
	date=date1;
	date=date+" ";
	date= date+ heure1;
	cout<<endl;
	cout<<endl;
	//Methode AjouterCleaner
}

void MenuSupprimerCleaner(){
	string cleanerID;

	cout<<"Entrez le nom de votre Air'Cleaner à supprimer "<<endl;
	cin>>cleanerID;
	cout<<endl;
	cout<<endl;
	//Methode SupprimerCleaner
}

void MenuFinCleaner(){
	string cleanerID;
	string date;
	string date1;
	string heure1;

	cout<<"Entrez le nom de votre Air'Cleaner "<<endl;
	cin>>cleanerID;
	cout<<"Entrez la date de fin de fontionnement au format aaaa-mm-jj"<<endl;
	cin>>date1;
	cout<<"Entrez l'heure de fin de fontionnement au format hh:mm:ss"<<endl;
	cin>>heure1;
	//Methode FinCleaner
}

void MenuQualiteCleaner(){
	string cleanerID;

	cout<<"Entrez le nom de votre Air'Cleaner "<<endl;
	cin>>cleanerID;
	cout<<endl;
	cout<<endl;
	//Methode qualite air cleaner
}