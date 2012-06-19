#ifndef DIVEXCEPTION_H
#define DIVEXCEPTION_H

#include "calculatriceexception.h"
/**
 * Classe d'Exception heritee de CalculatriceException. Levee quand on rencontre une exception de division par 0.
 */
class DivException : public CalculatriceException
{
    public:
        DivException(const QString& s = "") throw();
};

#endif // DIVEXCEPTION_H
