#include "typeconstanteexception.h"

TypeConstanteException::TypeConstanteException(const QString& s) : CalculatriceException(s)
{
    mLogSys->addMessage("Exception de TypeConstante levée : " + s, 5);
}
