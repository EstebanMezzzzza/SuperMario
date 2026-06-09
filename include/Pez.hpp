#pragma once

#include "Enemigo.hpp"

class Pez : public Enemigo
{
public:

    Pez();

    ~Pez() override;

    void mover() override;

    void actualizar(float dt) override;
};
