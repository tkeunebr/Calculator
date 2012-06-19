#ifndef OPERATION_H
#define OPERATION_H

#include "complexe.h"
#include "rationnel.h"
#include "expression.h"
/**
 * Classe abstraite generique de laquelle heritent les operations unaires et binaires.
 Declare des variables correspondant aux modes de la calculatrice ainsi que la methode getValue virtuelle pure permettant d'obtenir le resultat de l'operation sous forme d'une constante.
 */
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
