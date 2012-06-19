#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include "constante.h"
/**
 * Classe implementant le design pattern Factory. Permet de creer des constantes du bon type en fonction du mode,
 * a l'aide de la methode newInstance, définie dans les classes heritees.
 */
class ConstanteFactory
{
    public:
        virtual Constante* newInstance() = 0;
};

#endif // CONSTANTEFACTORY_H
