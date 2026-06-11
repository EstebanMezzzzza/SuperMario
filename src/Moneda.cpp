#include "Moneda.hpp"

Moneda::Moneda()
{
    cargarTextura(
        "assets/images/moneda.png"
    );

    sprite->setScale(
        {.15f, .15f}
    );
}
Moneda::~Moneda()
{
}

void Moneda::recoger()
{
    recogida = true;

    desactivar();
}

bool Moneda::estaRecogida() const
{
    return recogida;
}

void Moneda::actualizar(float)
{
}
