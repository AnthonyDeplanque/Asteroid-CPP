
#include "Jeu.h"

#include <memory>
#include <SFML/Graphics.hpp>

#include <string_view>

#include "ElementSpatial.h"
#include "Vaisseau.h"
#include "Asteroide.h"
#include "GestionnaireRessources.h"
#include "Constantes.h"

#include "font.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>


using namespace std::string_literals;

const sf::Color COULEUR_VAISSEAU = (sf::Color(128, 255, 128));

Jeu::Jeu(Espace& p_espace) : espace{ p_espace }
{
	if (!police.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size))
		throw std::runtime_error{ "No font" };

	texteScore.setFont(police);
	texteScore.move(0, 30);
	texteMeilleurScore.setFont(police);

	auto fichier = std::ifstream{ "meilleurScore.txt" };
	if (fichier.is_open())
	{
	fichier >> meilleurScore;
	}
	
	fichier.close();

	rafraichirMeilleurScore();

	try
	{
		spriteAccueil.setTexture(GestionnaireRessources<sf::Texture>::getRessource("Ressources/accueil.png"));
		setSpriteAccueilSize();
	}
	catch (std::exception const& exception)
	{
		initialiserException(exception);
	}
}

void Jeu::setSpriteAccueilSize() {
	float sizeX = spriteAccueil.getGlobalBounds().getSize().x;
	float sizeY = spriteAccueil.getGlobalBounds().getSize().y;
	float multiplierX = LONGUEUR_FENETRE / sizeX;
	float multiplierY = LARGEUR_FENETRE / sizeY;

	spriteAccueil.setScale(multiplierX, multiplierY);
}

void Jeu::demarrer()
{
	score = 0;
	rafraichirTexte();
	enCours = true;
	score = 0;
	espace.ajouter(make_unique<Vaisseau>(*this, espace, COULEUR_VAISSEAU));
	espace.ajouter(make_unique<Asteroide>(*this, espace));
	espace.ajouter(make_unique<Asteroide>(*this, espace));
	espace.ajouter(make_unique<Asteroide>(*this, espace));
}
void Jeu::terminer()
{
	enCours = false;
	if (score > meilleurScore)
	{
		meilleurScore = score;
		rafraichirMeilleurScore();
		auto fichier = std::ofstream{ "meilleurScore.txt" };
		if (fichier.is_open())
		{
			fichier << meilleurScore;
		}
		else 
		{
			throw std::runtime_error{ "impossible d'ouvrir le fichier meilleurScore.txt" };
		}
		fichier.close();
	}
	espace.vider();
}

void Jeu::afficher(sf::RenderWindow& fenetre) const {
	if (texteException)
	{
		fenetre.draw(*texteException);
	}
	else
	{
		if (!enCours && espace.estVide())
		{
			fenetre.draw(spriteAccueil);
		}
		else
		{
			fenetre.draw(texteScore);
		}
		fenetre.draw(texteMeilleurScore);
	}

}

void Jeu::initialiserException(std::exception const& exception)
{
	texteException = std::make_unique<sf::Text>();
	texteException->setFont(police);
	texteException->setString(exception.what());
	texteException->setFillColor(sf::Color::Red);
}

void Jeu::ajouterPoints(int points)
{
	score += points;
	rafraichirTexte();
}

void Jeu::rafraichirTexte()
{
	texteScore.setString("Score : "s + std::to_string(score));
}

void Jeu::rafraichirMeilleurScore()
{
	texteMeilleurScore.setString("Meilleur score : "s + std::to_string(meilleurScore));
}