#include <vector>
#include <iostream>
#include "Espace.h"

using namespace std;
Espace::Espace() {}

void Espace::ajouter(unique_ptr<ElementSpatial> element)
{
	aAjouter.push_back(move(element)); // move => methode pour déplacer un pointeur
}

void Espace::actualiser()
{
	auto tempsBoucle = chrono.restart().asSeconds();
	for (int i= 0u; i < elements.size(); ++i) {
		elements[i]->actualiser(tempsBoucle);
	}
}

void Espace::gererCollisions()
{
	for (int i = 0u; i < elements.size(); i++) {
		for (int j = 0u; j < elements.size(); j++) {

			if (i != j) {

				elements[i]->testerCollision(*elements[j]);
			}
		}
	}
}

void Espace::afficher(RenderWindow& fenetre) const
{
	for (auto& element : elements) { //vector<unique_ptr<ElementSpatial>>::const_iterator::value_type
		element->afficher(fenetre);
	}
}

void Espace::nettoyer()
{
	if (aVider)
	{
		elements.clear();
		aVider = false;
	}
	auto finTableau = remove_if(begin(elements), end(elements), ElementSpatial::estDetruit); // methode qui place à la fin du tableau tout les éléments à supprimer
	// finTableau => vector<unique_ptr<ElementSpatial>>::iterator
	// finTableau => 1er iterateur des éléments à supprimer
	
	elements.erase(finTableau, end(elements));
	for (auto& element : aAjouter) 
	{
		elements.push_back(move(element));
	}
	aAjouter.clear();
}

void Espace::vider() {
	aVider = true;
}