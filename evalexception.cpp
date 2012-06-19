#include "evalexception.h"

EvalException::EvalException(const QString& s) : CalculatriceException(s)
{
    mLogSys->addMessage("Exception d'Eval lev�e : " + s, 5);
}
