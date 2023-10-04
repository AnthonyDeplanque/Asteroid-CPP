#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "ElementSpatial.h"

using namespace std;

class Espace
{
public:
	Espace();
	void ajouter(unique_ptr<ElementSpatial> element);
	void actualiser();
	void gererCollisions();
	void afficher(RenderWindow& fenetre) const;
	void nettoyer();
	void vider();

	inline bool estVide() const { return elements.empty(); }


protected:
private:
	vector<unique_ptr<ElementSpatial>> elements {};
	vector<unique_ptr<ElementSpatial>> aAjouter{};
	bool aVider{ false };
	Clock chrono = Clock{};
};

