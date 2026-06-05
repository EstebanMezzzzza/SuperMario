#pragma once

#include <SFML/Graphics.hpp>

class Entidad
{
protected:

    sf::Sprite sprite;
    sf::Texture textura;

    sf::Vector2f posicion;
    sf::Vector2f velocidad;

public:

    Entidad();
    virtual ~Entidad();

    virtual void actualizar(float dt) = 0;

    virtual void dibujar(sf::RenderWindow& ventana);

    virtual sf::FloatRect obtenerLimites() const;

    virtual void setPosicion(float x, float y);

    virtual sf::Vector2f getPosicion() const;
};