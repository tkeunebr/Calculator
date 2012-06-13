#include "complexerationnelfactory.h"

Constante* ComplexeRationnelFactory::newInstance() {
    return new Complexe(Rationnel(), Rationnel());
}
