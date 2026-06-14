#pragma once

#include <vector>
#include <memory>

#include "Entidad.hpp"

class Bolita;

class Jugador : public Entidad
{
protected:

    int vidas;

    int puntuacion;

    bool enSuelo;

    bool invencible;

    float tiempoInvencible;

    float velocidadMovimiento;

    float fuerzaSalto;

    std::vector<
        std::unique_ptr<Bolita>
    > proyectiles;

public:

    Jugador();

     int getVidas() const;

    int getPuntuacion() const;

    virtual ~Jugador();

    virtual void mover(
        float direccion
    );

    virtual void saltar();

    virtual void disparar();

    virtual void recibirDanio(
        int cantidad
    );

    virtual void actualizar(
        float dt
    ) override;

    void agregarPuntos(
    int cantidad
);
};