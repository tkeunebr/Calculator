#ifndef RATIONNELFACTORY_H
#define RATIONNELFACTORY_H

#include "constantefactory.h"
#include "rationnel.h"

class RationnelFactory : public ConstanteFactory
{
    public:
        virtual Constante* newInstance();
};

#endif // RATIONNELFACTORY_H
