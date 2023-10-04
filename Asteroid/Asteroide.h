#pragma once
#include "ElementSpatial.h"
#include"Espace.h"
#include "Explosion.h"
#include "Jeu.h"

class Asteroide : public ElementSpatial
{
public:
	explicit Asteroide(Jeu& p_jeu, Espace& p_espace, Asteroide* parent = nullptr);
	virtual void reagirCollision(TypeElement typeAutre) override;
	Espace& espace;
	Jeu& jeu;

};


