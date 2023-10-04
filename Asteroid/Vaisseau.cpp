#include "Vaisseau.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string_view>
#include "./Vecteur.h"
#include "./Coordonees.h"
#include "./Constantes.h"
#include "./Missile.h"

#pragma region CONSTRUCTORS / DESTRUCTORS
Vaisseau::Vaisseau(Jeu& p_jeu, Espace& p_espace,Color const& couleur) :
	ElementSpatial{ "Ressources/vaisseau.png" },
	jeu{ p_jeu },
	espace{ p_espace }
{
	sprite.setColor(couleur);
	type = TypeElement::VAISSEAU;
}
Vaisseau::~Vaisseau() { cout << "Destruction du vaisseau" << endl; }
#pragma endregion

void Vaisseau::actualiserEtat()
{
	accelerationEnCours = Keyboard::isKeyPressed(Keyboard::Up);
	tourneAGauche = Keyboard::isKeyPressed(Keyboard::Left);
	tourneADroite = Keyboard::isKeyPressed(Keyboard::Right);
	if (
		Keyboard::isKeyPressed(Keyboard::Space)
		&& dernierTir.getElapsedTime().asSeconds() > 0.1f)
	{
		espace.ajouter(make_unique<Missile>(position, sprite.getRotation()));
		dernierTir.restart();
	}
}

void Vaisseau::mettreAJour(float temps)
{
	actualiserEtat();

	if (!detruit) {
		handleAcceleration(temps);
		handleRotation(temps);
	}
}

void Vaisseau::handleAcceleration(float temps)
{
	if (accelerationEnCours)
	{
		vitesse += Vecteur::creerDepuisAngle(ACCELERATION * temps, sprite.getRotation());
	}
	vitesse -= vitesse * COEFF_FROTTEMENT * temps; // *2.f = coeff de frottement dans l'air
}

void Vaisseau::handleRotation(float temps)
{
	if (tourneAGauche)
		vitesseAngulaire = -VITESSE_ANGULAIRE;

	else if (tourneADroite)
		vitesseAngulaire = VITESSE_ANGULAIRE;

	else
		vitesseAngulaire = 0;

}

void Vaisseau::reagirCollision(TypeElement typeAutre) {
	if (typeAutre == TypeElement::ASTEROIDE) {
		detruit = true;
		jeu.terminer();
		espace.ajouter(make_unique<Explosion>(position));
	}
}


