#include "PlantaMordedora.hpp"

PlantaMordedora::PlantaMordedora()
{
}

PlantaMordedora::~PlantaMordedora()
{
}

void PlantaMordedora::mover()
{
}

void PlantaMordedora::actualizar(float dt)
{
    sprite->move(velocidad * dt);

    posicion = sprite->getPosition();
}
