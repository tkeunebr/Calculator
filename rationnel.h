#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"

class Rationnel : public Constante
{
    public:
        Rationnel(int pNum=0, int pDen=1);

        // Getters
        int getNum() const { return mNum; }
        int getDen() const { return mDen; }

        // Setters
        void setDen(int pDen);
        virtual void setSlashEntre(bool slashEntre = true){
            mSlashEntre = slashEntre;
            mDen = 0;
        }
        virtual void setDollarEntre(bool dollarEntre = true) { }
        virtual void setVirguleEntree(bool virguleEntree = true) { }
        virtual bool isDollarEntre() const { return false; }

        virtual void addChiffre(int chiffre);

        virtual const QString toString() const;

        void simplifier();
    private:
        int mNum;
        int mDen;
        bool mSlashEntre;

        // Private methods
        int pgcd(int a, int b);
};

#endif // RATIONNEL_H
