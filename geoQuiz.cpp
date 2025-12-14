/*
Autheur: David Ndimina
Membre de l'equipe : David Ndimina Mamadou Siradiou Baldé
Date de remise du du projet: 14 déc. 2025 
Les technologie utilisées sont celles vue en classe
le fichier readme.txt explique toutes les decisions prise lors de l'ecriture de ce code 
*/


#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

#include "geoQuiz.h"

using namespace std;

// code du prof ainsi que les explications 
Question* chargerQuestions(int& nombreQuestions) // fonction qui renvoie/gere un tableau dynamique de questions, pointeur
{
    random_device rd;
    mt19937 generateur(rd()); // fonction qui peremet de generer des nombres aleatoires, maais dans ce cas ca va etre les indices du tableau lieés aux questions


    Question* questions = nullptr; // pointe vers rien au debut 

    try // gestion des exceptions avec try catch
    {
        ifstream fichier("quiz.txt"); // cette ligne permet d'ouvrir le fichier quiz.txt
        fichier.exceptions(ios::failbit | ios::badbit);

        string nbQuestionsString;
        getline(fichier, nbQuestionsString); // fonction getline pour la lecture complete comme vu dans les laboratoires 
        nombreQuestions = stoi(nbQuestionsString);

        questions = new Question[nombreQuestions]; // creer le tableau 

        for (int x = 0; x < nombreQuestions; x++)
        {
            string ligne;
            getline(fichier, ligne);
            chargerQuestion(questions[x], ligne);
        } // boucle des questions, sortir les boucles jusqu'a atteindre le nombre de questions 

        shuffle(questions, questions + nombreQuestions, generateur); 
    }
    catch (const exception& e)
    {
        cerr << "EXCEPTION : " << e.what() << endl;
    }

    return questions;
}
void chargerQuestion(Question& question, string lecture) // fonction qui permet de charger une question a partir d'une ligne lue dans le fichier
{
    // reprensentent les variables de cette fonction, qui permettent la gestions et prise des reponses aux questions 
    vector<string> elements;
    stringstream flux(lecture);
    string item;

    while (getline(flux, item, ';'))
        elements.push_back(item); // differencier chaque element grace au ';', et les stocker dans un vecteur grace a flux et vector

    question.pays = elements[0];

    for (int noQ = 0; noQ < 5; noQ++)
        question.capitales[noQ] = elements[noQ + 1]; // remplir le tableau des capitales

    question.reponse = stoi(elements[6]) - 1; 
}// fin du code du prof 

// Etape 8: gestion des questions
Question& chargerQuestionDepuisTableau(Question* questions, int index)
{
    return questions[index]; // retourne la qestion a l'index 
}

void afficherQuestion(const Question& question) // afficher la question et les choix de reponses
{
    cout << "\nPays : " << question.pays << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << (i + 1) << ") " << question.capitales[i] << endl;
    }     // boucle pour afficher les choix de reponses
}

// Etape 9: choix et validation de la reponse de l'utilisateur
int poserQuestionEtCalculerPoints(const Question& question) // fonction qui permet de poser la question et de calculer les points
{
    int choix = 0;
    cout << "Votre choix (1 a 5) : ";
    cin >> choix;

    int indexChoisi = choix - 1;

    if (indexChoisi == question.reponse)
    {
        cout << "Bonne reponse : +2 points" << endl;
        return 2; // bonne reponse
    }
    else
    {
        cout << "Mauvaise reponse : -1 point" << endl;
        cout << "Bonne reponse : " << question.capitales[question.reponse] << endl;
        return -1;   //// mauvaise reponse
    }
}

// renvoyez les questions au choix de la case 'z' du menu 
void geoQuiz(profil &profil_utilisateur)
{
    int nombreQuestions = 0;
    Question* questions = chargerQuestions(nombreQuestions);
    if (questions == nullptr || nombreQuestions <= 0)
    {
        cout << "Verification, au cas ou le fichier n'est pas a bonne place." << endl;
        return; // verificaton 
    }
    int nbQuestionsPartie = 5; //renvoie le nombre de questions (5)
    if (nombreQuestions < nbQuestionsPartie)
        nbQuestionsPartie = nombreQuestions;

    int total = 0; // compteur du score total 

    for (int i = 0; i < nbQuestionsPartie; i++)
    {
        Question& q = chargerQuestionDepuisTableau(questions, i); // charger la question depuis le tableau
        afficherQuestion(q);
        total += poserQuestionEtCalculerPoints(q);
        cout << "Total actuel : " << total << endl; // compter les points 
    }

    cout << "\n=== Fin de la partie ===" << endl;
    cout << "Score de la partie : " << total << endl;

    if (total > profil_utilisateur.score) // verifier si le score est un nouveau record
    {
        cout << "Bravo ! Nouveau record !" << endl;
        cout << "Ancien record { " << profil_utilisateur.score << " }" << endl;
        cout << "Nouveau record {" << total << "}" << endl;
        profil_utilisateur.score = total;
    }
    else // pas de nouveau record
    {
        cout << "Record actuel { " << profil_utilisateur.score << " }" << endl;
        cout << "Vous n'avez pas battu votre record." << endl;
    }

    delete[] questions;
}
