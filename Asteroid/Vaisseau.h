#pragma once
#include <SFML/Graphics.hpp>

#include "Vecteur.h"
#include "Coordonees.h"
#include "ElementSpatial.h"
#include "Explosion.h"
#include "Espace.h"
#include "Jeu.h"


using namespace sf;
class Vaisseau : public ElementSpatial
{
public:
	explicit Vaisseau(Jeu& p_jeu, Espace& p_espace, Color const& couleur);
	~Vaisseau();

	virtual void reagirCollision(TypeElement typeAutre) override;

protected:
	virtual void mettreAJour(float temps) override;

private:
	static constexpr float ACCELERATION{ 7000.f }; // constexpr = pas modifiable et défini à l'initialisation
	static constexpr float COEFF_FROTTEMENT{ 2.f };
	static constexpr float VITESSE_ANGULAIRE{ 80.f };

	bool accelerationEnCours{ false };
	bool tourneAGauche{ false };
	bool tourneADroite{ false };

	Jeu& jeu;
	Espace& espace;
	Clock dernierTir{};

	void actualiserEtat();
	void handleRotation(float temps);
	void handleAcceleration(float temps);
};

