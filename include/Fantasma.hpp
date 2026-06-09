#pragma once

#include "Enemigo.hpp"

class Fantasma : public Enemigo
{
public:

    Fantasma();

    ~Fantasma() override;

    void mover() override;

    void actualizar(float dt) override;
};
