#include "GestorRecursos.hpp"

GestorRecursos::GestorRecursos()
{
}

sf::Texture&
GestorRecursos::obtenerTextura(
    const std::string& archivo
)
{
    auto it = texturas.find(archivo);

    if(it == texturas.end())
    {
        sf::Texture textura;

        textura.loadFromFile(archivo);

        texturas.emplace(
            archivo,
            std::move(textura)
        );
    }

    return texturas.at(archivo);
}
