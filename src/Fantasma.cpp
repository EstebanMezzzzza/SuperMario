#include "Fantasma.hpp"

Fantasma::Fantasma()
{
}

Fantasma::~Fantasma()
{
}

void Fantasma::mover()
{
}

void Fantasma::actualizar(float dt)
{
    sprite->move(velocidad * dt);

    posicion = sprite->getPosition();
}
