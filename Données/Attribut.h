/*************************************************************************
                           Attribut  -  description
                             -------------------
    copyright            : (C) XU Yuantao
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( Attribut_H )
#define Attribut_H

#include <string.h>
using namespace std;



class Attribut
{
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------- Constructeurs
    Attribut (string unit, string description, string id);

    Attribut ();

//-------------------------------------------- getters

    string getUnit();

    string getID();

    string getDescription();

//-------------------------------------------- setters

    void setUnit(string unit);

    void setDescription(string description);

    virtual ~Attribut ( );



protected:

//----------------------------------------------------- Attributs protégés

string attributeID;
string unit;
string description;

};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // Attribut_H
