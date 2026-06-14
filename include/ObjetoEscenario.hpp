#pragma once

#include <memory>
#include <Entidad.hpp>
#include <SFML/Graphics.hpp>

class ObjetoEscenario : public Entidad
{
protected:

    std::unique_ptr<sf::Texture> textura;

    std::unique_ptr<sf::Sprite> sprite;

public:

    ObjetoEscenario();

    virtual ~ObjetoEscenario();

    virtual void dibujar(
        sf::RenderWindow& ventana
    );

    virtual sf::FloatRect
    obtenerLimites() const;

    virtual void setPosicion(
        float x,
        float y
    );

    bool cargarTextura(
        const std::string& ruta
    );
};
