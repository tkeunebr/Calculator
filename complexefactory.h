#ifndef COMPLEXEFACTORY_H
#define COMPLEXEFACTORY_H

#include "constantefactory.h"
#include "complexe.h"

class ComplexeFactory : public ConstanteFactory
{
    public:
        virtual Constante* newInstance();
};

#endif // COMPLEXEFACTORY_H
