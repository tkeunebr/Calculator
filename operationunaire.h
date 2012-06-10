#ifndef OPERATIONUNAIRE_H
#define OPERATIONUNAIRE_H

#include <QStack>

#include "complexe.h"
#include "rationnel.h"
#include "expression.h"

class OperationUnaire
{
    protected:
        Constante* c;
    public:
        virtual Constante* getValue() const = 0;
        OperationUnaire();
};

class Eval : public OperationUnaire
{
    public:
        Eval(Constante& pc);
        virtual Constante* getValue() const;
};

#endif // OPERATIONUNAIRE_H
