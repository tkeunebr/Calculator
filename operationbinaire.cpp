#include "operationbinaire.h"

OperationBinaire::OperationBinaire()
{
}

Constante* Addition::getValue() const {
    Expression* expa = dynamic_cast<Expression*>(a);
    if (expa != NULL){
        //a est une expression
        Expression* expb = dynamic_cast<Expression*>(b);
        if (expb != NULL){
            // b est une expression
            return &(*expa + *expb);
        }
        else {
            Complexe* complexeb = dynamic_cast<Complexe*>(b);
            if (complexeb != NULL) {
                // b est un complexe
                return &(*expa + *complexeb);
            }
            else {
                // b est un rationnel
                return &(*expa + *((Rationnel*)b));
            }
        }
    }
    else {
        // a n'est pas une expression
        Complexe* complexea = dynamic_cast<Complexe*>(a);
        if (complexea != NULL){
            //a est un complexe
            Expression* expb = dynamic_cast<Expression*>(b);
            if (expb != NULL) {
                // b est une expression
                return &(*complexea + *expb);
            }
            else {
                Complexe* complexeb = dynamic_cast<Complexe*>(b);
                if (complexeb != NULL){
                    //b est un complexe
                    return &(*complexea + *complexeb);
                }
                else{
                    return &(*complexea + *((Rationnel*)b));
                }
           }
        }
        else{
            // a est un rationnel
            Expression* expb = dynamic_cast<Expression*>(b);
            if (expb != NULL) {
                // b est une expression
                return &(*((Rationnel*)a) + *expb);
            }
            else {
                Complexe* complexeb = dynamic_cast<Complexe*>(b);
                if (complexeb != NULL){
                    //b est un complexe
                    return &(*((Rationnel*)a) + *complexeb);
                }
                else{
                    return &(*((Rationnel*)a) + *((Rationnel*)b));
                }
           }
        }
    }
}

Addition::Addition(Constante& pa, Constante& pb) : OperationBinaire()
{
    a = &pa;
    b = &pb;
}

Constante& operator+(const Rationnel& a, const Rationnel& b){
    return *(new Rationnel(a.getNum()*b.getDen()+b.getNum()*a.getDen(), a.getDen()*b.getDen()));
}

Constante& operator+(const Complexe& c1, const Complexe& c2){
    return *(new Complexe(c1.getRe() + c2.getRe(), c1.getIm() + c2.getIm()));
}

Constante& operator+(const Complexe& a, const Rationnel& b) {
    return *(new Complexe(a.getRe()+(float)b.getNum()/(float)b.getDen(),a.getIm()));
}

Constante& operator+(const Rationnel& ra, const Complexe& cb) {
    return *(new Complexe(cb.getRe()+(float)ra.getNum()/(float)ra.getDen(),cb.getIm()));
}

Constante& operator+(const Expression& e1, const Expression& e2) {
    return *(new Expression(e1.getExp() + " " + e2.getExp() + " +"));
}

Constante& operator+(const Expression& e1, const Rationnel& r) {
    return *(new Expression(e1.getExp() + " " + r.toString() + " +"));
}

Constante& operator+(const Expression& e1, const Complexe& c) {
    return *(new Expression(e1.getExp() + " " + c.toString() + " +"));
}

Constante& operator+(const Rationnel& r, const Expression& e1) {
    return *(new Expression(r.toString() + " " + e1.getExp() + " +"));
}

Constante& operator+(const Complexe& c, const Expression& e1) {
    return *(new Expression(c.toString() + " " + e1.getExp() + " +"));
}
