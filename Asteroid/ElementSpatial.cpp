#include "ElementSpatial.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <string_view>
#include "./Vecteur.h"
#include "./Coordonees.h"
#include "./Constantes.h"
#include "GestionnaireRessources.h"

using namespace std;
using namespace sf;


ElementSpatial::ElementSpatial() = default;

ElementSpatial::ElementSpatial(string_view const& cheminTexture)
{
	sprite.setTexture(GestionnaireRessources<Texture>::getRessource(cheminTexture));
	sprite.setOrigin(
		sprite.getLocalBounds().width / 2,
		sprite.getLocalBounds().height / 2
	); // setter l'origine du sprite, pour son axe de rotation

	sprite.setPosition(position.getX(), position.getY());
}

void ElementSpatial::actualiser(float temps)
{
	mettreAJour(temps);
	auto deplacement = vitesse * temps;
	position += deplacement;
	sprite.setPosition(position.getX(), position.getY());
	sprite.rotate(vitesseAngulaire * temps);
}

void ElementSpatial::mettreAJour(float temps) { }

void ElementSpatial::afficher(RenderWindow& fenetre) const
{
	array<Vecteur, 9> affichages = {
									Vecteur{-1,-1}, Vecteur{-1, 0}, Vecteur{-1, 1},
									Vecteur{ 0,-1}, Vecteur{ 0, 0}, Vecteur{ 0, 1},
									Vecteur{ 1,-1}, Vecteur{ 1, 0}, Vecteur{ 1, 1},
	};
	for (Vecteur& affichage : affichages) {
		Transform transformation;
		transformation.translate(
			affichage.x * Coordonees::getLongueurEspace(),
			affichage.y * Coordonees::getHauteurEspace()
		);
		fenetre.draw(sprite, transformation);
	}


}

float ElementSpatial::getRayon() const
{
	return (sprite.getGlobalBounds().height / 2.4f);
}

void ElementSpatial::testerCollision(ElementSpatial& autre)
{
	auto distance = position.calculerDistance(autre.position);

	if (distance < getRayon() + autre.getRayon())
	{
		reagirCollision(autre.type);
	}
}


bool ElementSpatial::estDetruit(unique_ptr<ElementSpatial>& element) {
	return element->detruit;
}