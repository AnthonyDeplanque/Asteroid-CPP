#pragma once
#include "ElementSpatial.h"
#include <SFML/Audio.hpp>

class Explosion : public ElementSpatial
{
public:
	Explosion(Coordonees const& p_position);
	virtual void reagirCollision(TypeElement typeAutre) override;

protected:
	virtual void mettreAJour(float temps) override;

private :
	float age{};
	static float constexpr DUREE_VIE = 0.1f;
	sf::Sound son;

};


