#pragma once

#include "Nivel.hpp"

class NivelAgua : public Nivel
{
public:

    NivelAgua();

    ~NivelAgua() override;

    void cargar() override;
};