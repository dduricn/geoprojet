/*
Autheur: David Ndimina
Membre de l'equipe : David Ndimina ,Mamadou Siradiou Baldé
Date de remise du du projet: 14 déc. 2025 
Les technologie utilisées sont celles vue en classe
le fichier readme.txt explique toutes les decisions prise lors de l'ecriture de ce code 
*/
// importation des utilitaires et des bibliotheques utiles
#include <iostream>
#include <string>
#include "geoExploration.h"
#include "geoQuiz.h"
using namespace std; 

// creeons une structure qui permettra de redonner plus facilement le menu 
struct menu {
    char numeroMenu;
    string nomOptions; 
};

// creeons la fonction de renvoie et de prise du choix de l'utilisateur 
char afficherMenu(menu selection[], int taille) 
{
    // variable qui permet de recupere le choix de l'utilisateur 
    char choix;
    int score=0 ;
    // boucle d'affiche 
    for (int i=0; i<taille; i++)
    {
         cout << selection[i].numeroMenu << " =>" << selection[i].nomOptions << endl;
    }

    cout << "Que voulez vous consultez: ";
    cin >> choix;

    return choix;
}
// fonction de l'introduction du joueur avec l'utilisation d'une reference 

void introduction (profil &profil_utilisateur)
{
    cout <<"\nBienvenue au geoprojet"<<endl;
    cout<<"\nQuel est votre nom?" ; cin>> profil_utilisateur.nom; 
    profil_utilisateur.score =0; 
}

// fonction main

int main()
{
    // variable, si y'en a definir (ligne a supprimer a la fin de mon code )
    char choix; // choix de l'utilisateur
    profil Profil;

    // afficher les membres de l'equipe 
    cout <<"--Membre de l'equipe : David NDIMINA--"<<endl;

    // corps du code 
    menu selection [4] = {
        {'z', "Le géoquiz"},
        {'e', "La GeoExploration"},
        {'i', "Les GeoInformations"},
        {'q', "Quitter"}
    };
    
    // importation et affichage des donnees de la structure profil
    introduction(Profil);
    cout<< Profil.nom << " ton score est de : " << Profil.score <<endl;


    // boucle de repetion do while utilisé avec des switch 
    do 
    {
        cout << "\n==== Menu de selection ===="<<endl;
        choix = afficherMenu(selection, 4); // ==> rappelle la fonction char menu 

        switch(choix)
        {
            case 'z':
                cout << "« Bienvenue dans le géoquiz! »" << endl;
                geoQuiz(Profil); 
                break;

            case 'e':
                cout << "« Bienvenue dans la GeoExploration !»" << endl;
                geoExploration(Profil);
                break;

            case 'i':
            
                cout << "« Bienvenue dans les GeoInformations ! »" << endl;

                try {
                cout <<"\nVoici les conversions:"<<endl;
                cout << "100$ CAD ==> USD : "<< convertisseur (100,"usd")<<"$ USD"<<endl;
                cout << "100$ CAD ==> EURO : "<< convertisseur (100,"euro")<<"EURO"<<endl;
                cout <<"==>Conversion par defaut vers le franc suisse CHF"<<endl;
                cout << "100$ CAD ==> CHF : "<< convertisseur (100)<<"CHF"<<endl;
                cout <<"==>Conversion par defaut de 150$ CAD vers le franc suisse CHF"<<endl;
                cout << "CAD ==> CHF : "<< convertisseur ()<<"CHF"<<endl;
                double verification = convertisseur (100, "USD"); 
            } 
            catch (const exception& e) {
                cout << "==> Une erreur a ete dectecte lors de la conversion, pas le bon format de devise"<< endl;
            }
            
                break;
            case 'q':
                cout << "« L’utilisateur quitte. »" << endl;
                break;

            default:
                cout << "« L’utilisateur fait un choix invalide. »" << endl;
                break;

        }

    } while(choix != 'q');

    return 0;
}