#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "./Vecteur.h"
#include "./Coordonees.h"
#include "./Constantes.h"
#include <string_view>

using namespace sf;
using namespace std;

enum class TypeElement {VAISSEAU, ASTEROIDE, MISSILE, AUTRE};

class ElementSpatial
{
public:
	explicit ElementSpatial();
	virtual ~ElementSpatial() = default;

	explicit ElementSpatial(string_view const& cheminTexture);
	ElementSpatial(ElementSpatial const& autre) = delete;
	void operator=(ElementSpatial const& autre) = delete;

	void actualiser(float temps);

	virtual void afficher(RenderWindow& fenetre) const;

	float getRayon() const;
	void testerCollision(ElementSpatial& autre);
	virtual void reagirCollision(TypeElement typeAutre)= 0;

	static bool estDetruit(unique_ptr<ElementSpatial>& element);

protected:
	virtual void mettreAJour(float temps);

	Texture texture{};
	Sprite sprite{};
	Vecteur vitesse{ 0.f,0.f };
	Coordonees position = Coordonees();

	TypeElement type = TypeElement::AUTRE;

	float vitesseAngulaire{};

	bool detruit{ false };

};

