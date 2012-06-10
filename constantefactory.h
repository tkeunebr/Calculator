#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include "constante.h"

class ConstanteFactory
{
    public:
        virtual Constante* newInstance() = 0;
};

#endif // CONSTANTEFACTORY_H
