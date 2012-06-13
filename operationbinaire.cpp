#include "operationbinaire.h"

OperationBinaire::OperationBinaire(Constante& pa, Constante& pb, int pModeConstante, int pModeComplexes) :  Operation(pModeConstante, pModeComplexes)
{
    a = &pa;
    b = &pb;
}
