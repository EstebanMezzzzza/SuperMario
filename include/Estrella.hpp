#pragma once

#include "PowerUp.hpp"

class Estrella : public PowerUp
{
public:

    Estrella();

    ~Estrella() override;

    void aplicar(Jugador& jugador) override;

    void actualizar(float dt) override;
};
