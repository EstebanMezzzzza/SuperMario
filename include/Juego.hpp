#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "Plomero.hpp"
#include "Nivel.hpp"

enum class EstadoJuego
{
    MENU,
    JUGANDO,
    PAUSA,
    GAME_OVER,
    VICTORIA
};

class Juego
{
private:

    sf::RenderWindow ventana;

    sf::Font fuente;

    std::unique_ptr<sf::Text>
        textoVidas;

    std::unique_ptr<sf::Text>
        textoPuntos;

    EstadoJuego estado;

    sf::View camara;

    std::unique_ptr<Plomero> jugador;

    std::unique_ptr<Nivel> nivelActual;

public:

    Juego();

    void ejecutar();

private:

    void procesarEventos();

    void actualizar(
        float dt
    );

    void renderizar();
};