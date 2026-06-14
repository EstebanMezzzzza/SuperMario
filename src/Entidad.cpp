#include "Entidad.hpp"
#include <iostream>

Entidad::Entidad()
    :
    posicion(0.f, 0.f),
    velocidad(0.f, 0.f),
    activa(true)
{
}

Entidad::~Entidad()
{
}

void Entidad::dibujar(
    sf::RenderWindow& ventana
)
{
    if(activa && sprite)
    {
        std::cout
            << "Sprite OK\n";

        ventana.draw(*sprite);
    }
    else
    {
        std::cout
            << "Sprite NULL\n";
    }
}

bool Entidad::cargarTextura(
    const std::string& ruta
)
{
    textura = std::make_unique<sf::Texture>();

    if(!textura->loadFromFile(ruta))
    {
        return false;
    }

    sprite =
        std::make_unique<sf::Sprite>(
            *textura
        );

    return true;

   std::cout
    << ruta
    << " -> "
    << textura->getSize().x
    << " x "
    << textura->getSize().y
    << std::endl;
}

sf::FloatRect Entidad::obtenerLimites() const
{
    if(sprite)
    {
        return sprite->getGlobalBounds();
    }

    return {};
}

void Entidad::setPosicion(
    float x,
    float y
)
{
    posicion = {x, y};

    if(sprite)
    {
        sprite->setPosition(posicion);
    }
}

sf::Vector2f Entidad::getPosicion() const
{
    return posicion;
}

void Entidad::setVelocidad(
    const sf::Vector2f& v
)
{
    velocidad = v;
}

sf::Vector2f Entidad::getVelocidad() const
{
    return velocidad;
}

bool Entidad::estaActiva() const
{
    return activa;
}

void Entidad::activar()
{
    activa = true;
}

void Entidad::desactivar()
{
    activa = false;
}

void Entidad::setEscala(
    float x,
    float y
)
{
    if(sprite)
    {
        sprite->setScale(
            {x, y}
        );
    }
}