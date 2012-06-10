#include "complexe.h"

Complexe::Complexe(float pRe, float pIm) : mRe(pRe),mIm(pIm),nbChiffresApresVirgule(0),mDollarEntre(pIm != 0)
{
}

void Complexe::addChiffre(int chiffre){
    if(!mDollarEntre){
        if(nbChiffresApresVirgule == 0){
            mRe*=10;
            mRe+=chiffre;
        }
        else{
            mRe+=chiffre * pow(double(10),-nbChiffresApresVirgule);
            nbChiffresApresVirgule++;
        }
    }
    else{
        if(nbChiffresApresVirgule == 0){
            mIm*=10;
            mIm+=chiffre;
        }
        else{
            mIm+=chiffre * pow(double(10),-nbChiffresApresVirgule);
            nbChiffresApresVirgule++;
        }
    }
}

const QString Complexe::toString() const {
    QString s = QString::number(mRe);
    if (mDollarEntre) {
        s += "$" + QString::number(mIm);
    }
    return s;
}
