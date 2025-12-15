=============================================================================================================================
Projet assisté : 
Cours : Element de programmation 
langage : c++ 
Par : David Verrhy Durcin NDIMINA(NDID25010407), Mamadou Siradiou Baldé (BALM16089700)
===============================================================================================================================
# comment excuter le projet ? 

la commande suivante permet d'excuter tous les fichier.cpp du documemt. 
g++ projet.cpp geoExploration.cpp geoQuiz.cpp -o projet 
 ./ projet ===> excute le fichier.cpp du main 


# Ce fichier README.txt, est la sommation de des explications de tout ce que j'ai fait et pourquoi je l'ai fait comme ça dans mon code.
# etape 1: Le menu

Ce qu'il faut faire, c'est de cree une fonction menu qui renvoie le choix de l'utilisateur comprenant des options. 

- j'ai utilise le struct{}  pour organiser la sortie du menu en creeant un tableau qui gere en meme temps, le char qui represente 
une lettre qui elle est liée a une option du menu qui sera gere dans le switch case. 
- J'ai cree la fonction qui retouren le choix de l'utilisateur avec char afficherMenu(). cette fonction prend en compte en parametre 
la selection du menu et la taille de celui ci, en gros les arguments du tableau qui a ete cree avec le struct{}. Cette fonction est
ensuite importée dans la boucle do while. 
- boucle do..while(), cette boucle permet de retourner le menu a chaque fois que l'utilisateur fait un choix. il prend aussi le choix de ce dernier
grace a la fonction qui a ete cree tantot pour retouner le choix de l'utilisateur. Cette boucle ne se ferme que lorsque le choix de l'utilisateur 
est 'q'. 
- les switch...case. chaque case dans le switch renverra une sortie en fonction du choix de l'utilisateur. 

Voir les captures d'ecrans pour la demonstration de l'etape 1. 

# etape 2: Les geoInformations 

Dans cette seconde etape, ce qu'il faut faire, c'est de creer un fichier header et un fichier .cpp contenant les instruction. 

- fichier header(geoExploration.h): 
Pour construire le fichier header, j'ai utilise trois fonction convertisseur pour matcher avec les trois cas de cout du fichier main du prof.

*notion de surchage: 
- cas où la fonction prends deux argument, le montant a convertir et la devise de conversion soit usd ou euro.
===> convertisseur(double montant, string devise) 
- cas où la fonction prend un seul argument, le montant mais le devise n'est pas specifié. La devise par defaut est donc la devise de notre choix,
j'ai choisi le franc suisse(chf)
===> convertisseur (double montant)
- cas où la fonction ne prend aucun argument, ni montant ni devise. Pour traiter, je vais devoir mettre en place un montant par defaut et choisir
une devise par defaut. Pour ce faire, je choisis le montant par defaut sera 150 CAD et la devise par defaut sera le franc suisse (chf)
===> convertisseur(), les arguments seront (150, "chf").
- Le cas de devise invalide, ce cas renvoie un message d'invalidation pour l'instant(voir etape 5).

- fichier d'instructions (geoExploration.cpp):
Dans ce fichier, il s'agit de donner des instructions a nos fonctions creees dans le fichier header.Ces instructions sont des operations
à retourner dans chacun des cas.

# etape 3: les structures d'informations 
Dans cette etape 3, nous devons creer des structure d'informations. 

- creation du fichier header(geoQuiz.h):
Ce fichier doit contenir les structures de profil et question. Pour realiser ça, je vais utiliser la meme technologie struct{} comme je 
l'ai fait dans le menu pour gerer l'affiche du menu. 
 - Profil: doit contenir deux arguments si je peux les appeler comme ça. le premier sera un sting qui contiendra le nom, le second un int 
 qui contiendra la valeur du score. 
 - Question: de meme, sera defini par un sting qui renvera la valeur ou nom d'un pays, un tableau de capitale en format (string [5]) 
 et une reponse int.

- creation du fichier d'instruction (geoQuiz.cpp):
dans le ce fichier d'instructions, pour l'instant juste l'entete est emportée. aucune instrcution n'a ete demandé.

- fonction introduction dans le main:
la fonction introduction dans le fichier Projet.cpp a ete creee grace a void introduction(profil &profil_utilisateur).
&profil_utilisateur fait une reference et me permet de copier les informations de l'utilisateur et me laisse une liberte de la changer.
vu que le nom de l'utilisateur est appeler en fonction de celui ci. De meme pour son score qui lui, change au fil du temps. Donc faire une reference
me paraissait une solution adequate.

# etape 4: La geoExploration 

Le processus de resolution de cett etape se separe en deux partie: modifier les fichier geoExploration.h et geoExploration.cpp afin
d'y ajouter de nouvelle fonction ensuite importer la fonction geoExploration dans la case 'e' de la switch.
 - etape 1: la fonction void geoExploration(profil &profil_utilisateur). J'ai choisi cette structure parce que ça me permettait de reutiliser 
 les arguments, notatement le nom de l'utilisateur present dans la structure profil qui à ete utiliser pour la fonction introduction. C'est pour 
 cela que j'ai inclue le header <<geoQuiz.h>> vu que c'est lui qui a ces informations.
 La fonction void voyager (string *voyages, int etapes, int position). Cette structure de fonction prend en compte le pointeur de types
 string qui permet de creer un tableau de taille dynmaique ou sera stocker les destinations de notre utilisateur. int etape represente 
 le nombre d'etapes des deplacements, entre autres, le nombres de case qu'aura le tableau a taille dynamique cree avec le pointeur. int position
 represente tout simplement la position de la case dans le tableau dynamique. La variable position nous permet de nous deplacer dans le tableau 
 jusqu'a atteindre la valeur des etapes. la fonction voyager prendra fin quand position == etape.
- etape 2: importer geoExploration(Profil); dans main. Pourquoi (Profil)? c'est l'argument que j'ai donne a la fonction 
introduction afin de me simplifier la lecture de mon code 

# etape 5: gestion des problemes 

- Dans geoExploration,dans la fonction convertisseur, nous avons implanter deux gestions de problemes conforme a ce que nous avons appris en classe.
* try, le try a ete ajoute afin de prevenir toute eventuealité de mauvaise devise. a la place de exception, on a utilise runtime_error.
ensuite le try catch a ete fait dans le main(). Protection du bloc a excuté encadre dans le try et l'erreur est rattrape par le bloc catch{}

- Dans la fonction voyager, on a ajouter une gestion de problemes avec une porte logique OU(||) qui empeche d'avoir un nombre d'etape inferieur a 1 ou superieur a 9

# etape 6,7: ensemble 
Dans ces etsps liees, on doit maintenant rendre interactive la case: 'z'. 

Comme pour l'etape 'e', J'utilise ma variable Profil qui est liee a ma structure profil. ==> geoQuiz(Progil);
Ensuite, on a copié et commenter le code que le prof a propose pour l'etape 7. 

# Etape 8: gestion des questions 
realiser avec deux fonctions bien distincte mais qui se completent et qui permettent l'excution de cette partie 
Question& chargerQuestionDepuisTableau(Question* questions, int index); // retourne la qestion charger a une certaine index de notre tableau 
void afficherQuestion(const Question& question) // sortir la question avec les reponses (pays et capitales) 
Aussi, boucle on a utilise une boucle for pour montrer a l'utilisateur les differents choix de reponse qu'il a. 

# etape 9 : choix et validation de la réponse de l'utilisateur
int poserQuestionEtCalculerPoints(const Question& question) // fonction qui permet de poser la question et de calculer les points 
on a utilise une fonction int() afin de pouvoir renvoyer la bonne reponse, attribue ou retirer le point a l'utilisateur. 
Une structure conditionnelle a ete utilisee. 

# Lien github: 
Je sais qu'il n y a pas de point pour le dépôt github, mais on s'est dit que peut etre, par le grand pure des hasard en avoir. 
Notre github est assez structuré. 
https://github.com/dduricn/geoprojet.git 

