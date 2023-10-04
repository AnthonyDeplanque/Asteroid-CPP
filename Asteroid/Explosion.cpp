#include "Explosion.h"
#include "GestionnaireRessources.h"

Explosion::Explosion(Coordonees const& p_position) : ElementSpatial{ "Ressources/explosion.png" }
{
	type = TypeElement::AUTRE;
	position = p_position;

	son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("Ressources/explosion.wav"));
	son.play();
}

void Explosion::mettreAJour(float temps)
{
	age += (temps);
	if (age < DUREE_VIE) {
		float scale = age / DUREE_VIE;
		sprite.setScale(scale, scale);
	}
	else {
		sprite.setScale(0, 0);
		if (son.getStatus() == sf::SoundSource::Stopped) {
		detruit = true;
		}
	}
}

void Explosion::reagirCollision(TypeElement typeAutre)
{

}