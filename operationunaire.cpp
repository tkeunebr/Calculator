#include "operationunaire.h"

OperationUnaire::OperationUnaire(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres) : Operation(pModeConstante, pModeComplexes), mModeDegres(pModeDegres)
{
    c = &pc;
}
