#pragma once

#include "Nivel.hpp"

class CasaTerror : public Nivel
{
public:

    CasaTerror();

    ~CasaTerror() override;

    void cargar() override;
};