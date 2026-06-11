#pragma once

#include "Entidad.hpp"

class Jugador;

class PowerUp : public Entidad
{
public:

    PowerUp();

    ~PowerUp() override;

    void actualizar(float dt) override;

    virtual void aplicar(
        Jugador& jugador
    ) = 0;
};
