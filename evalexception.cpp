#include "evalexception.h"

EvalException::EvalException(const QString& s) : CalculatriceException(s)
{
    mLogSys->addMessage("Exception d'Eval levée : " + s, 5);
}
