#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;

//-------------------------------------------EXERCICE 2----------------------------------------

int main() {
    StockageObjet2D liste;  
    Rectangle* rectangle = new Rectangle(7, 29);             // Crée un rectangle
    liste.AtHead(rectangle);                                 // Ajoute le rectangle à la liste
    Cube* cube = new Cube(17);                               // Crée un cube
    liste.AtTail(cube);                                      // Ajoute le cube à la liste
   
    Objet2D* courant = nullptr;
    if (liste.getHead() != nullptr) {
        courant = liste.getHead();
    }                                                        // Crée une boucle qui s'exécute tant qu'il y a des objets dans la liste
    while (courant != nullptr) {
        courant->afficheInfo();                              // Affiche les informations de l'objet courant
        courant = courant->getSuivant();                     // Passe à l'objet suivant
    }
    return 0;
}
