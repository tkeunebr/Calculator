#include "complexereelfactory.h"

Constante* ComplexeReelFactory::newInstance() {
    return new Complexe(0, 0);
}
