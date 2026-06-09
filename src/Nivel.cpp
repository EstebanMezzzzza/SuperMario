#include "Nivel.hpp"

Nivel::Nivel()
{
}

Nivel::~Nivel()
{
}

void Nivel::cargar()
{
}

void Nivel::actualizar(
    float dt
)
{
    for(auto& enemigo :
        enemigos)
    {
        enemigo->actualizar(dt);
    }

    for(auto& moneda :
        monedas)
    {
        moneda->actualizar(dt);
    }
}

void Nivel::dibujar(
    sf::RenderWindow&
    ventana
)
{
    for(auto& bloque :
        bloques)
    {
        bloque->dibujar(
            ventana
        );
    }

    for(auto& tubo :
        tubos)
    {
        tubo->dibujar(
            ventana
        );
    }

    for(auto& moneda :
        monedas)
    {
        moneda->dibujar(
            ventana
        );
    }

    for(auto& enemigo :
        enemigos)
    {
        enemigo->dibujar(
            ventana
        );
    }
}