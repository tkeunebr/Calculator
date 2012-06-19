#ifndef COMPLEXERATIONNELFACTORY_H
#define COMPLEXERATIONNELFACTORY_H

#include "constantefactory.h"
#include "complexe.h"

/**
 * Classe implementant le design pattern Factory. Permet de creer des constantes du bon type (ici Complexe de Rationnels) en fonction du mode,
 * a l'aide de la methode newInstance
 */

class ComplexeRationnelFactory : public ConstanteFactory
{
    public:
        virtual Constante* newInstance();
};

#endif // COMPLEXERATIONNELFACTORY_H
