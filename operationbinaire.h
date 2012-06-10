#ifndef OPERATIONBINAIRE_H
#define OPERATIONBINAIRE_H

#include "complexe.h"
#include "rationnel.h"
#include "expression.h"

class OperationBinaire
{
    protected:
        Constante* a;
        Constante* b;
    public:
        virtual Constante* getValue() const = 0;
        OperationBinaire();
};

Constante& operator+(const Rationnel& a, const Rationnel& b);
Constante& operator+(const Complexe& a, const Complexe& b);
Constante& operator+(const Complexe& a, const Rationnel& b);
Constante& operator+(const Rationnel& ra, const Complexe& cb);
Constante& operator+(const Expression& e1, const Expression& e2);
Constante& operator+(const Expression& e1, const Rationnel& r);
Constante& operator+(const Expression& e1, const Complexe& c);
Constante& operator+(const Rationnel& r, const Expression& e1);
Constante& operator+(const Complexe& c, const Expression& e1);


class Addition : public OperationBinaire {
    public:
        Addition(Constante& pa, Constante& pb);
        virtual Constante* getValue() const;
};

#endif // OPERATIONBINAIRE_H
