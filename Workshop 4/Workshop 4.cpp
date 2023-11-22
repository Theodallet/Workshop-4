#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;

//-------------------------------------------EXERCICE 1----------------------------------------
/*
int Exercice1_1();
int Exercice1_3();

int main() {
    cout << Exercice1_1() << endl ;
    cout << Exercice1_3() << endl ;
}

int Exercice1_1() {
   
    int tableau[3];                      // D�claration du tableau

                                         // Remplissage du tableau
    tableau[0] = 1;
    tableau[1] = 2;
    tableau[2] = 3;

                                         // Affichage du contenu du tableau
    for (int i = 0; i < 3; i++) {
        cout << tableau[i] << endl;
    }

    return 0;
}

int Exercice1_3() {
                                        // D�claration du tableau
    int* tableau = new int[3];
                                        // Remplissage du tableau
    for (int i = 0; i < 3; i++) {
        cout << "Entrez une valeur : ";
        cin >> tableau[i];
    }
                                         // Affichage du contenu du tableau
    for (int i = 0; i < 3; i++) {
        cout << tableau[i] << endl;
    }
                                         // Lib�ration de la m�moire
    delete[] tableau;

    return 0;
}
*/

//-------------------------------------------EXERCICE 2----------------------------------------

int main() {
    StockageObjet2D liste;  
    Rectangle* rectangle = new Rectangle(7, 29);             // Cr�e un rectangle
    liste.AtHead(rectangle);                                 // Ajoute le rectangle � la liste
    Cube* cube = new Cube(17);                               // Cr�e un cube
    liste.AtTail(cube);                                      // Ajoute le cube � la liste
   
    Objet2D* courant = nullptr;
    if (liste.getHead() != nullptr) {
        courant = liste.getHead();
    }                                                        // Cr�e une boucle qui s'ex�cute tant qu'il y a des objets dans la liste
    while (courant != nullptr) {
        courant->afficheInfo();                              // Affiche les informations de l'objet courant
        courant = courant->getSuivant();                     // Passe � l'objet suivant
    }
    return 0;
}