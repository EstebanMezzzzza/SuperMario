#include "../../include/entidades/Entidad.hpp"

Entidad::Entidad()
{
    posicion = {0.f, 0.f};
    velocidad = {0.f, 0.f};
}

Entidad::~Entidad()
{
}

void Entidad::dibujar(sf::RenderWindow& ventana)
{
    ventana.draw(sprite);
}

sf::FloatRect Entidad::obtenerLimites() const
{
    return sprite.getGlobalBounds();
}

void Entidad::setPosicion(float x, float y)
{
    posicion.x = x;
    posicion.y = y;

    sprite.setPosition(posicion);
}

sf::Vector2f Entidad::getPosicion() const
{
    return posicion;
}