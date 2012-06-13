#ifndef OPERATION_H
#define OPERATION_H

#include "complexe.h"
#include "rationnel.h"
#include "expression.h"

class Operation
{
    protected:
        int mModeConstante;
        int mModeComplexes;
    public:
        Operation(int pModeConstante, int pModeComplexes);
        virtual Constante* getValue() const = 0;
};

#endif // OPERATION_H
