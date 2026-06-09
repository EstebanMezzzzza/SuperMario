#pragma once

#include "ObjetoEscenario.hpp"

class PowerUp;

class Bloque : public ObjetoEscenario
{
private:

    bool destruido;

    PowerUp* contenido;

public:

    Bloque();

    virtual ~Bloque();

    void golpear();

    bool estaDestruido() const;
};
