#pragma once
#include "ElementSpatial.h"
#include <SFML/Audio.hpp>

class Missile :public ElementSpatial
{
public:
	Missile(Coordonees const& p_position, float rotation);
	virtual void reagirCollision(TypeElement typeAutre) override;

protected:

private:
	static constexpr float VITESSE{ 2000.f };

	sf::Sound son{};
};

