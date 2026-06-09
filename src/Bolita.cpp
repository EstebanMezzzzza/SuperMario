#include "Bolita.hpp"

Bolita::Bolita()
    : danio(1)
{
}

Bolita::~Bolita()
{
}

int Bolita::obtenerDanio() const
{
    return danio;
}

void Bolita::actualizar(float dt)
{
    sprite->move(velocidad * dt);

    posicion = sprite->getPosition();
}
