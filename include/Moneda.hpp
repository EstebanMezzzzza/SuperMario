#pragma once

#include "Entidad.hpp"

class Moneda : public Entidad
{
private:

    bool recogida;

public:

    Moneda();

    ~Moneda() override;

    void recoger();

    bool estaRecogida() const;

    void actualizar(float dt) override;
};