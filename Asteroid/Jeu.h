#pragma once
#include "Espace.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <exception>

class Jeu
{
public:
	Jeu(Espace& p_espace);
	void demarrer();
	void terminer();
	void afficher(sf::RenderWindow& fenetre) const;

	void ajouterPoints(int points);
	
	inline bool estEnCours() const { return enCours; };

	void initialiserException(std::exception const& exception);



protected:

private:
	Espace& espace;
	bool enCours{ false };
	sf::Sprite spriteAccueil{};

	void setSpriteAccueilSize();
	void rafraichirTexte();
	void rafraichirMeilleurScore();

	int score{0};
	sf::Text texteScore{};
	sf::Font police{};

	int meilleurScore{ 0 };
	sf::Text texteMeilleurScore{};


	std::unique_ptr<sf::Text> texteException;
};

