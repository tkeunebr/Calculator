#ifndef EVALEXCEPTION_H
#define EVALEXCEPTION_H

#include "calculatriceexception.h"
/**
 * Classe d'Exception heritee de CalculatriceException. Levee quand on rencontre une erreur dans la syntaxe d'une expression
 */
class EvalException : public CalculatriceException
{
    public:
        EvalException(const QString& s = "") throw();
};

#endif // EVALEXCEPTION_H
