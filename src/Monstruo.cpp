#include "Monstruo.hpp"

Monstruo::Monstruo()
{
    velocidad.x = -80.f;
}

Monstruo::~Monstruo()
{
}

void Monstruo::mover()
{
    if(sprite)
    {
        sprite->move(
            sf::Vector2f(
                velocidad.x,
                0.f
            )
        );
    }
}

void Monstruo::actualizar(float dt)
{
    mover();

    if(sprite)
    {
        sprite->move(
            sf::Vector2f(
                0.f,
                velocidad.y * dt
            )
        );

        posicion =
            sprite->getPosition();
    }
}

