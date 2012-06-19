#include "trigoexception.h"

TrigoException::TrigoException(const QString& s) : CalculatriceException(s)
{
    mLogSys->addMessage("Exception de trigonométrie levée : " + s, 5);
}
