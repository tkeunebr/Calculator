#ifndef COMPLEXEFACTORY_H
#define COMPLEXEFACTORY_H

#include "constantefactory.h"
#include "complexe.h"

/**
 * Classe implementant le design pattern Factory. Permet de creer des constantes du bon type (ici Complexe de reels) en fonction du mode,
 * a l'aide de la methode newInstance
 */


class ComplexeReelFactory : public ConstanteFactory
{
    public:
        virtual Constante* newInstance();
};

#endif // COMPLEXEFACTORY_H
