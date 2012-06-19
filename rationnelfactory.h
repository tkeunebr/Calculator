#ifndef RATIONNELFACTORY_H
#define RATIONNELFACTORY_H

#include "constantefactory.h"
#include "rationnel.h"


/**
 * Classe implementant le design pattern Factory, heritee de ConstanteFactory. Permet de creer des Rationnels a l'aide de la methode newInstance definie.
 */


class RationnelFactory : public ConstanteFactory
{
    public:
        virtual Constante* newInstance();
};

#endif // RATIONNELFACTORY_H
