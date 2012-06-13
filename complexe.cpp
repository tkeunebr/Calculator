#include "complexe.h"

Complexe::Complexe(float pRe, float pIm) : mRe(pRe),mIm(pIm),nbChiffresApresVirgule(0),mDollarEntre(pIm != 0), mReRationnel(), mImRationnel(), mIsFloat(true)
{
}

Complexe::Complexe(Rationnel& pRe, Rationnel& pIm) : mRe(0), mIm(0), nbChiffresApresVirgule(0),mDollarEntre(pIm.getNum() != 0), mReRationnel(pRe), mImRationnel(pIm), mIsFloat(false)
{
}

Complexe::Complexe(const Rationnel& pRe, const Rationnel& pIm) : mRe(0), mIm(0), nbChiffresApresVirgule(0),mDollarEntre(pIm.getNum() != 0), mReRationnel(pRe), mImRationnel(pIm), mIsFloat(false)
{
}

void Complexe::setSlashEntre(bool slashEntre) {
    if (!mIsFloat) {
        if (!mDollarEntre) {
            mReRationnel.setSlashEntre(slashEntre);
        }
        else {
            mImRationnel.setSlashEntre(slashEntre);
        }
    }
}

void Complexe::addChiffre(int chiffre){
    if (mIsFloat) {
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
    else {
        if (!mDollarEntre) {
            mReRationnel.addChiffre(chiffre);
        }
        else {
            mImRationnel.addChiffre(chiffre);
        }
    }
}

const QString Complexe::toString() const {
    QString s;
    if (mIsFloat) {
         s = QString::number(mRe);
        if (mDollarEntre) {
            s += "$" + QString::number(mIm);
        }
    }
    else {
        s = mReRationnel.toString();
        if (mDollarEntre) {
            s += "$" + mImRationnel.toString();
        }
    }
    return s;
}
