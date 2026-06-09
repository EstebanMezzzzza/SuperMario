#include "Tubo.hpp"

Tubo::Tubo()
    : entradaSecreta(false)
{
}

Tubo::~Tubo()
{
}

bool Tubo::esEntradaSecreta() const
{
    return entradaSecreta;
}
