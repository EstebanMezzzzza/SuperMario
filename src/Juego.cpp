#include "Juego.hpp"

Juego::Juego()
    :
    ventana(
        sf::VideoMode(
            {1280,720}
        ),
        "Super Mario"
    )
{
    estado =
        EstadoJuego::MENU;

    jugador =
        std::make_unique<
            Plomero>();

    nivelActual =
        std::make_unique<
            Nivel>();
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

void Juego::actualizar(
    float dt
)
{
    if(
        estado ==
        EstadoJuego::JUGANDO
    )
    {
        jugador->actualizar(dt);

        nivelActual
            ->actualizar(dt);
    }
}

void Juego::renderizar()
{
    ventana.clear();

    nivelActual
        ->dibujar(
            ventana
        );

    jugador
        ->dibujar(
            ventana
        );

    ventana.display();
}
