#ifndef OPERATIONBINAIRE_H
#define OPERATIONBINAIRE_H

#include "operation.h"
#include "calculatricepolonaise.h"
#include "calculatriceexception.h"

class OperationBinaire : public Operation
{
    protected:
        Constante* a;
        Constante* b;
    public:
        OperationBinaire(Constante& pa, Constante& pb, int pModeConstante, int pModeComplexes);
        virtual Constante* getValue() const = 0;
};


class Addition : public OperationBinaire {
    public:
        Addition(Constante& pa, Constante& pb, int pModeConstante, int pModeComplexes);
        virtual Constante* getValue() const;
    private:
        Constante* addition(const Rationnel& a, const Rationnel& b) const;
        Constante* addition(const Complexe& a, const Complexe& b) const;
        Constante* addition(const Complexe& a, const Rationnel& b) const;
        Constante* addition(const Rationnel& ra, const Complexe& cb) const;
        Constante* addition(const Expression& e1, const Expression& e2) const;
        Constante* addition(const Expression& e1, const Rationnel& r) const;
        Constante* addition(const Expression& e1, const Complexe& c) const;
        Constante* addition(const Rationnel& r, const Expression& e1) const;
        Constante* addition(const Complexe& c, const Expression& e1) const;

};

#endif // OPERATIONBINAIRE_H
