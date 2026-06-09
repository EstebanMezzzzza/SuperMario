#include "Pez.hpp"

Pez::Pez()
{
}

Pez::~Pez()
{
}

void Pez::mover()
{
}

void Pez::actualizar(float dt)
{
    sprite->move(velocidad * dt);

    posicion = sprite->getPosition();
}
