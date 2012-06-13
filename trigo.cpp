#include "operationunaire.h"
#include "trigoexception.h"

#include <QTextStream>

extern QTextStream cout;

const float PI = 3.14159265;

Cos::Cos(Constante &pc, int pModeConstante, int pModeComplexes, int pModeDegres) : OperationUnaire(pc, pModeConstante, pModeComplexes, pModeDegres)
{
}

Constante* Cos::getValue() const {
    Complexe* complexe = dynamic_cast<Complexe*>(c);
    if (complexe != 0) {
        // c est un complexe
        return cosinus(*complexe);
    }
    else {
        Rationnel* rat = dynamic_cast<Rationnel*>(c);
        if (rat != 0) {
            // c est un rationnel
            return cosinus(*rat);
        }
        else {
            // Ni un rationnel, ni un complexe => Expression
            throw TypeConstanteException("Opération impossible : Cosinus sur expression");
        }
    }
}

Constante* Cos::cosinus(const Complexe& c) const {
    Constante* retour;
    switch(mModeConstante) {
        case CalculatricePolonaise::MODE_ENTIER:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(cosf(c.getRe()*PI/180));
                    else retour = new Rationnel(cosf(c.getRe()));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(cosf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                    else
                        retour = new Rationnel(cosf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
                }

            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(cosf(c.getRe()*PI/180)));
                    else
                        retour = new Complexe(Rationnel(cosf(c.getRe())));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(cosf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180)));
                    else
                        retour = new Complexe(Rationnel(cosf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())));
                }
            }
            break;
        case CalculatricePolonaise::MODE_RATIONNEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((cosf(c.getRe()*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((cosf(c.getRe()))*1000000, 1000000);
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((cosf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((cosf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000);
                }
            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((cosf(c.getRe()*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((cosf(c.getRe()))*1000000, 1000000));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((cosf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((cosf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000));
                }
            }
            break;
        case CalculatricePolonaise::MODE_REEL:
            if (c.isFloat()) {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(cosf(c.getRe()*PI/180));
                else retour = new Complexe(cosf(c.getRe()));
            }
            else {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(cosf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                else
                    retour = new Complexe(cosf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
            }
            break;
        default:
            break;
    }

    return retour;
}

Constante* Cos::cosinus(const Rationnel &r) const {
    const Complexe& complexe(r);
    return cosinus(complexe);
}

Sin::Sin(Constante &pc, int pModeConstante, int pModeComplexes, int pModeDegres) : OperationUnaire(pc, pModeConstante, pModeComplexes, pModeDegres)
{
}

Constante* Sin::getValue() const {
    Complexe* complexe = dynamic_cast<Complexe*>(c);
    if (complexe != 0) {
        // c est un complexe
        return sinus(*complexe);
    }
    else {
        Rationnel* rat = dynamic_cast<Rationnel*>(c);
        if (rat != 0) {
            // c est un rationnel
            return sinus(*rat);
        }
        else {
            // Ni un rationnel, ni un complexe => Expression
            throw TypeConstanteException("Opération impossible : sinus sur expression");
        }
    }
}

Constante* Sin::sinus(const Complexe& c) const {
    Constante* retour;
    switch(mModeConstante) {
        case CalculatricePolonaise::MODE_ENTIER:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(sinf(c.getRe()*PI/180));
                    else retour = new Rationnel(sinf(c.getRe()));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(sinf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                    else
                        retour = new Rationnel(sinf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
                }

            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(sinf(c.getRe()*PI/180)));
                    else
                        retour = new Complexe(Rationnel(sinf(c.getRe())));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(sinf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180)));
                    else
                        retour = new Complexe(Rationnel(sinf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())));
                }
            }
            break;
        case CalculatricePolonaise::MODE_RATIONNEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((sinf(c.getRe()*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((sinf(c.getRe()))*1000000, 1000000);
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((sinf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((sinf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000);
                }
            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((sinf(c.getRe()*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((sinf(c.getRe()))*1000000, 1000000));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((sinf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((sinf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000));
                }
            }
            break;
        case CalculatricePolonaise::MODE_REEL:
            if (c.isFloat()) {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(sinf(c.getRe()*PI/180));
                else retour = new Complexe(sinf(c.getRe()));
            }
            else {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(sinf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                else
                    retour = new Complexe(sinf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
            }
            break;
        default:
            break;
    }

    return retour;
}

Constante* Sin::sinus(const Rationnel &r) const {
    const Complexe& complexe(r);
    return sinus(complexe);
}

Tan::Tan(Constante &pc, int pModeConstante, int pModeComplexes, int pModeDegres) : OperationUnaire(pc, pModeConstante, pModeComplexes, pModeDegres)
{
}

Constante* Tan::getValue() const {
    Complexe* complexe = dynamic_cast<Complexe*>(c);
    if (complexe != 0) {
        // c est un complexe
        return tangente(*complexe);
    }
    else {
        Rationnel* rat = dynamic_cast<Rationnel*>(c);
        if (rat != 0) {
            // c est un rationnel
            return tangente(*rat);
        }
        else {
            // Ni un rationnel, ni un complexe => Expression
            throw TypeConstanteException("Opération impossible : tan sur expression");
        }
    }
}

Constante* Tan::tangente(const Complexe& c) const {
    Constante* retour;
    switch(mModeConstante) {
        case CalculatricePolonaise::MODE_ENTIER:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    checkException(c.getRe(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(tanf(c.getRe()*PI/180));
                    else retour = new Rationnel(tanf(c.getRe()));
                }
                else {
                    checkException(c.getReRationnel(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(tanf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                    else
                        retour = new Rationnel(tanf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
                }

            }
            else {
                if (c.isFloat()) {
                    checkException(c.getRe(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(tanf(c.getRe()*PI/180)));
                    else
                        retour = new Complexe(Rationnel(tanf(c.getRe())));
                }
                else {
                    checkException(c.getReRationnel(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(tanf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180)));
                    else
                        retour = new Complexe(Rationnel(tanf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())));
                }
            }
            break;
        case CalculatricePolonaise::MODE_RATIONNEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    checkException(c.getRe(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((tanf(c.getRe()*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((tanf(c.getRe()))*1000000, 1000000);
                }
                else {
                    checkException(c.getReRationnel(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((tanf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((tanf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000);
                }
            }
            else {
                if (c.isFloat()) {
                    checkException(c.getRe(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((tanf(c.getRe()*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((tanf(c.getRe()))*1000000, 1000000));
                }
                else {
                    checkException(c.getReRationnel(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((tanf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((tanf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000));
                }
            }
            break;
        case CalculatricePolonaise::MODE_REEL:
            if (c.isFloat()) {
                checkException(c.getRe(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(tanf(c.getRe()*PI/180));
                else retour = new Complexe(tanf(c.getRe()));
            }
            else {
                checkException(c.getReRationnel(), mModeDegres == CalculatricePolonaise::MODE_DEGRE);
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(tanf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                else
                    retour = new Complexe(tanf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
            }
            break;
        default:
            break;
    }

    return retour;
}

Constante* Tan::tangente(const Rationnel &r) const {
    const Complexe& complexe(r);
    return tangente(complexe);
}

void Tan::checkException(float f, bool deg) const {
    float diff = f - floor(f);
    if (diff == 0) {
        if ((deg && ((int)f)%180 == 90) || (!deg && ((int)(f*PI/180))%180 == PI/2)) {
            throw TrigoException("Impossible d'appliquer la tangente à " + QString::number(f));
        }
    }
}

void Tan::checkException(const Rationnel &r, bool deg) const {
    float div = (float)r.getNum()/(float)r.getDen();
    checkException(div, deg);
}

Cosh::Cosh(Constante &pc, int pModeConstante, int pModeComplexes, int pModeDegres) : OperationUnaire(pc, pModeConstante, pModeComplexes, pModeDegres)
{
}

Constante* Cosh::getValue() const {
    Complexe* complexe = dynamic_cast<Complexe*>(c);
    if (complexe != 0) {
        // c est un complexe
        return cosinush(*complexe);
    }
    else {
        Rationnel* rat = dynamic_cast<Rationnel*>(c);
        if (rat != 0) {
            // c est un rationnel
            return cosinush(*rat);
        }
        else {
            // Ni un rationnel, ni un complexe => Expression
            throw TypeConstanteException("Opération impossible : cosh sur expression");
        }
    }
}

Constante* Cosh::cosinush(const Complexe& c) const {
    Constante* retour;
    switch(mModeConstante) {
        case CalculatricePolonaise::MODE_ENTIER:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(coshf(c.getRe()*PI/180));
                    else retour = new Rationnel(coshf(c.getRe()));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(coshf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                    else
                        retour = new Rationnel(coshf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
                }

            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(coshf(c.getRe()*PI/180)));
                    else
                        retour = new Complexe(Rationnel(coshf(c.getRe())));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(coshf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180)));
                    else
                        retour = new Complexe(Rationnel(coshf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())));
                }
            }
            break;
        case CalculatricePolonaise::MODE_RATIONNEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((coshf(c.getRe()*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((coshf(c.getRe()))*1000000, 1000000);
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((coshf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((coshf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000);
                }
            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((coshf(c.getRe()*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((coshf(c.getRe()))*1000000, 1000000));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((coshf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((coshf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000));
                }
            }
            break;
        case CalculatricePolonaise::MODE_REEL:
            if (c.isFloat()) {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(coshf(c.getRe()*PI/180));
                else retour = new Complexe(coshf(c.getRe()));
            }
            else {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(coshf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                else
                    retour = new Complexe(coshf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
            }
            break;
        default:
            break;
    }

    return retour;
}

Constante* Cosh::cosinush(const Rationnel &r) const {
    const Complexe& complexe(r);
    return cosinush(complexe);
}

Sinh::Sinh(Constante &pc, int pModeConstante, int pModeComplexes, int pModeDegres) : OperationUnaire(pc, pModeConstante, pModeComplexes, pModeDegres)
{
}

Constante* Sinh::getValue() const {
    Complexe* complexe = dynamic_cast<Complexe*>(c);
    if (complexe != 0) {
        // c est un complexe
        return sinush(*complexe);
    }
    else {
        Rationnel* rat = dynamic_cast<Rationnel*>(c);
        if (rat != 0) {
            // c est un rationnel
            return sinush(*rat);
        }
        else {
            // Ni un rationnel, ni un complexe => Expression
            throw TypeConstanteException("Opération impossible : sinh sur expression");
        }
    }
}

Constante* Sinh::sinush(const Complexe& c) const {
    Constante* retour;
    switch(mModeConstante) {
        case CalculatricePolonaise::MODE_ENTIER:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(sinhf(c.getRe()*PI/180));
                    else retour = new Rationnel(sinhf(c.getRe()));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(sinhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                    else
                        retour = new Rationnel(sinhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
                }

            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(sinhf(c.getRe()*PI/180)));
                    else
                        retour = new Complexe(Rationnel(sinhf(c.getRe())));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(sinhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180)));
                    else
                        retour = new Complexe(Rationnel(sinhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())));
                }
            }
            break;
        case CalculatricePolonaise::MODE_RATIONNEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((sinhf(c.getRe()*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((sinhf(c.getRe()))*1000000, 1000000);
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((sinhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((sinhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000);
                }
            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((sinhf(c.getRe()*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((sinhf(c.getRe()))*1000000, 1000000));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((sinhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((sinhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000));
                }
            }
            break;
        case CalculatricePolonaise::MODE_REEL:
            if (c.isFloat()) {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(sinhf(c.getRe()*PI/180));
                else retour = new Complexe(sinhf(c.getRe()));
            }
            else {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(sinhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                else
                    retour = new Complexe(sinhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
            }
            break;
        default:
            break;
    }

    return retour;
}

Constante* Sinh::sinush(const Rationnel &r) const {
    const Complexe& complexe(r);
    return sinush(complexe);
}

Tanh::Tanh(Constante &pc, int pModeConstante, int pModeComplexes, int pModeDegres) : OperationUnaire(pc, pModeConstante, pModeComplexes, pModeDegres)
{
}

Constante* Tanh::getValue() const {
    Complexe* complexe = dynamic_cast<Complexe*>(c);
    if (complexe != 0) {
        // c est un complexe
        return tangenteh(*complexe);
    }
    else {
        Rationnel* rat = dynamic_cast<Rationnel*>(c);
        if (rat != 0) {
            // c est un rationnel
            return tangenteh(*rat);
        }
        else {
            // Ni un rationnel, ni un complexe => Expression
            throw TypeConstanteException("Opération impossible : tanh sur expression");
        }
    }
}

Constante* Tanh::tangenteh(const Complexe& c) const {
    Constante* retour;
    switch(mModeConstante) {
        case CalculatricePolonaise::MODE_ENTIER:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(tanhf(c.getRe()*PI/180));
                    else retour = new Rationnel(tanhf(c.getRe()));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel(tanhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                    else
                        retour = new Rationnel(tanhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
                }

            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(tanhf(c.getRe()*PI/180)));
                    else
                        retour = new Complexe(Rationnel(tanhf(c.getRe())));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel(tanhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180)));
                    else
                        retour = new Complexe(Rationnel(tanhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())));
                }
            }
            break;
        case CalculatricePolonaise::MODE_RATIONNEL:
            if (mModeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((tanhf(c.getRe()*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((tanhf(c.getRe()))*1000000, 1000000);
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Rationnel((tanhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000);
                    else
                        retour = new Rationnel((tanhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000);
                }
            }
            else {
                if (c.isFloat()) {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((tanhf(c.getRe()*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((tanhf(c.getRe()))*1000000, 1000000));
                }
                else {
                    if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                        retour = new Complexe(Rationnel((tanhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180))*1000000, 1000000));
                    else
                        retour = new Complexe(Rationnel((tanhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()))*1000000, 1000000));
                }
            }
            break;
        case CalculatricePolonaise::MODE_REEL:
            if (c.isFloat()) {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(tanhf(c.getRe()*PI/180));
                else retour = new Complexe(tanhf(c.getRe()));
            }
            else {
                if (mModeDegres == CalculatricePolonaise::MODE_DEGRE)
                    retour = new Complexe(tanhf(((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen())*PI/180));
                else
                    retour = new Complexe(tanhf((float)c.getReRationnel().getNum()/(float)c.getReRationnel().getDen()));
            }
            break;
        default:
            break;
    }

    return retour;
}

Constante* Tanh::tangenteh(const Rationnel &r) const {
    const Complexe& complexe(r);
    return tangenteh(complexe);
}


