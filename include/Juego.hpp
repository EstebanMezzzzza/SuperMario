#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../entidades/Plomero.hpp"
#include "../mundo/Nivel.hpp"

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

    EstadoJuego estado;

    std::unique_ptr<Plomero> jugador;

    std::unique_ptr<Nivel> nivelActual;

public:

    Juego();

    void ejecutar();

private:

    void procesarEventos();

    void actualizar(float dt);

    void renderizar();
};