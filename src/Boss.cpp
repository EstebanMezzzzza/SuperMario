#include "Boss.hpp"

Boss::Boss()
    : fase(1)
{
    vida = 20;
}

Boss::~Boss()
{
}

void Boss::mover()
{
}

void Boss::actualizar(float dt)
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
