#include "GestorColisiones.hpp"
#include "Entidad.hpp"

bool GestorColisiones::colisionan(
    const Entidad& a,
    const Entidad& b
)
{
    return
        a.obtenerLimites()
        .findIntersection(
            b.obtenerLimites()
        )
        .has_value();
}
