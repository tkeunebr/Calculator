#include "rationnelfactory.h"

Constante* RationnelFactory::newInstance() {
    return new Rationnel();
}
