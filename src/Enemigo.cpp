#include "Enemigo.hpp"

Enemigo::Enemigo()
{
    vida = 1;

    velocidad.x = -100.f;

    cargarTextura(
        "assets/images/goomba.png"
    );

    sprite->setScale(
        {.15f, .15f}
    );
}

Enemigo::~Enemigo()
{
}

void Enemigo::mover()
{
    if(posicion.x < 1000.f)
    {
        velocidad.x = 100.f;
    }

    if(posicion.x > 1400.f)
    {
        velocidad.x = -100.f;
    }
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