#pragma once

#include "Entidad.hpp"

class Enemigo : public Entidad
{
protected:

    int vida;

public:

    Enemigo();

    virtual ~Enemigo();

    virtual void mover();

    virtual void actualizar(float dt) override;
};