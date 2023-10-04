#include "GestionnaireRessources.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

template<>
unordered_map<string_view, Texture> GestionnaireRessources<Texture>::ressources{};
template<>
unordered_map<string_view, SoundBuffer> GestionnaireRessources<SoundBuffer>::ressources{};

