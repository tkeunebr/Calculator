#ifndef OPERATIONUNAIRE_H
#define OPERATIONUNAIRE_H

#include <QStack>
#include <cmath>

#include "operation.h"
#include "calculatricepolonaise.h"
#include "typeconstanteexception.h"

/**
 * Classe definissant un operateur unaire. Herite d'Operation. Declare une variable de type pointeur sur Constante correspondant a l'operande unique.
 * La methode getValue est redeclaree virtuelle pure et sera implementee dans des classes heritees comme Cos par exemple.
 */



class OperationUnaire : public Operation
{
    protected:
        Constante* c;
        int mModeDegres;

    public:
        OperationUnaire(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const = 0;
};

/**
 * Classe heritee d'OperationUnaire permettant l'evaluation d'une constante de type expression. La mathode getValue parcourt l'expression et l'evalue a l'aide d'une pile.
 */


class Eval : public OperationUnaire
{
    public:
        Eval(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
};

/**
 * Classe heritee d'OperationUnaire permettant de calculer le Cosinus d'une constante.
 */

class Cos : public OperationUnaire
{
    public:
        Cos(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* cosinus(const Complexe& c) const;
        Constante* cosinus(const Rationnel &r) const;
};

/**
 * Classe heritee d'OperationUnaire permettant de calculer le Sinus d'une constante.
 */

class Sin : public OperationUnaire
{
    public:
        Sin(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* sinus(const Complexe& c) const;
        Constante* sinus(const Rationnel &r) const;
};


/**
 * Classe heritee d'OperationUnaire permettant de calculer la Tangeante d'une constante.
 */
 
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


/**
 * Classe heritee d'OperationUnaire permettant de calculer le Cosinus Hyperbolique d'une constante.
 */
class Cosh : public OperationUnaire
{
    public:
        Cosh(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* cosinush(const Complexe& c) const;
        Constante* cosinush(const Rationnel &r) const;
};


/**
 * Classe heritee d'OperationUnaire permettant de calculer le Sinus Hyperbolique d'une constante.
 */
class Sinh : public OperationUnaire
{
    public:
        Sinh(Constante& pc, int pModeConstante, int pModeComplexes, int pModeDegres);
        virtual Constante* getValue() const;
    private:
        Constante* sinush(const Complexe& c) const;
        Constante* sinush(const Rationnel &r) const;
};


/**
 * Classe heritee d'OperationUnaire permettant de calculer la Tangeante Hyperbolique d'une constante.
 */
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
