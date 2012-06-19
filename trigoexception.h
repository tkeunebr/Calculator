#ifndef TRIGOEXCEPTION_H
#define TRIGOEXCEPTION_H

#include "calculatriceexception.h"

/**
 * Classe d'Exception heritee de CalculatriceException. Levee quand on rencontre une exception de trigonometrie, par
 * exemple quand on essaie de calculer la tangeante d'un angle de 90° (tangeante non definie en ce point)
 */


class TrigoException : public CalculatriceException
{
public:
     TrigoException(const QString& s = "") throw();
};

#endif // TRIGOEXCEPTION_H
