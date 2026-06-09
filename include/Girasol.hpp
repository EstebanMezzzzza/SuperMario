#pragma once

#include "PowerUp.hpp"

class Girasol : public PowerUp
{
public:

    Girasol();

    ~Girasol() override;

    void aplicar(Jugador& jugador) override;

    void actualizar(float dt) override;
};
