#pragma once

#include "Enemigo.hpp"

class Boss : public Enemigo
{
protected:

    int fase;

public:

    Boss();

    ~Boss() override;

    void mover() override;

    void actualizar(float dt) override;
};
