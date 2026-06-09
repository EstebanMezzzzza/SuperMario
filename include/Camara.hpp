#pragma once

#include <SFML/Graphics.hpp>

class Jugador;

class Camara
{
private:

    sf::View vista;

public:

    Camara();

    void seguir(
        const Jugador& jugador
    );

    sf::View& obtenerVista();
};
