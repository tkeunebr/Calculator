#ifndef TRIGOEXCEPTION_H
#define TRIGOEXCEPTION_H

#include "calculatriceexception.h"

class TrigoException : public CalculatriceException
{
public:
     TrigoException(const QString& s = "") throw();
};

#endif // TRIGOEXCEPTION_H
