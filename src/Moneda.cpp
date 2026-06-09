#include "Moneda.hpp"

Moneda::Moneda()
    : recogida(false)
{
}

Moneda::~Moneda()
{
}

void Moneda::recoger()
{
    recogida = true;
}

bool Moneda::estaRecogida() const
{
    return recogida;
}

void Moneda::actualizar(float)
{
}
