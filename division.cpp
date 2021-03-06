#include "operationbinaire.h"

#include "divexception.h"

Division::Division(Constante& pa, Constante& pb, int pModeConstante, int pModeComplexes) : OperationBinaire(pa, pb, pModeConstante, pModeComplexes)
{
}

Constante* Division::getValue() const {
    Expression* expa = dynamic_cast<Expression*>(a);
    if (expa != NULL){
        //a est une expression
        Expression* expb = dynamic_cast<Expression*>(b);
        if (expb != NULL){
            // b est une expression
            return division(*expa, *expb);
        }
        else {
            Complexe* complexeb = dynamic_cast<Complexe*>(b);
            if (complexeb != NULL) {
                // b est un complexe
                return division(*expa, *complexeb);
            }
            else {
                // b est un rationnel
                return division(*expa, *((Rationnel*)b));
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
                return division(*complexea, *expb);
            }
            else {
                Complexe* complexeb = dynamic_cast<Complexe*>(b);
                if (complexeb != NULL){
                    //b est un complexe
                    return division(*complexea, *complexeb);
                }
                else{
                    return division(*complexea, *((Rationnel*)b));
                }
           }
        }
        else{
            // a est un rationnel
            Expression* expb = dynamic_cast<Expression*>(b);
            if (expb != NULL) {
                // b est une expression
                return division(*((Rationnel*)a), *expb);
            }
            else {
                Complexe* complexeb = dynamic_cast<Complexe*>(b);
                if (complexeb != NULL){
                    //b est un complexe
                    return division(*((Rationnel*)a), *complexeb);
                }
                else{
                    return division(*((Rationnel*)a), *((Rationnel*)b));
                }
           }
        }
    }
}

Constante* Division::division(const Rationnel& a, const Rationnel& b) const {
    Constante* retour;

    if(b.getNum() == 0) {
        throw DivException("division par z�ro");
    }
    switch(mModeConstante) {
        case CalculatricePolonaise::MODE_ENTIER:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {

                retour = new Rationnel((a.getNum()*b.getDen())/( a.getDen() * b.getNum()));
            }
            else {

                retour = new Complexe(Rationnel((a.getNum()*b.getDen())/( a.getDen() * b.getNum())));
            }
            break;
        case CalculatricePolonaise::MODE_RATIONNEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                retour = new Rationnel(a.getNum()*b.getDen(), a.getDen() * b.getNum());
            }
            else {
                retour = new Complexe(Rationnel(a.getNum()*b.getDen(), a.getDen() * b.getNum()));
            }
            break;
        case CalculatricePolonaise::MODE_REEL:
            retour = new Complexe(((float)a.getNum()/(float)a.getDen()) / ((float)b.getNum()/(float)b.getDen()));
            break;
        default:
            retour = 0;
            break;
    }
    return retour;
}

Constante* Division::division(const Complexe& c1, const Complexe& c2) const {
    Constante* retour;
    if(c2.isFloat()){
        if(c2.getRe() == 0) throw DivException("division par z�ro");
    }else{
        if(c2.getReRationnel().getNum() == 0) throw DivException("division par z�ro");
    }
    switch(mModeConstante) {
        case CalculatricePolonaise::MODE_ENTIER:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c1.isFloat()) {
                    if (c2.isFloat()) {
                        retour = new Rationnel(c1.getRe() / c2.getRe());
                    }
                    else {
                        retour = new Rationnel(c1.getRe() / (c2.getReRationnel().getNum()/c2.getReRationnel().getDen()));
                    }
                }
                else {
                    if (c2.isFloat()) {
                        retour = new Rationnel((c1.getReRationnel().getNum()/c1.getReRationnel().getDen()) / c2.getRe());
                    }
                    else {
                        retour = new Rationnel((((float)c1.getReRationnel().getNum())/((float)c1.getReRationnel().getDen())) / (((float)c2.getReRationnel().getNum())/((float)c2.getReRationnel().getDen())));
                    }
                }

            }
            else {
                if (c1.isFloat()) {
                    if (c2.isFloat()) {
                        retour = new Complexe(Rationnel(c1.getRe() / c2.getRe() - c1.getIm()/c2.getIm()), Rationnel(c1.getRe() / c2.getIm() + c2.getRe() / c1.getIm()));
                    }
                    else {
                        retour = new Complexe(Rationnel(c1.getRe() / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()) - c1.getIm() / ((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen())),
                                              Rationnel(c1.getRe() / ((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen()) + c1.getIm() / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen())));
                    }
                }
                else {
                    if (c2.isFloat()) {
                        retour = new Complexe(Rationnel(((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()) * c2.getRe() - ((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen()) / c2.getIm()),
                                              Rationnel(((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()) / c2.getIm() + ((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen()) / c2.getRe()));
                    }
                    else {
                        retour = new Complexe(Rationnel(((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()) / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()) - ((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen()) / ((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen())),
                                              Rationnel(((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()) / ((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen()) + ((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen()) / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen())));
                    }
                }
            }
            break;
        case CalculatricePolonaise::MODE_RATIONNEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c1.isFloat()) {
                    if (c2.isFloat()) {
                        retour = new Rationnel((c1.getRe() / c2.getRe())*1000000, 1000000);
                    }
                    else {
                        Rationnel r(c1.getRe()*1000000,1000000);
                        retour = new Rationnel(r.getNum() / c2.getReRationnel().getNum(), r.getDen()/c2.getReRationnel().getDen());
                    }
                }
                else {
                    if (c2.isFloat()) {
                        Rationnel r(c2.getRe()*1000000,1000000);
                        retour = new Rationnel(r.getNum() / c1.getReRationnel().getNum(), r.getDen()/c1.getReRationnel().getDen());
                    }
                    else {
                        retour = new Rationnel(c2.getReRationnel().getNum() / c1.getReRationnel().getNum(), c1.getReRationnel().getDen()/c2.getReRationnel().getDen());
                    }
                }

            }
            else {
                if (c1.isFloat()) {
                    if (c2.isFloat()) {
                        retour =  new Complexe(Rationnel((c1.getRe()/c2.getRe() - c1.getIm() / c2.getIm())*1000000,1000000), Rationnel((c1.getRe()/c2.getIm() + c1.getIm() / c2.getRe())*1000000,1000000));
                    }
                    else {
                        retour = new  Complexe (Rationnel((c1.getRe()/((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()) - ((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen()) / c1.getIm())*1000000,1000000),
                                   Rationnel((c1.getRe()/((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen() + c1.getIm()) / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()))*1000000,1000000));
                    }
                }
                else {
                    if (c2.isFloat()) {
                        retour = new Complexe(Rationnel((((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen()) / c2.getIm() - c2.getRe()/((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()))*1000000,1000000),
                                   Rationnel((c2.getRe()/((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen()) + c2.getIm() / ((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()))*1000000,1000000));
                    }
                    else {
                        retour = new  Complexe(Rationnel((((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen())/((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()) - ((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen()) / ((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen()))*1000000,1000000),
                                                Rationnel((((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen())/((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen()) + ((float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen()) / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()))*1000000,1000000));
                    }
                }
            }
            break;
        case CalculatricePolonaise::MODE_REEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c1.isFloat()) {
                    if (c2.isFloat()) {
                        retour = new Complexe(c1.getRe() / c2.getRe());
                    }
                    else {
                        retour = new Complexe(c1.getRe() / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()));
                    }
                }
                else {
                    if (c2.isFloat()) {
                        retour = new Complexe(((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()) / c2.getRe());
                    }
                    else {
                        retour = new Complexe(((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()) / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()));
                    }
                }

            }
            else {
                if (c1.isFloat()) {
                    if (c2.isFloat()) {
                        retour = new Complexe(c1.getRe() / c2.getRe() - c1.getIm() / c2.getIm(), c1.getRe() / c2.getIm() + c1.getIm() / c2.getRe());
                    }
                    else {
                        retour = new Complexe(c1.getRe() / ((float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen()) - c1.getIm() / ((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen()), c1.getRe() / ((float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen()) + c1.getIm() /(float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen());
                    }
                }
                else {
                    if (c2.isFloat()) {
                        retour = new Complexe((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen() / c2.getRe() - (float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen() / c2.getIm(), (float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen() / c2.getIm() + (float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen() / c2.getRe());
                    }
                    else {
                        retour = new Complexe(((float)c1.getReRationnel().getNum()/(float)c1.getReRationnel().getDen()) - (float)c2.getReRationnel().getNum()/(float)c2.getReRationnel().getDen(), (float)c1.getImRationnel().getNum()/(float)c1.getImRationnel().getDen() - (float)c2.getImRationnel().getNum()/(float)c2.getImRationnel().getDen());
                    }
                }
            }
            break;
        default:
            break;
    }

    return retour;
}

Constante* Division::division(const Complexe& a, const Rationnel& b) const {
    const Complexe& r(b);
    return division(a,r);
}

Constante* Division::division(const Rationnel& ra, const Complexe& cb) const {

    return division(cb, ra);
}

Constante* Division::division(const Expression& e1, const Expression& e2) const {
    return new Expression(e1.getExp() + " " + e2.getExp() + " /");
}

Constante* Division::division(const Expression& e1, const Rationnel& r) const {
    return new Expression(e1.getExp() + " " + r.toString() + " /");
}

Constante* Division::division(const Expression& e1, const Complexe& c) const {
    return new Expression(e1.getExp() + " " + c.toString() + " /");
}

Constante* Division::division(const Rationnel& r, const Expression& e1) const {
    return new Expression(r.toString() + " " + e1.getExp() + " /");
}

Constante* Division::division(const Complexe& c, const Expression& e1) const {
    return new Expression(c.toString() + " " + e1.getExp() + " /");
}
