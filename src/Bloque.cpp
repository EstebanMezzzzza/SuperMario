#include "Bloque.hpp"

Bloque::Bloque()
    : destruido(false),
      contenido(nullptr)
{
    cargarTextura(
        "assets/images/bloque.png"
    );

    sprite->setScale(
        {.10f, .10f}
    );
}


Bloque::~Bloque()
{
}

void Bloque::golpear()
{
    if(!destruido)
    {
        destruido = true;
    }
}

bool Bloque::estaDestruido() const
{
    return destruido;
}

void Bloque::actualizar(float)
{
}