#ifndef TYPECONSTANTEEXCEPTION_H
#define TYPECONSTANTEEXCEPTION_H

#include "calculatriceexception.h"

/**
 * Classe d'Exception heritee de CalculatriceException. Levee quand on rencontre une exception de type, par exemple
 * lorsque l'on tente d'effectuer une operation specifique a un ou plusieurs types, differents de ceux des constantes depilees.
 */


class TypeConstanteException : public CalculatriceException
{
    public:
        TypeConstanteException(const QString& s = "") throw();
};

#endif // TYPECONSTANTEEXCEPTION_H
