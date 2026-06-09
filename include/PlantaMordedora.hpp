#pragma once

#include "Enemigo.hpp"

class PlantaMordedora : public Enemigo
{
public:

    PlantaMordedora();

    ~PlantaMordedora() override;

    void mover() override;

    void actualizar(float dt) override;
};
