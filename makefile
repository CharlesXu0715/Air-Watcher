main: main.o  Analyse.o AnalyseFournisseur.o AnalyseGouverneur.o AnalyseUtilisateurPrive.o Capteur.o Cleaner.o Fournisseur.o Gouverneur.o LectureFichier.o Mesure.o UtilisateurPrive.o Attribut.o
	g++ -o main main.o  Analyse.o AnalyseFournisseur.o AnalyseGouverneur.o AnalyseUtilisateurPrive.o Capteur.o Cleaner.o Fournisseur.o Gouverneur.o LectureFichier.o Mesure.o UtilisateurPrive.o Attribut.o

Analyse.o: Analyse.cpp
		g++ -c -std=c++11 Analyse.cpp
		
AnalyseFournisseur.o: AnalyseFournisseur.cpp
		g++ -c -std=c++11 AnalyseFournisseur.cpp

AnalyseGouverneur.o: AnalyseGouverneur.cpp
		g++ -c -std=c++11 AnalyseGouverneur.cpp

AnalyseUtilisateurPrive.o: AnalyseUtilisateurPrive.cpp
		g++ -c -std=c++11 AnalyseUtilisateurPrive.cpp

Capteur.o: Capteur.cpp
		g++ -c -std=c++11 Capteur.cpp
		
Cleaner.o: Cleaner.cpp
		g++ -c -std=c++11 Cleaner.cpp

Fournisseur.o: Fournisseur.cpp
		g++ -c -std=c++11 Fournisseur.cpp
		
Gouverneur.o: Gouverneur.cpp
		g++ -c -std=c++11 Gouverneur.cpp
		
LectureFichier.o: LectureFichier.cpp
		g++ -c -std=c++11 LectureFichier.cpp

main.o: main.cpp
		g++ -c -std=c++11 main.cpp
		
Mesure.o: Mesure.cpp
		g++ -c -std=c++11 Mesure.cpp

UtilisateurPrive.o: UtilisateurPrive.cpp
		g++ -c -std=c++11 UtilisateurPrive.cpp
		
Attribut.o: Attribut.cpp
		g++ -c -std=c++11 Attribut.cpp

