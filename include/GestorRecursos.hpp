#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

class GestorRecursos
{
private:

    std::unordered_map<
        std::string,
        sf::Texture
    > texturas;

public:

    GestorRecursos();

    sf::Texture& obtenerTextura(
        const std::string& archivo
    );
};
