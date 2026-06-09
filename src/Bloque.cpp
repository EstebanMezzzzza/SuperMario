#include "Bloque.hpp"

Bloque::Bloque()
    : destruido(false),
      contenido(nullptr)
{
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
