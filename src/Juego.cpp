#include "Juego.hpp"
#include <iostream>
#include <cmath>

Juego::Juego():
    ventana(
    sf::VideoMode({1280,720}),
    "Super Mario"
)
{
    estado =
        EstadoJuego::MENU;

    camara =
    ventana.getDefaultView();

    textoVidas =
    std::make_unique<sf::Text>(
        fuente
    );

textoPuntos =
    std::make_unique<sf::Text>(
        fuente
    );

    jugador =
        std::make_unique<
            Plomero>();

    nivelActual =
        std::make_unique<
            Nivel>();

    fuente.openFromFile(
    "assets/fonts/arial.ttf"
);

textoVidas->setString(
    "Vidas: " +
    std::to_string(
        jugador->getVidas()
    )
);

textoPuntos->setString(
    "Puntos: " +
    std::to_string(
        jugador->getPuntuacion()
    )
);

textoVidas->setPosition(
    {20.f, 20.f}
);

textoPuntos->setPosition(
    {20.f, 60.f}
);

}

void Juego::ejecutar()
{
    sf::Clock reloj;

    while(
        ventana.isOpen()
    )
    {
        float dt =
            reloj.restart()
            .asSeconds();

        procesarEventos();

        actualizar(dt);

        renderizar();
    }
}
void Juego::procesarEventos()
{
    while(
        const std::optional evento =
        ventana.pollEvent()
    )
    {
        if(
            evento->is<
            sf::Event::Closed>()
        )
        {
            ventana.close();
        }
    }
}

void Juego::actualizar(float dt)
{

    std::cout
    << "Enemigos: "
    << nivelActual->getEnemigos().size()
    << std::endl;


    float direccion = 0.f;

    jugador->actualizar(dt);

    nivelActual->actualizar(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        direccion = -1.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        direccion = 1.f;

    jugador->mover(direccion);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        jugador->saltar();
    }

for(auto& moneda :
    nivelActual->getMonedas())
{
    if(
        jugador
            ->obtenerLimites()
            .findIntersection(
                moneda
                ->obtenerLimites()
            )
    )
    {
        if(
            !moneda->estaRecogida()
        )
        {
            moneda->recoger();

            jugador->agregarPuntos(
                100
            );
        }
    }
}

    camara.setCenter(
    {
        jugador->getPosicion().x,
        360.f
    });

for(auto& enemigo :
    nivelActual->getEnemigos())
{
    auto marioRect =
        jugador->obtenerLimites();

    auto enemigoRect =
        enemigo->obtenerLimites();

    std::cout
        << "Mario: "
        << marioRect.position.x
        << ", "
        << marioRect.position.y
        << "\n";

    std::cout
        << "Goomba: "
        << enemigoRect.position.x
        << ", "
        << enemigoRect.position.y
        << "\n";

        std::cout
        << "Mario size: "
        << marioRect.size.x
        << ", "
        << marioRect.size.y
        << "\n";

    std::cout
        << "Goomba size: "
        << enemigoRect.size.x
        << ", "
        << enemigoRect.size.y
        << "\n";

    auto interseccion =
    marioRect.findIntersection(
        enemigoRect
    );

if(interseccion.has_value())
{
    std::cout
        << "COLISION DETECTADA\n";

    jugador->recibirDanio(1);
}
}

for(auto& enemigo :
    nivelActual->getEnemigos())
{
    float dx =
        std::abs(
            jugador->getPosicion().x -
            enemigo->getPosicion().x
        );

    float dy =
        std::abs(
            jugador->getPosicion().y -
            enemigo->getPosicion().y
        );

    if(dx < 40.f && dy < 40.f)
{
    if(
        jugador
            ->getVelocidad()
            .y > 0
    )
    {
        enemigo->desactivar();

        jugador->agregarPuntos(
            200
        );
    }
    else
    {
        jugador->recibirDanio(1);
    }
}
}

for(auto& bloque :
    nivelActual->getBloques())
{
    auto interseccion =
        jugador->obtenerLimites()
        .findIntersection(
            bloque->obtenerLimites()
        );

    if(interseccion.has_value())
    {
        if(
            jugador->getVelocidad().y > 0
        )
        {
            auto pos =
                jugador->getPosicion();

            pos.y -=
                interseccion->size.y;

            jugador->setPosicion(
                pos.x,
                pos.y
            );

            jugador->setVelocidad(
            {
                jugador->getVelocidad().x,
                0.f
            });
        }
    }
}

if(
    jugador->getVidas() <= 0
)
{
    estado =
        EstadoJuego::GAME_OVER;
}

if(
    jugador->getPosicion().x >
    3000.f
)
{
    estado =
        EstadoJuego::VICTORIA;
}

textoPuntos->setString(
    "Puntos: " +
    std::to_string(
        jugador->getPuntuacion()
    )
);

textoVidas->setString(
    "Vidas: " +
    std::to_string(
        jugador->getVidas()
    )
);

}

void Juego::renderizar()
{
    ventana.clear(
        sf::Color(100,149,237)
    );

    // Vista del mundo
    ventana.setView(camara);

    nivelActual->dibujar(
        ventana
    );

    jugador->dibujar(
        ventana
    );

    for(auto& enemigo :
        nivelActual->getEnemigos())
    {
        auto r =
            enemigo->obtenerLimites();

        sf::RectangleShape caja;

        caja.setPosition(
            {
                r.position.x,
                r.position.y
            }
        );

        caja.setSize(
            {
                r.size.x,
                r.size.y
            }
        );

        caja.setFillColor(
            sf::Color::Transparent
        );

        caja.setOutlineThickness(
            2.f
        );

        caja.setOutlineColor(
            sf::Color::Red
        );

        ventana.draw(caja);
    }

    // Cambiar a la vista fija de la interfaz
    ventana.setView(
        ventana.getDefaultView()
    );

    ventana.draw(
        *textoVidas
    );

    ventana.draw(
        *textoPuntos
    );

    for(int i = 0; i < 50; i++)
{
    sf::RectangleShape bloque(
        {64.f,64.f}
    );

    bloque.setPosition(
        {
            i * 64.f,
            600.f
        }
    );

    bloque.setFillColor(
        sf::Color(
            120,
            70,
            15
        )
    );

    ventana.draw(
        bloque
    );
}

    ventana.display();
}