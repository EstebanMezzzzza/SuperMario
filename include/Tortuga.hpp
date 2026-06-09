#pragma once

#include "Enemigo.hpp"

class Tortuga : public Enemigo
{
public:

    Tortuga();

    ~Tortuga() override;

    void mover() override;

    void actualizar(float dt) override;
};
