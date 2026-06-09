#include "Enemigo.hpp"

Enemigo::Enemigo()
{
    vida = 1;
}

Enemigo::~Enemigo()
{
}

void Enemigo::mover()
{
}

void Enemigo::actualizar(float dt)
{
    mover();

    if(sprite)
    {
        sprite->move(
            velocidad * dt
        );

        posicion =
            sprite->getPosition();
    }
}