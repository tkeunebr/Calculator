#ifndef TYPECONSTANTEEXCEPTION_H
#define TYPECONSTANTEEXCEPTION_H

#include "calculatriceexception.h"

class TypeConstanteException : public CalculatriceException
{
    public:
        TypeConstanteException(const QString& s = "") throw();
};

#endif // TYPECONSTANTEEXCEPTION_H
