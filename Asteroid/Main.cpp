#include <SFML/Graphics.hpp>
#include <exception>

#include "Constantes.h"
#include "Espace.h"
#include "Jeu.h"

using namespace std;
using namespace sf;
int main()
{
	RenderWindow fenetre(VideoMode(LONGUEUR_FENETRE, LARGEUR_FENETRE), "Asteroïds");
	//fenetre.setFramerateLimit(60);
	//fenetre.setVerticalSyncEnabled(true);

	Coordonees::initialiserEspace(LONGUEUR_FENETRE, LARGEUR_FENETRE);

	auto espace = Espace();
	auto jeu = Jeu{ espace };


	while (fenetre.isOpen())
	{
		try 
		{
		Event evenement = Event{};

		while (fenetre.pollEvent(evenement))
		{
			if (evenement.type == Event::Closed)
			{
				fenetre.close();
			}
			if (evenement.type == Event::KeyPressed && !jeu.estEnCours())
			{
				jeu.demarrer();
			}

		}
		espace.actualiser();
		espace.gererCollisions();

		fenetre.clear();
		espace.afficher(fenetre);
		jeu.afficher(fenetre);
		fenetre.display();
		espace.nettoyer();

		}
		catch (std::exception const& exception)
		{
			jeu.initialiserException(exception);
		}
	}


	return EXIT_SUCCESS;
}

