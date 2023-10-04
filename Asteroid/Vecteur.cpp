#define _USE_MATH_DEFINES

#include "Vecteur.h"
#include <cmath>
#include <iostream>

using namespace std;

void Vecteur::operator+=(Vecteur const& autre)
{
	x += autre.x;
	y += autre.y;
}
void Vecteur::operator-=(Vecteur const& autre)
{
	x -= autre.x;
	y -= autre.y;
}
Vecteur Vecteur::operator*(float coefficient) const
{
	return Vecteur{x* coefficient, y * coefficient };
}

Vecteur Vecteur::creerDepuisAngle(float taille, float angleEnDegree)
{
	// Les cosinus et sinus prennent des angles en radians, et nous recevons des angles en degrés
	// degré -> radians = angleEnDegré / 180 * pi
	return Vecteur
	{
		static_cast<float>(taille * cos(angleEnDegree / 180.f * M_PI)),
		static_cast<float>(taille * sin(angleEnDegree / 180.f * M_PI))
	};
}

void Vecteur::afficherVecteur(Vecteur vecteur) {
	cout << vecteur.x << ':' << vecteur.y << endl;
}
