#include"pch.h"
class Objet2D {
private:
	Objet2D* Suivant;
protected:
	int dim1;
	int dim2;
public:
	Objet2D(void);
	Objet2D(int tdim1, int tdim2);
	virtual int getPerimetre() = 0;
	virtual int getAire() = 0;
	virtual void afficheInfo() = 0;
	Objet2D* getSuivant();
	void setSuivant(Objet2D* Suivant);

};

class Rectangle : public Objet2D {
public:
	Rectangle(void);
	Rectangle(int tdim1, int tdim2);
	int getLongueur();
	int getLargueur();
	virtual int getPerimetre();
	virtual int getAire();
	virtual void afficheInfo();
};

class Cube :public Rectangle {
public:
	Cube(void);
	Cube(int tcote);
	int getCote();
	virtual void afficheInfo() override;
};

class StockageObjet2D {
protected:
	Objet2D* Head;
	Objet2D* Tail;
public:
	StockageObjet2D();
	Objet2D* getHead();
	int taille();
	void AtHead(Objet2D* Objet);
	void AtTail(Objet2D* Objet);
	void AtIndex(Objet2D* Objet, int index);
	void SupHead();
	void SupTail();
	void SupIndex(int index);

};