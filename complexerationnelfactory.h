#ifndef COMPLEXERATIONNELFACTORY_H
#define COMPLEXERATIONNELFACTORY_H

#include "constantefactory.h"
#include "complexe.h"

class ComplexeRationnelFactory : public ConstanteFactory
{
    public:
        virtual Constante* newInstance();
};

#endif // COMPLEXERATIONNELFACTORY_H
