#include "Jugador.hpp"
#include "Bolita.hpp"

Jugador::Jugador()
{
    vidas = 3;

    puntuacion = 0;

    enSuelo = false;

    invencible = false;

    velocidadMovimiento = 250.f;

    fuerzaSalto = -550.f;
}

Jugador::~Jugador()
{
}

void Jugador::mover(
    float direccion
)
{
    velocidad.x =
        direccion *
        velocidadMovimiento;
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

void Jugador::recibirDanio(
    int cantidad
)
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
}

void Jugador::actualizar(
    float dt
)
{
    constexpr float gravedad =
        1200.f;

    velocidad.y +=
        gravedad * dt;

    sprite->move(
        velocidad * dt
    );

    posicion =
        sprite->getPosition();

    for(auto& bolita :
        proyectiles)
    {
        bolita->actualizar(dt);
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
