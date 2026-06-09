#include "Tortuga.hpp"

Tortuga::Tortuga()
{
    velocidad.x = -100.f;
}

Tortuga::~Tortuga()
{
}

void Tortuga::mover()
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

void Tortuga::actualizar(float dt)
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
