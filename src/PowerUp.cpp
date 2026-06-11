#include "PowerUp.hpp"

PowerUp::PowerUp()
{
}

PowerUp::~PowerUp()
{
}

void PowerUp::actualizar(float dt)
{
    if(sprite)
    {
        sprite->move(
            velocidad * dt
        );

        posicion =
            sprite->getPosition();
    }
}
