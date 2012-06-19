#ifndef OPERATIONBINAIRE_H
#define OPERATIONBINAIRE_H

#include "operation.h"
#include "calculatricepolonaise.h"
#include "calculatriceexception.h"
/**
 * Classe definissant un operateur binaire. Herite d'Operation. Declare deux variables de type pointeur sur Constante correspondant aux deux operandes.
 * La methode getValue est redeclaree virtuelle pure et sera implementee dans des classes heritees comme Addition par exemple.
 */


class OperationBinaire : public Operation
{
    protected:
        Constante* a;
        Constante* b;
    public:
        OperationBinaire(Constante& pa, Constante& pb, int pModeConstante, int pModeComplexes);
        virtual Constante* getValue() const = 0;
};

/**
 * Classe heritee d'OperationUnaire permettant de calculer la somme de deux constantes.
 */
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
/**
 * Classe heritee d'OperationUnaire permettant de calculer la difference de deux constantes.
 */
class Soustraction : public OperationBinaire {
    public:
        Soustraction(Constante& pa, Constante& pb, int pModeConstante, int pModeComplexes);
        virtual Constante* getValue() const;
    private:
        Constante* soustraction(const Rationnel& a, const Rationnel& b) const;
        Constante* soustraction(const Complexe& a, const Complexe& b) const;
        Constante* soustraction(const Complexe& a, const Rationnel& b) const;
        Constante* soustraction(const Rationnel& ra, const Complexe& cb) const;
        Constante* soustraction(const Expression& e1, const Expression& e2) const;
        Constante* soustraction(const Expression& e1, const Rationnel& r) const;
        Constante* soustraction(const Expression& e1, const Complexe& c) const;
        Constante* soustraction(const Rationnel& r, const Expression& e1) const;
        Constante* soustraction(const Complexe& c, const Expression& e1) const;

};

/**
 * Classe heritee d'OperationUnaire permettant de calculer le produit de deux constantes.
 */

class Multiplication : public OperationBinaire {
    public:
        Multiplication(Constante& pa, Constante& pb, int pModeConstante, int pModeComplexes);
        virtual Constante* getValue() const;
    private:
        Constante* multiplication(const Rationnel& a, const Rationnel& b) const;
        Constante* multiplication(const Complexe& a, const Complexe& b) const;
        Constante* multiplication(const Complexe& a, const Rationnel& b) const;
        Constante* multiplication(const Rationnel& ra, const Complexe& cb) const;
        Constante* multiplication(const Expression& e1, const Expression& e2) const;
        Constante* multiplication(const Expression& e1, const Rationnel& r) const;
        Constante* multiplication(const Expression& e1, const Complexe& c) const;
        Constante* multiplication(const Rationnel& r, const Expression& e1) const;
        Constante* multiplication(const Complexe& c, const Expression& e1) const;

};

/**
 * Classe heritee d'OperationUnaire permettant de calculer le quotient de deux constantes.
 */

class Division : public OperationBinaire {
    public:
        Division(Constante& pa, Constante& pb, int pModeConstante, int pModeComplexes);
        virtual Constante* getValue() const;
    private:
        Constante* division(const Rationnel& a, const Rationnel& b) const;
        Constante* division(const Complexe& a, const Complexe& b) const;
        Constante* division(const Complexe& a, const Rationnel& b) const;
        Constante* division(const Rationnel& ra, const Complexe& cb) const;
        Constante* division(const Expression& e1, const Expression& e2) const;
        Constante* division(const Expression& e1, const Rationnel& r) const;
        Constante* division(const Expression& e1, const Complexe& c) const;
        Constante* division(const Rationnel& r, const Expression& e1) const;
        Constante* division(const Complexe& c, const Expression& e1) const;

};

#endif // OPERATIONBINAIRE_H
