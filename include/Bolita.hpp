#pragma once

#include "Entidad.hpp"

class Bolita : public Entidad
{
private:

    int danio;

public:

    Bolita();

    ~Bolita() override;

    int obtenerDanio() const;

    void actualizar(float dt) override;
};