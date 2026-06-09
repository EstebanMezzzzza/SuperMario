#pragma once

#include "Nivel.hpp"

class NivelExtra : public Nivel
{
public:

    NivelExtra();

    ~NivelExtra() override;

    void cargar() override;
};