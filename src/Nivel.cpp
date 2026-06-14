#include "Nivel.hpp"
#include <iostream>

Nivel::Nivel()
{
    std::cout
        << "Creando nivel..."
        << std::endl;

    // ====================
    // BLOQUES
    // ====================

    for(int i = 0; i < 10; i++)
    {
        auto bloque =
            std::make_unique<Bloque>();

        if(
            !bloque->cargarTextura(
                "assets/images/bloque.png"
            )
        )
        {
            std::cout
                << "Error cargando bloque.png"
                << std::endl;
        }

        bloque->setPosicion(
            500.f + i * 70.f,
            400.f
        );

        bloque->setEscala(
            1.55f,
            1.55f
        );

        bloques.push_back(
            std::move(bloque)
        );
    }

    std::cout
        << "Bloques creados"
        << std::endl;

    // ====================
    // MONEDAS
    // ====================

    for(int i = 0; i < 10; i++)
    {
        auto moneda =
            std::make_unique<Moneda>();

        if(
            !moneda->cargarTextura(
                "assets/images/moneda.png"
            )
        )
        {
            std::cout
                << "Error cargando moneda.png"
                << std::endl;
        }

        moneda->setPosicion(
            600.f + i * 120.f,
            300.f
        );

        moneda->setEscala(
            0.06f,
            0.06f
        );

        monedas.push_back(
            std::move(moneda)
        );
    }

    std::cout
        << "Monedas creadas"
        << std::endl;

    // ====================
    // GOOMBAS
    // ====================

    for(int i = 0; i < 5; i++)
    {
        auto enemigo =
            std::make_unique<Enemigo>();

        if(
            !enemigo->cargarTextura(
                "assets/images/goomba.png"
            )
        )
        {
            std::cout
                << "Error cargando goomba.png"
                << std::endl;
        }

        enemigo->setPosicion(
            900.f + i * 400.f,
            520.f
        );

        enemigo->setEscala(
            0.15f,
            0.15f
        );

        enemigos.push_back(
            std::move(enemigo)
        );
    }

    std::cout
        << "Goombas creados"
        << std::endl;

    std::cout
        << "Nivel creado correctamente"
        << std::endl;
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
    if(
        enemigo->estaActiva()
    )
    {
        enemigo->dibujar(
            ventana
        );
    }
}
}

std::vector<
    std::unique_ptr<Bloque>
>& Nivel::getBloques()
{
    return bloques;
}

std::vector<
    std::unique_ptr<Bloque>
>& Nivel::getSuelo()
{
    return suelo;
}

std::vector<
    std::unique_ptr<Moneda>
>& Nivel::getMonedas()
{
    return monedas;
}

std::vector<
    std::unique_ptr<Enemigo>
>& Nivel::getEnemigos()
{
    return enemigos;
}