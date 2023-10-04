#pragma once
#include "ExceptionRessourceIntrouvable.h"

#include <iostream>
#include <string_view>
#include <unordered_map>

using namespace std;

template <typename T>
class GestionnaireRessources
{
public:
	GestionnaireRessources() = delete;
	static T const& getRessource(string_view const& chemin)
	{
		auto resultat = ressources.find(chemin);
		if (resultat == end(ressources))
		{
			if (!ressources[chemin].loadFromFile(chemin.data()))
			{
				throw ExceptionRessourceIntrouvable{ chemin };
			}
			return ressources[chemin];
		}
		return resultat->second;
	}

protected:

private:
	static unordered_map<string_view, T> ressources;
};

