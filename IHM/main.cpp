
//Import de librairies
#include <string>
#include "../Données/Capteur.h"
#include "../Données/Mesure.h"
#include "../Données/Fournisseur.h"
#include "../Données/Cleaner.h"
#include "../Données/UtilisateurPrive.h"
#include "../Services/Analyse.h"
#include "../Services/AnalyseGouverneur.h"
#include "../Données/LectureFichier.h"
#include "../Données/Gouverneur.h"
#include <iostream>
#include <iostream>
using namespace std;
#include <fstream>

//fonctions servant à l'affichage Terminal
int MenuPrincipal();

int MenuGouv();
int MenuStatGouv();
void MenuMoyZoneMoment();
void MenuMoyZonePeriode();
void MenuQualitePointMoment(AnalyseGouverneur *);

int MenuUtilisateur(string);
void MenuAjouterCapteur();
void MenuSupprimerCapteur();

int MenuFournisseur(string);
void MenuAjouterCleaner();
void MenuSupprimerCleaner();
void MenuFinCleaner();
void MenuQualiteCleaner();

//Variable servant a naviguer dans les switch cases
AnalyseGouverneur * ana;






int main(int argc,char* argv[]){
	
	//Phase de lecture et de stockage de toutes les données contenues dans les fichiers .csv		
	
	//Variables servant à appeler les fonctions
	
	ifstream fic("./FichiersCSV/attributes.csv");
	vector<Attribut> listAttribut=LectureFichier::lectureAttribut(fic);
	ifstream fic2("./FichiersCSV/MeasurementTest2.csv");
	vector<Mesure> listMesure=LectureFichier::lectureMesure(fic2,listAttribut);
	ifstream fic3("./FichiersCSV/SensorTest.csv");
	vector<Capteur> listCapteur=LectureFichier::lectureCapteur(fic3,listMesure);
	ifstream fic4("./FichiersCSV/cleanersTest.csv");
	vector<Cleaner> listCleaner=LectureFichier::lectureCleaner(fic4);
	ifstream fic5("./FichiersCSV/providers.csv");
	vector<Fournisseur> listProvider=LectureFichier::lectureFournisseur(fic5,listCleaner);
	ifstream fic6("./FichiersCSV/users.csv");
	vector<UtilisateurPrive> listUP=LectureFichier::lectureUtilisateurPrive(fic6,listCapteur);
	AnalyseGouverneur * ana = new AnalyseGouverneur(listAttribut,listMesure,listCapteur,listCleaner,listProvider,listUP);
	Gouverneur* gouvernement= new Gouverneur("10",ana->getListeCapteur(),ana->getListeCleaner());
	
	
	
	int select = 0;;
	
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
							//ana->QualitePointMoment(1.8, 44.0, 2019, 8,11);
							MenuQualitePointMoment(ana);
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
	int annee;
	int mois;
	int jour;

	cout<<"nous allons déterminer la zone circulaire de recherche, entrez la latitude du centre de la zone"<<endl;
	cin>>latitude;
	cout<<"nous allons déterminer la zone circulaire de recherche, entrez la longitude du centre de la zone"<<endl;
	cin>>longitude;
	cout<<"nous allons déterminer la zone circulaire de recherche, entrez le rayon de la zone"<<endl;
	cin>>rayon;
	cout<<"Entrez le jour de recherche"<<endl;
	cin>>jour;
	cout<<"Entrez le mois de recherche (en chiffre, par exemple pour mars entrez \"03\")"<<endl;
	cin>>mois;
	cout<<"Entrez l'année de recherche"<<endl;
	cin>>annee;
	
	
	
	cout<<endl;
	cout<<endl;
	//Méthode Moy Zone Moment

}

void MenuMoyZonePeriode(){
	double longitude;
	double latitude;
	double rayon;
	int anneeDebut;
	int moisDebut;
	int jourDebut;
	int anneeFin;
	int moisFin;
	int jourFin;

	cout<<"nous allons déterminer la zone circulaire de recherche, entrez la latitude du centre de la zone"<<endl;
	cin>>latitude;
	cout<<"nous allons déterminer la zone circulaire de recherche, entrez la longitude du centre de la zone"<<endl;
	cin>>longitude;
	cout<<"nous allons déterminer la zone circulaire de recherche, entrez le rayon de la zone"<<endl;
	cin>>rayon;
	cout<<"Entrez le jour de début derecherche"<<endl;
	cin>>jourDebut;
	cout<<"Entrez le mois de début de recherche (en chiffre, par exemple pour mars entrez \"03\")"<<endl;
	cin>>moisDebut;
	cout<<"Entrez l'année de début de recherche"<<endl;
	cin>>anneeDebut;
	cout<<"Entrez le jour de fin derecherche"<<endl;
	cin>>jourFin;
	cout<<"Entrez le mois de fin de recherche (en chiffre, par exemple pour mars entrez \"03\")"<<endl;
	cin>>moisFin;
	cout<<"Entrez l'année de fin de recherche"<<endl;
	cin>>anneeFin;
	cout<<endl;
	cout<<endl;
	//Méthode Moy Zone Periode
}

void MenuQualitePointMoment(AnalyseGouverneur * ana2){
	double longitude;
	double latitude;
	int annee;
	int mois;
	int jour;

	cout<<"nous allons déterminer le point de recherche, entrez la latitude de ce point"<<endl;
	cin>>latitude;
	cout<<"nous allons déterminer le point de recherche, entrez la longitude de ce point"<<endl;
	cin>>longitude;
	cout<<"Entrez le jour de recherche"<<endl;
	cin>>jour;
	cout<<"Entrez le mois de recherche (en chiffre, par exemple pour mars entrez \"03\")"<<endl;
	cin>>mois;
	cout<<"Entrez l'année de recherche"<<endl;
	cin>>annee;

	cout<<"la qualité de l'air en "<<to_string(latitude)<<" / "+to_string(longitude)<<" le "<<to_string(jour)<<"/"<<to_string(mois)<<"/"<<to_string(annee)<<" est :"<<endl;
	ana2->QualitePointMoment(longitude, latitude, annee, mois, jour);
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
	int annee;
	int mois;
	int jour;

	cout<<"Entrez le nom de votre Air'Cleaner "<<endl;
	cin>>cleanerID;
	cout<<"Entrez la latitude de votre Air'Cleaner"<<endl;
	cin>>latitude;
	cout<<"Entrez la longitude de votre Air'Cleaner"<<endl;
	cin>>longitude;
	cout<<"Entrez le jour de début de fonctionnement de votre Air'Cleaner"<<endl;
	cin>>jour;
	cout<<"Entrez le mois de fonctionnement de votre Air'Cleaner (en chiffre, par exemple pour mars entrez \"03\")"<<endl;
	cin>>mois;
	cout<<"Entrez l'année de fonctionnement de votre Air'Cleaner"<<endl;
	cin>>annee;
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
	int annee;
	int mois;
	int jour;

	cout<<"Entrez le nom de votre Air'Cleaner "<<endl;
	cin>>cleanerID;
	cout<<"Entrez le jour de fin de fonctionnement du Air'Cleaner"<<endl;
	cin>>jour;
	cout<<"Entrez le mois de fin de fonctionnement du Air'Cleaner (en chiffre, par exemple pour mars entrez \"03\")"<<endl;
	cin>>mois;
	cout<<"Entrez l'année de fin de fonctionnement du Air'Cleaner"<<endl;
	cin>>annee;
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
