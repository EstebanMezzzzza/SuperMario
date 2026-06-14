#include "Moneda.hpp"

Moneda::Moneda()
{
    cargarTextura(
        "assets/images/moneda.png"
    );

    sprite->setScale(
        {.08f, .08f}
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
