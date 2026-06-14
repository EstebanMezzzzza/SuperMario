#include "Plomero.hpp"

Plomero::Plomero()
{
    cargarTextura("assets/images/mario.png");

    setPosicion(140.f, 190.f);

    sprite->setScale({.15f, .15f});
}

Plomero::~Plomero()
{
}

void Plomero::actualizar(float dt)
{
    Jugador::actualizar(dt);
}