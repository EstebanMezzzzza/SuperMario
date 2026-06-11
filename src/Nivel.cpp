#include "Nivel.hpp"

std::vector<
    std::unique_ptr<Enemigo>
>& Nivel::getEnemigos()
{
    return enemigos;
}

std::vector<
    std::unique_ptr<Moneda>
>& Nivel::getMonedas()
{
    return monedas;
}

Nivel::Nivel()
{
    for(int i = 0; i < 5; i++)
{
    auto bloque =
        std::make_unique<Bloque>();

    bloque->setPosicion(
        500.f + i * 64.f,
        400.f
    );

    bloques.push_back(
        std::move(bloque)
    );
}

auto moneda =
    std::make_unique<Moneda>();

moneda->setPosicion(
    800.f,
    300.f
);

monedas.push_back(
    std::move(moneda)
);

auto enemigo =
    std::make_unique<Enemigo>();

enemigo->setPosicion(
    1200.f,
    520.f
);

enemigos.push_back(
    std::move(enemigo)
);

std::vector<
    std::unique_ptr<Moneda>
>& getMonedas();

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