#include "Plomero.hpp"

Plomero::Plomero()
{
    cargarTextura("assets/images/mario.png");

    setPosicion(100.f, 100.f);

    sprite->setScale({.15f, .15f});
}

Plomero::~Plomero()
{
}

void Plomero::actualizar(float dt)
{
    Jugador::actualizar(dt);
}