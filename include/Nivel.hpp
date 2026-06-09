#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Bloque.hpp"
#include "Tubo.hpp"

#include "Moneda.hpp"
#include "Enemigo.hpp"

class Nivel
{
protected:

    std::vector<
        std::unique_ptr<Enemigo>
    > enemigos;

    std::vector<
        std::unique_ptr<Moneda>
    > monedas;

    std::vector<
        std::unique_ptr<Bloque>
    > bloques;

    std::vector<
        std::unique_ptr<Tubo>
    > tubos;

public:

    Nivel();

    virtual ~Nivel();

    virtual void cargar();

    virtual void actualizar(
        float dt
    );

    virtual void dibujar(
        sf::RenderWindow&
        ventana
    );
};