#pragma once

#include "PowerUp.hpp"

class ChampinionVerde : public PowerUp
{
public:

    ChampinionVerde();

    ~ChampinionVerde() override;

    void aplicar(Jugador& jugador) override;

    void actualizar(float dt) override;
};
