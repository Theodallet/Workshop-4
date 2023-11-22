#include "pch.h"
#include <iostream>

using namespace std;

Objet2D::Objet2D(void) {
	this->dim1 = 0;
	this->dim2 = 0;
}

Objet2D::Objet2D(int tdim1, int tdim2) {
	this->dim1 = tdim1;
	this->dim2 = tdim2;
}

int Objet2D::getPerimetre() {
	return (this->dim1 + this->dim2) * 2;
}

int Objet2D::getAire() {
	return this->dim1 * this->dim2;
}

void Objet2D::afficheInfo() {
	cout << "Dimensions : " << dim1 << ", " << dim2 << endl;
}

Objet2D* Objet2D::getSuivant(){
	return this-> Suivant;
}

void Objet2D::setSuivant(Objet2D* Suivant){
	this->Suivant = Suivant;
}

//------------------------------------------------------------------------------

Rectangle::Rectangle(void) :Objet2D() {
}

Rectangle::Rectangle(int tdim1, int tdim2) : Objet2D(tdim1, tdim2) {
}

int Rectangle::getLongueur() {
	return this->dim1;
}

int Rectangle::getLargueur() {
	return this->dim2;
}

int Rectangle::getPerimetre() {
	return (this->dim1 + this->dim2) * 2;
}

int Rectangle::getAire() {
	return this->dim1 * this->dim2;
}

void Rectangle::afficheInfo() {
	cout << "Rectangle" << endl;
	cout << "Dimensions : " << dim1 << ", " << dim2 << endl;
	cout << "Longueur : " << getLongueur() << endl;
	cout << "Largeur : " << getLargueur() << endl;
	cout << "Perimètre : " << getPerimetre() << endl;
	cout << "Aire : " << getAire() <<endl;
}

//------------------------------------------------------------------------------

Cube::Cube(void) :Rectangle() {
}

Cube::Cube(int tcote) : Rectangle(tcote, tcote) {
}

int Cube::getCote() {
	return this->dim1;
}

void Cube::afficheInfo() {
	cout << "Carre" << endl;
	cout << "Dimensions : " << dim1 << endl;
	cout << "Longueur : " << getCote() << endl;
	cout << "Perimètre : " << getPerimetre() << endl;
	cout << "Aire : " << getAire() << endl;
}

//------------------------------------------------------------------------------

StockageObjet2D::StockageObjet2D(){
	this->Head = nullptr;				//Initialisation en mettant qu'il n'y a pas de valeur
	this->Tail = nullptr;
}

Objet2D* StockageObjet2D::getHead()
{
	return this -> Head;
}

int StockageObjet2D::taille() {
											   // Si la liste est vide, la taille est 0
		if (Head == nullptr) {
		return 0;
	}

												// Sinon, la taille est égale au nombre d'éléments
	int taille = 1;
	Objet2D* courant = Head;
	while (courant->getSuivant() != nullptr) {
		taille++;
		courant = courant->getSuivant();
	}

	return taille;
}
void StockageObjet2D::AtHead(Objet2D* Objet) {
	Objet2D* nouveau = Objet;
		if (Head == nullptr) {  // Si il la head na pas de valeur alors on met la nouvelle 
			Head = nouveau;
			Tail = nouveau;
		}
		else {					
			Head->setSuivant(nouveau);	// Sinon on deplace la valeur de la head au suivant
			Head = nouveau;				// Puis la head est égale à la nouvelle valeur
		}
}

void StockageObjet2D::AtTail(Objet2D* Objet){
	Objet2D* nouveau = Objet;
	if (Head == nullptr) {		 // Si il la head na pas de valeur alors on met la nouvelle 
		Head = nouveau;
		Tail = nouveau;
	}
	else {
		Tail->setSuivant(nouveau);		// Sinon on deplace la valeur de la Tail au suivant
		Tail = nouveau;					// Puis la Tail est égale à la nouvelle valeur
	}
}

void StockageObjet2D::AtIndex(Objet2D* Objet, int index){
	if (index < 0 || index >= taille()) {			// On vérifie que la valeur est bien dans notre interval c'est-à-dire que ce soit entre 0 et le nombre d'élément de la liste
		return;
	}

	Objet2D* nouveau = Objet;
	
	if (index == 0) {							// Si l'index est à 0 alors c'est qu'on met la valeur sur la head
		AtHead(nouveau);
		return;
	}

	if (index == taille()) {					// Si l'index est au maximum alors c'est qu'on met la valeur sur la tail
		AtTail(nouveau);
		return;
	}

	Objet2D* precedent = Head;					// L'objet est ajouté à l'index demander 

	for (int i = 0; i < index - 1; i++) {
		precedent = precedent->getSuivant();
	}													
	nouveau->setSuivant(precedent->getSuivant());
	precedent->setSuivant(nouveau);
}

void StockageObjet2D::SupHead() {
												// Si la liste est vide, ne fait rien
	if (Head == nullptr) {
		return;
	}
												// Si la liste ne contient qu'un élément, la tête et la queue sont mises à nullptr
	if (Head == Tail) {
		Head = nullptr;
		Tail = nullptr;
	}
	else {
												// La tête devient le deuxième élément
		Head = Head->getSuivant();
	}
}

void StockageObjet2D::SupTail() {
												// Si la liste est vide, ne fait rien
	if (Head == nullptr) {
		return;
	}
												// Si la liste ne contient qu'un élément, la tête et la queue sont mises à nullptr
	if (Head == Tail) {
		Head = nullptr;
		Tail = nullptr;
	}
	else {
												// On parcourt la liste jusqu'au deuxième dernier élément
		Objet2D* precedent = Head;
		while (precedent->getSuivant()->getSuivant() != nullptr) {
			precedent = precedent->getSuivant();
		}
												// Le deuxième dernier élément devient la nouvelle queue
		Tail = precedent;
												// On supprime le dernier élément
		precedent->setSuivant(nullptr);
	}
}

void StockageObjet2D::SupIndex(int index) {
												// Si l'index est négatif ou supérieur à la taille de la liste, ne fait rien
	if (index < 0 || index >= taille()) {
		return;
	}
												// Si l'index est 0, on supprime l'élément en tête
	if (index == 0) {
		SupHead();
		return;
	}
												// Si l'index est la taille de la liste, on supprime l'élément en queue
	if (index == taille() - 1) {
		SupTail();
		return;         
	}
												// On parcourt la liste jusqu'à l'élément à supprimer
	Objet2D* precedent = Head;
	for (int i = 0; i < index - 1; i++) {
		precedent = precedent->getSuivant();
	}
	precedent->setSuivant(precedent->getSuivant()->getSuivant());
}
