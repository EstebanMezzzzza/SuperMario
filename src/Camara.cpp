#include "Camara.hpp"
#include "Jugador.hpp"

Camara::Camara()
{
    vista.setSize(
        sf::Vector2f(
            1280.f,
            720.f
        )
    );
}

void Camara::seguir(
    const Jugador& jugador
)
{
    vista.setCenter(
        jugador.getPosicion()
    );
}

sf::View&
Camara::obtenerVista()
{
    return vista;
}
