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
    
    std::unique_ptr<Bloque>
    banderaFinal;

    std::vector<
        std::unique_ptr<Bloque>
    > suelo;

   

   

public:

    Nivel();

    virtual ~Nivel();

    virtual void cargar();

     Bloque* getBanderaFinal();

    virtual void actualizar(
        float dt
    );

    virtual void dibujar(
        sf::RenderWindow&
        ventana
    );

     std::vector<
    std::unique_ptr<Moneda>
>& getMonedas();

std::vector<
    std::unique_ptr<Enemigo>
>& getEnemigos();

std::vector<
    std::unique_ptr<Bloque>
>&getSuelo();

std::vector<
    std::unique_ptr<Bloque>
>& getBloques();



};