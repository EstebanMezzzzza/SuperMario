#pragma once

#include "Jugador.hpp"

class Plomero : public Jugador
{
public:

    Plomero();

    virtual ~Plomero();

    void actualizar(float dt) override;
};