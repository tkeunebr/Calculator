#ifndef OPERATIONUNAIRE_H
#define OPERATIONUNAIRE_H

#include <QStack>
#include <cmath>

#include "operation.h"
#include "calculatricepolonaise.h"
#include "typeconstanteexception.h"

class OperationUnaire : public Operation
{
    protected:
        Constante* c;
        int mModeDegres;

    public:
        OperationUnaire(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const = 0;
};

class Eval : public OperationUnaire
{
    public:
        Eval(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
};

class Cos : public OperationUnaire
{
    public:
        Cos(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* cosinus(const Complexe& c) const;
        Constante* cosinus(const Rationnel &r) const;
};

class Sin : public OperationUnaire
{
    public:
        Sin(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* sinus(const Complexe& c) const;
        Constante* sinus(const Rationnel &r) const;
};

class Tan : public OperationUnaire
{
    public:
        Tan(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* tangente(const Complexe& c) const;
        Constante* tangente(const Rationnel &r) const;
        void checkException(float f, bool deg = false) const;
        void checkException(const Rationnel& r, bool deg = false) const;
};

class Cosh : public OperationUnaire
{
    public:
        Cosh(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* cosinush(const Complexe& c) const;
        Constante* cosinush(const Rationnel &r) const;
};

class Sinh : public OperationUnaire
{
    public:
        Sinh(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* sinush(const Complexe& c) const;
        Constante* sinush(const Rationnel &r) const;
};

class Tanh : public OperationUnaire
{
    public:
        Tanh(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* tangenteh(const Complexe& c) const;
        Constante* tangenteh(const Rationnel &r) const;
};

#endif // OPERATIONUNAIRE_H
