#pragma once

#include "PowerUp.hpp"

class Champinion : public PowerUp
{
public:

    Champinion();

    ~Champinion() override;

    void aplicar(Jugador& jugador) override;

    void actualizar(float dt) override;
};
