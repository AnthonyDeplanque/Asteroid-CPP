#include "Asteroide.h"
#include <random>;
#include"Vecteur.h"

using namespace std;
Asteroide::Asteroide(Jeu& p_jeu, Espace& p_espace, Asteroide* parent) :jeu{p_jeu},espace { p_espace }, ElementSpatial{ "Ressources/asteroide.png" }
{
	random_device generateur;
	uniform_real_distribution<float> distributionPosition = uniform_real_distribution<float>{ -150, 150 };
	uniform_real_distribution<float> distributionVitesse = uniform_real_distribution<float>{ 40, 60 };
	uniform_real_distribution<float> distributionAngle = uniform_real_distribution<float>{ 0, 360 };
	uniform_real_distribution<float> distributionVitesseAngulaire = uniform_real_distribution<float>{ 10, 30 };

	if (parent)
	{
		sprite.setScale(parent->sprite.getScale().x/1.4f, parent->sprite.getScale().y/1.4f);
		position = parent->position;

	}

	position = {
				distributionPosition(generateur),
				distributionPosition(generateur)
	};

	vitesse = Vecteur::creerDepuisAngle(
										distributionVitesse(generateur),
										distributionAngle(generateur)
	);

	vitesseAngulaire = distributionVitesseAngulaire(generateur);

	type = TypeElement::ASTEROIDE;
};

void Asteroide::reagirCollision(TypeElement typeAutre)
{
	if (typeAutre == TypeElement::MISSILE)
	{
		jeu.ajouterPoints(sprite.getScale().x*100);
		detruit = true;
		if (sprite.getScale().x > 0.1) {
		espace.ajouter(make_unique<Asteroide>(jeu, espace, this));
		espace.ajouter(make_unique<Asteroide>(jeu, espace, this));
		}
		espace.ajouter(make_unique<Explosion>(position));
	}
}

