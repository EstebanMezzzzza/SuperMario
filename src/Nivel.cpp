#include "Nivel.hpp"
#include <iostream>

Bloque* Nivel::getBanderaFinal()
{
    return banderaFinal.get();
}

Nivel::Nivel()
{
    banderaFinal =
    std::make_unique<Bloque>();

banderaFinal->cargarTextura(
    "assets/images/bandera.png"
);

banderaFinal->setPosicion(
    3000.f,
    430.f
);

banderaFinal->setEscala(
    .20f,
    .20f
);

    std::cout
        << "Creando nivel..."
        << std::endl;

    // ====================
    // BLOQUES
    // ====================

    for(int i = 0; i < 40; i++)
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
    100.f + i * 70.f,
    400.f
);

        bloque->setEscala(
            .25f,
            .25f
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

    for(int i = 0; i < 30; i++)
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
            1.f,
            1.f
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

    for(int i = 0; i < 10; i++)
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
            570.f
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

    enemigos.erase(
    std::remove_if(
        enemigos.begin(),
        enemigos.end(),
        [](const auto& enemigo)
        {
            return !enemigo->estaActiva();
        }
    ),
    enemigos.end()
);
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

for(auto& bloque : bloques)
{
    auto r =
        bloque->obtenerLimites();

    std::cout
        << "Bloque: "
        << r.position.x
        << ", "
        << r.position.y
        << std::endl;

    bloque->dibujar(
        ventana
    );
}

for(auto& bloque : bloques)
{
    bloque->dibujar(
        ventana
    );

    auto r =
        bloque->obtenerLimites();
}

    if(banderaFinal)
{
    banderaFinal->dibujar(
        ventana
    );
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