#include "divexception.h"

DivException::DivException(const QString& s) : CalculatriceException(s)
{
   mLogSys->addMessage("Exception de DivException levée : " + s, 5);
}
