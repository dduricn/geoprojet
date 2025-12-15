/*
Autheur: David Ndimina
Membre de l'equipe : David Ndimina Mamadou Siradiou Baldé
Date de remise du du projet: 14 déc. 2025 
Les technologie utilisées sont celles vue en classe
le fichier readme.txt explique toutes les decisions prise lors de l'ecriture de ce code 
*/

// importations des bibliotheques et des necessecités
#include <iostream>
#include <string>
#include <stdexcept>
#include "geoQuiz.h"
#include "geoExploration.h" 
using namespace std; 

// intstuctions des fonction du header 
// cas 1 : montant + devise 
double convertisseur(double montant, string devise)
{
    double montantConvertie =0.0;

    // flux d'instructions en fonction de la devise choisis
    if (devise =="usd")
    {
        montantConvertie = montant *  0.71; 
    }
    else if (devise =="euro")
    {
        montantConvertie = montant * 0.61;
    }
    else if (devise =="chf")
    {
        montantConvertie = montant * 0.57; 
    }
    else 
    {
        throw runtime_error("Devise inconnue: {devise}"); 
    }

    return montantConvertie; // renvoie la conversion du montant vers la devise choisie 
}
// cas 2 : devise par defaut avec montant defini 
double convertisseur(double montant)
{
    return convertisseur(montant,"chf");
}
// cas 3 : devise et montant par defaut 
double convertisseur()
{
    return convertisseur(150, "chf");
}

// etape 4 : geoExploration
void voyager (string *voyage, int etapes, int position)
{
    // verifie si le recursion est atteinte(position == etapes)
    if (position == etapes)
        return;

    // faire ceci autant de fois que la position dans le tableau n'est pas egale aux etapes du voyages 
    cout << " Etapes # : "<< position +1 << " du voyage"<<endl;
    cout <<"-> Nom de la  destination : "; 
    cin>>voyage[position]; /* ->voyages[postion], permet de stocker une destination une certaine position dans le tableau*/

    // la fonction qui sera utiliser dans geoExportation 
    voyager(voyage, etapes, position +1); // stockage complet du voyage: destination, etape, et position dans le tableau
}

void geoExploration (profil &profil_utilisateur)
{   
    // re-importation de la variables etapes 
    int etapes;
    do
    {
        cout << "Bievenue " << profil_utilisateur.nom<<endl;
        cout <<"Nombre etapes du voyage(entre 1 et 9) : "; cin >> etapes;

        // faire une porte logique or pour verifier le depassement si ca depasse 
        if (etapes < 1 || etapes >= 9)
        {
            cout << "Vous avez entrez un nombre d'etapes invalides, reesayer"<< endl; 
        }

    }while (etapes < 1 || etapes >= 9); 

    // tableau a taille dynamique crée a l'aide du pointeur *voyage et appel de cette derniere 
    string *voyage = new string[etapes]; 
    voyager(voyage, etapes);
    
    // boucle d'affichage du resumer du votage
    cout <<"*******************************"<<endl;
    for (int i=0; i<etapes; i++)
    {   
        cout<< voyage[i];
        if (i < etapes - 1)
        cout << " > ";
    }
    cout << endl;
    cout <<"*******************************"<<endl;
    // liberation de la memoire 
    delete[] voyage;
}