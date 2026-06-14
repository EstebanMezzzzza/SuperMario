#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

class Entidad
{
protected:

    std::unique_ptr<sf::Texture> textura;

    std::unique_ptr<sf::Sprite> sprite;

    sf::Vector2f posicion;

    sf::Vector2f velocidad;

    bool activa;

public:

    Entidad();

    virtual ~Entidad();

    virtual void actualizar(float dt) = 0;

    virtual void dibujar(
        sf::RenderWindow& ventana
    );

    bool cargarTextura(
        const std::string& ruta
    );

    sf::FloatRect obtenerLimites() const;

    void setPosicion(
        float x,
        float y
    );

    sf::Vector2f getPosicion() const;

    void setVelocidad(
        const sf::Vector2f& v
    );

    sf::Vector2f getVelocidad() const;

    bool estaActiva() const;

    void activar();

    void desactivar();

    void setEscala(
    float x,
    float y
);
};