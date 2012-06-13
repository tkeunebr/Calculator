#include "calculatriceexception.h"

CalculatriceException::CalculatriceException(const QString& s) throw() : info(s)
{
}

const char* CalculatriceException::what() const throw() {
    return info.toStdString().c_str();
}
