#include "ObjetoEscenario.hpp"

ObjetoEscenario::ObjetoEscenario()
{
}

ObjetoEscenario::~ObjetoEscenario()
{
}

bool ObjetoEscenario::cargarTextura(
    const std::string& ruta
)
{
    textura =
        std::make_unique<sf::Texture>();

    if(!textura->loadFromFile(ruta))
    {
        return false;
    }

    sprite =
        std::make_unique<sf::Sprite>(
            *textura
        );

    return true;
}

void ObjetoEscenario::dibujar(
    sf::RenderWindow& ventana
)
{
    if(sprite)
    {
        ventana.draw(*sprite);
    }
}

sf::FloatRect
ObjetoEscenario::obtenerLimites() const
{
    if(sprite)
    {
        return sprite->getGlobalBounds();
    }

    return {};
}

void ObjetoEscenario::setPosicion(
    float x,
    float y
)
{
    if(sprite)
    {
        sprite->setPosition(
            sf::Vector2f(x, y)
        );
    }
}