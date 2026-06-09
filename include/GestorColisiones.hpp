#pragma once

class Entidad;

class GestorColisiones
{
public:

    static bool colisionan(
        const Entidad& a,
        const Entidad& b
    );
};
