#include "rationnel.h"

Rationnel::Rationnel(int pNum, int pDen) : mNum(pNum), mSlashEntre(pDen!=1)
{
    setDen(pDen);
    simplifier();
}

void Rationnel::setDen(int pDen){
    if(pDen!=0) mDen = pDen;
    else mDen = 1;
}

const QString Rationnel::toString() const {
    QString s = QString::number(mNum);
    if (mDen != 1) {
        s += "/" + QString::number(mDen);
    }
    return s;
}

void Rationnel::addChiffre(int chiffre){
    if(!mSlashEntre){
        mNum*=10;
        mNum+=chiffre;
    }
    else{
        mDen*=10;
        mDen+=chiffre;
    }
    simplifier();
}

void Rationnel::simplifier(){
    int p = pgcd(mNum, mDen);
    mNum/=p;
    mDen/=p;
}

// Private methods

int Rationnel::pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}
