#include "operationunaire.h"

OperationUnaire::OperationUnaire()
{
}

Eval::Eval(Constante &pc) : OperationUnaire()
{
    c = &pc;
}

Constante* Eval::getValue() const {
    Expression* exp = dynamic_cast<Expression*>(c);
    if (exp != NULL){
        //a est une expression
        //QString exp = expa->getExp();

    }
    return c;
}
