#include "Jugador.hpp"
#include "Bolita.hpp"
#include <iostream>

Jugador::Jugador()
{
    vidas = 3;
    puntuacion = 0;

    invencible = false;

    tiempoInvencible = 0.f;

    enSuelo = true;

    invencible = false;

    velocidadMovimiento = 350.f;
    fuerzaSalto = -950.f;
}

Jugador::~Jugador()
{
}

void Jugador::mover(float direccion)
{
    velocidad.x =
        direccion *
        velocidadMovimiento;

    if(sprite)
    {
        if(direccion > 0)
        {
            sprite->setScale(
                {0.15f, 0.15f}
            );
        }
        else if(direccion < 0)
        {
            sprite->setScale(
                {-0.15f, 0.15f}
            );
        }
    }
}

void Jugador::saltar()
{
    if(enSuelo)
    {
        velocidad.y =
            fuerzaSalto;

        enSuelo = false;
    }
}

void Jugador::disparar()
{
}

void Jugador::recibirDanio(int cantidad)
{
    if(invencible)
    {
        return;
    }

    vidas -= cantidad;

    if(vidas < 0)
    {
        vidas = 0;
    }

    invencible = true;

    tiempoInvencible = 1.5f;

    std::cout
        << "VIDAS: "
        << vidas
        << std::endl;
}



void Jugador::actualizar(float dt)
{
    if(invencible)
{
    tiempoInvencible -= dt;

    if(tiempoInvencible <= 0.f)
    {
        invencible = false;
    }
}
    constexpr float gravedad =
        1200.f;

    velocidad.y +=
        gravedad * dt;

    if(sprite)
    {
        sprite->move(
            velocidad * dt
        );

        posicion =
            sprite->getPosition();

        if(posicion.y >= 570.f)
        {
            posicion.y = 570.f;

            sprite->setPosition(
                posicion
            );

            velocidad.y = 0.f;

            enSuelo = true;
        }
    }

    for(auto& bolita :
        proyectiles)
    {
        bolita->actualizar(dt);
    }

    if(tiempoInvencible > 0.f)
{
    tiempoInvencible -= dt;

    invencible = true;
}
else
{
    invencible = false;
}


}

int Jugador::getVidas() const
{
    return vidas;
}

int Jugador::getPuntuacion() const
{
    return puntuacion;
}

void Jugador::agregarPuntos(
    int cantidad
)
{
    puntuacion += cantidad;
}