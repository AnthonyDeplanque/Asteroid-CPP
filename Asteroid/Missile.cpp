#include "Missile.h"
#include "GestionnaireRessources.h"
#include <exception>

Missile::Missile(Coordonees const& p_position, float rotation) :ElementSpatial{ "Ressources/missile.png" }
{
	type = TypeElement::MISSILE;
	
	position = p_position;
	sprite.setRotation(rotation);
	vitesse = Vecteur::creerDepuisAngle(VITESSE, rotation);

	try {

	son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("Ressources/laser.wav"));
	son.play();
	}
	catch (std::exception const& exception)
	{
		throw exception;
	}

}
void Missile::reagirCollision(TypeElement typeAutre)
{
	if (typeAutre != TypeElement::VAISSEAU) {
		detruit = true;
	}
};