#include "complexefactory.h"

Constante* ComplexeFactory::newInstance() {
    return new Complexe();
}
