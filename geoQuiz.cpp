/*
Autheur: David Ndimina
Membre de l'equipe : David Ndimina
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

// code du prof 
Question* chargerQuestions(int& nombreQuestions)
{
    random_device rd;
    mt19937 generateur(rd());

    Question* questions = nullptr;

    try
    {
        ifstream fichier("quiz.txt");
        fichier.exceptions(ios::failbit | ios::badbit);

        string nbQuestionsString;
        getline(fichier, nbQuestionsString);
        nombreQuestions = stoi(nbQuestionsString);

        questions = new Question[nombreQuestions];

        for (int x = 0; x < nombreQuestions; x++)
        {
            string ligne;
            getline(fichier, ligne);
            chargerQuestion(questions[x], ligne);
        }

        shuffle(questions, questions + nombreQuestions, generateur);
    }
    catch (const exception& e)
    {
        cerr << "EXCEPTION : " << e.what() << endl;
    }

    return questions;
}
void chargerQuestion(Question& question, string lecture)
{
    vector<string> elements;
    stringstream flux(lecture);
    string item;

    while (getline(flux, item, ';'))
        elements.push_back(item);

    question.pays = elements[0];

    for (int noQ = 0; noQ < 5; noQ++)
        question.capitales[noQ] = elements[noQ + 1];

    question.reponse = stoi(elements[6]) - 1; 
}// fin du code du prof 

// gestion des questions
Question& chargerQuestionDepuisTableau(Question* questions, int index)
{
    return questions[index];
}

void afficherQuestion(const Question& question)
{
    cout << "\nPays : " << question.pays << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << (i + 1) << ") " << question.capitales[i] << endl;
    }
}

// choix et validation de la reponse de l'utilisateur
int poserQuestionEtCalculerPoints(const Question& question)
{
    int choix = 0;
    cout << "Votre choix (1 a 5) : ";
    cin >> choix;

    int indexChoisi = choix - 1;

    if (indexChoisi == question.reponse)
    {
        cout << "Bonne reponse : +2 points" << endl;
        return 2;
    }
    else
    {
        cout << "Mauvaise reponse : -1 point" << endl;
        cout << "Bonne reponse : " << question.capitales[question.reponse] << endl;
        return -1;
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
        return;
    }
    int nbQuestionsPartie = 5; //renvoie le nombre de questions (5)
    if (nombreQuestions < nbQuestionsPartie)
        nbQuestionsPartie = nombreQuestions;

    int total = 0; // compteur du score total 

    for (int i = 0; i < nbQuestionsPartie; i++)
    {
        Question& q = chargerQuestionDepuisTableau(questions, i);
        afficherQuestion(q);
        total += poserQuestionEtCalculerPoints(q);
        cout << "Total actuel : " << total << endl; // compter les points 
    }

    cout << "\n=== Fin de la partie ===" << endl;
    cout << "Score de la partie : " << total << endl;

    if (total > profil_utilisateur.score)
    {
        cout << "Bravo ! Nouveau record !" << endl;
        cout << "Ancien record { " << profil_utilisateur.score << " }" << endl;
        cout << "Nouveau record {" << total << "}" << endl;
        profil_utilisateur.score = total;
    }
    else
    {
        cout << "Record actuel { " << profil_utilisateur.score << " }" << endl;
        cout << "Vous n'avez pas battu votre record." << endl;
    }

    delete[] questions;
}
