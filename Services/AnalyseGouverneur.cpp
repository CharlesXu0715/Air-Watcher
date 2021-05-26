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

/*void AnalyseGouverneur::sensorsSimilairs(string capteurID, int dureeEnMois, float precision){

  sensorsSimilaires.clear();
  const float earthRadiusInKm = 6371;
  

  vector<Capteur>::iterator it;
  for (it=)

  //obtenir temps actuel
  time_t rawtime;
  struct tm * now;
  time (&rawtime);
  now = localtime (&rawtime); //right now in tm

  //obtenir nombre de mois et nombre d'annees de mesure
  int nbAnnees = (int)dureeEnMois/12+1;
  int nbMois = dureeEnMois%12;

  //obtenir rayon de mesure
  float radiusDegrees = rtod(rayonEnKm/earthRadiusInKm); //demi-taille de l'intervalle de lat/lon en degres
  float latitude = stof(lat);//string to float
  float longitude = stof(lon);
  map<Sensor, pair<float, unsigned int>, sensCompare> meanBySensor; //map des sensors avec leur moyenne de valeur et le nombre de valeurs ajoutees
                                                       //(pour diviser apres), je profite de la boucle qui parcours deja les sensors
  for(Sensor s : listSensor)
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
  for(Measure m : listMeasure)
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
  }
 return;
}*/


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*AnalyseGouverneur::AnalyseGouverneur ( const AnalyseGouverneur & uneAnalyseGouverneur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)
*/

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


