#pragma once

#include "Entidad.hpp"

class Jugador : public Entidad
{
protected:

    int vidas;
    int puntuacion;

    bool enSuelo;

public:

    Jugador();

    virtual ~Jugador();

    virtual void mover(float direccion);

    virtual void saltar();

    virtual void recibirDanio(int cantidad);

    virtual void actualizar(float dt) override;

    int getVidas() const;

    int getPuntuacion() const;
};