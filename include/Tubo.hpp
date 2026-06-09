#pragma once

#include "ObjetoEscenario.hpp"

class Tubo : public ObjetoEscenario
{
private:

    bool entradaSecreta;

public:

    Tubo();

    virtual ~Tubo();

    bool esEntradaSecreta() const;
};
