#ifndef EVALEXCEPTION_H
#define EVALEXCEPTION_H

#include "calculatriceexception.h"

class EvalException : public CalculatriceException
{
    public:
        EvalException(const QString& s = "") throw();
};

#endif // EVALEXCEPTION_H
