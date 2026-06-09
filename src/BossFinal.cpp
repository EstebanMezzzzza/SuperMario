#include "BossFinal.hpp"

BossFinal::BossFinal()
{
    vida = 50;
}

BossFinal::~BossFinal()
{
}

void BossFinal::actualizar(float dt)
{
    Boss::actualizar(dt);
}
