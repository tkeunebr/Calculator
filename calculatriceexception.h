#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

#include <QString>
#include "logsystem.h"

/**
 * Classe d'Exception heritee de std::exception. Levee quand on rencontre une exception standard. On utilisera plus souvent des classes d'exception heritees
 *  de CalculatriceException
 */


class CalculatriceException : public std::exception
{
    protected:
        QString info;
        LogSystem* mLogSys;

    public:
        CalculatriceException(const QString& s = "") throw();
        const char* what() const throw();
        const QString& getErrorMessage() const { return info; }
};

#endif // CALCULATRICEEXCEPTION_H
