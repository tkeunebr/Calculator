#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

#include <QString>

class CalculatriceException : public std::exception
{
    protected:
        QString info;

    public:
        CalculatriceException(const QString& s = "") throw();
        const char* what() const throw();
        const QString& getErrorMessage() const { return info; }
};

#endif // CALCULATRICEEXCEPTION_H
