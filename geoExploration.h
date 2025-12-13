/*
Autheur: David Ndimina
Membre de l'equipe : David Ndimina
Date de remise du du projet: 14 déc. 2025 
Les technologie utilisées sont celles vue en classe
le fichier readme.txt explique toutes les decisions prise lors de l'ecriture de ce code 
*/

// importations des bibliotheques et des necessecités
#ifndef GEOEXPLORATION_H
#define GEOEXPLORATION_H
#include "geoQuiz.h"
#include <iostream>
#include <string>
using namespace std;

//utilisation des surcharge pour matcher avec les cout du prof
double convertisseur(double montant, string devise); 
double convertisseur (double montant); 
double convertisseur();

// ajout des fonctions de l'etape 4: geoExploration et voyager 

void geoExploration (profil &profil_utilisateur);
void voyager (string *voyage, int etapes, int position=0);

#endif // ----> empecehr les inclusions multiples