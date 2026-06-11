#include "Bloque.hpp"

Bloque::Bloque()
    : destruido(false),
      contenido(nullptr)
{
    cargarTextura(
        "assets/images/bloque.png"
    );

    sprite->setScale(
        {.15f, .15f}
    );
}


Bloque::~Bloque()
{
}

void Bloque::golpear()
{
}

bool Bloque::estaDestruido() const
{
    return destruido;
}
