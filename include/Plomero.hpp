#pragma once

#include "Jugador.hpp"

class Plomero : public Jugador
{
public:
    Plomero();
    ~Plomero() override;

    void actualizar(float dt) override;
};
