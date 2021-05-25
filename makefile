
main: IHM/main.o  Services/Analyse.o Services/AnalyseFournisseur.o Services/AnalyseGouverneur.o Services/AnalyseUtilisateurPrive.o Données/Capteur.o Données/Cleaner.o Données/Fournisseur.o Données/Gouverneur.o Données/LectureFichier.o Données/Mesure.o Données/UtilisateurPrive.o Données/Attribut.o
	g++ -o main IHM/main.o  Services/Analyse.o Services/AnalyseFournisseur.o Services/AnalyseGouverneur.o Services/AnalyseUtilisateurPrive.o Données/Capteur.o Données/Cleaner.o Données/Fournisseur.o Données/Gouverneur.o Données/LectureFichier.o Données/Mesure.o Données/UtilisateurPrive.o Données/Attribut.o

%.o: %.cpp
	g++ -o $@ -c -std=c++11 $^
		
clean:
	rm -f */*.o
