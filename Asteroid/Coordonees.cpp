#include "Coordonees.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int Coordonees::longueurEspace{ 0 };
int Coordonees::hauteurEspace{ 0 };

// Constructeur factultatif mais ici on envoie un message d�erreur si une coordonn�e est cr��e avant l�initialisation de l�espace
Coordonees::Coordonees() {
	if (longueurEspace == 0 || hauteurEspace == 0) {
		cerr << "Attention : une coordonn�e a �t� cr��e avant l�initialisation de l�espace !" << endl;
	}
}

Coordonees::Coordonees(float px, float py) : x(px), y(py) { // assignation des param�tres juste apr�s les deux points
	//this->x = px;
	//this->y = py;
	recalculer();
}

// L�op�rateur += ajoute d�j� le vecteur en param�tre puis ajoute ou retire la taille de l�espace sur les composantes x,y si besoin
void Coordonees::operator+=(Vecteur const& vecteur) {
	x += vecteur.x;
	y += vecteur.y;
	recalculer();
}

void Coordonees::initialiserEspace(int longueur, int hauteur) {
	// on envoie un message d�erreur si l�espace �tait d�j� initialis�
	if (longueurEspace != 0 || hauteurEspace != 0) {
		cerr << "Attention : l�espace �tait d�j� initialis� !" << endl;
	}
	longueurEspace = longueur;
	hauteurEspace = hauteur;
}


void Coordonees::recalculer() {
	if (x > longueurEspace) {
		x = 0;
	}
	if (x < 0) {
		x = longueurEspace;
	}
	if (y > hauteurEspace) {
		y = 0;
	}
	if (y < 0) {
		y = hauteurEspace;
	}
}

float Coordonees::calculerDistance(Coordonees const& autre) const {

	//std::min(a,b) retourne la valeur la plus basse
	//std::abs(a) retourne la valeur absolue (toujours positive)
	//std::sqrt(a) retourne la racine carr�e

	auto delta = Vecteur{
		static_cast<float>(
			min(
			{
					abs(x - autre.x),
					abs(x - autre.x - longueurEspace),
					abs(x - autre.x + longueurEspace)
				}
		)),
		static_cast<float>(
			min(
			{
					abs(y - autre.y),
					abs(y - autre.y - hauteurEspace),
					abs(y - autre.y + hauteurEspace)
				}
		))
	};
	return sqrt(delta.x * delta.x + delta.y * delta.y);
}
