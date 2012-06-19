#include "trigoexception.h"

TrigoException::TrigoException(const QString& s) : CalculatriceException(s)
{
    mLogSys->addMessage("Exception de trigonom�trie lev�e : " + s, 5);
}
