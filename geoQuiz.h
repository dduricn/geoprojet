/*
Autheur: David Ndimina
Membre de l'equipe : David Ndimina Mamadou Siradiou Baldé
Date de remise du du projet: 14 déc. 2025 
Les technologie utilisées sont celles vue en classe
le fichier readme.txt explique toutes les decisions prise lors de l'ecriture de ce code 
*/

// importation des utilitaires et des bibliotheques utiles
#include <iostream>
#include <string>
using namespace std;

#ifndef GEOQUIZ_H
#define GEOQUIZ_H

// structure de profil: 
struct profil   
{
    string nom;
    int score;
};

// structure de question : 
struct Question  
{
    string pays;
    string capitales[5];
    int reponse;

};

// les fonctions de geoQuiz


void geoQuiz(profil &profil_utilisateur); // importe geoQuiz.cpp dans le main 

// fonction donnée par le prof 
Question* chargerQuestions(int& nombreQuestions);
void chargerQuestion(Question& question, string lecture);

// fonction supplementaire a implemeter, celle pas données par le prof 
Question& chargerQuestionDepuisTableau(Question* questions, int index);
void afficherQuestion(const Question& question);
int poserQuestionEtCalculerPoints(const Question& question); // valide la reponse de l'utilisateur 
 

#endif // ----> empecehr les inclusions multiples