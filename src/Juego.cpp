#include "Juego.hpp"
#include <iostream>

Juego::Juego():
    ventana(
    sf::VideoMode({1280,720}),
    "PRUEBA123"
)
{
    estado =
        EstadoJuego::MENU;

    camara =
    ventana.getDefaultView();

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

void Juego::actualizar(float dt)
{
    float direccion = 0.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        direccion = -1.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        direccion = 1.f;

    jugador->mover(direccion);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        jugador->saltar();
    }

    jugador->actualizar(dt);

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
        moneda->recoger();
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
    if(
        jugador
            ->obtenerLimites()
            .findIntersection(
                enemigo
                ->obtenerLimites()
            )
    )
    {
        jugador
            ->recibirDanio(1);
    }
}
}

void Juego::renderizar()
{
    ventana.clear(sf::Color::Blue);

    ventana.setView(camara);

    sf::RectangleShape suelo({3000.f,100.f});
    suelo.setPosition({0.f,620.f});
    suelo.setFillColor(sf::Color(50,200,50));
    ventana.draw(suelo);

    for(int i = 0; i < 5; i++)
    {
        sf::RectangleShape bloque({64.f,64.f});

        bloque.setPosition(
        {
            500.f + i * 64.f,
            400.f
        });

        bloque.setFillColor(
            sf::Color(180,100,30)
        );

        ventana.draw(bloque);
    }

    sf::CircleShape moneda(15.f);
    moneda.setPosition({800.f,300.f});
    moneda.setFillColor(sf::Color::Yellow);
    ventana.draw(moneda);

    sf::RectangleShape goomba({50.f,50.f});
    goomba.setPosition({1200.f,570.f});
    goomba.setFillColor(sf::Color::Red);
    ventana.draw(goomba);

    nivelActual->dibujar(
    ventana
);

jugador->dibujar(
    ventana
);

    jugador->dibujar(ventana);

    ventana.display();
}