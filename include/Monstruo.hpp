#pragma once

#include "Enemigo.hpp"

class Monstruo : public Enemigo
{
public:

    Monstruo();

    ~Monstruo() override;

    void mover() override;

    void actualizar(float dt) override;
};
