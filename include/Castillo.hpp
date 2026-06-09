#pragma once

#include "Nivel.hpp"

class Castillo : public Nivel
{
public:

    Castillo();

    ~Castillo() override;

    void cargar() override;
};