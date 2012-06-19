#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"

/**
 * Classe definissant un rationnel et ses methodes. Herite de la classe Constante et definit les methodes declarees virtuelles pures dans celle-ci.
 * Un rationnel est compose d'un numerateur et d'un denominateur entiers. La methode simplifier permet d'obtenir une forme simple. Appelee lors de la
 * construction, elle permet d'avoir le plus souvent affaire a des formes simplifiees automatiquement.
 */


class Rationnel : public Constante
{
    public:
        explicit Rationnel(int pNum=0, int pDen=1);
        explicit Rationnel(float pNum, int pDen=1);
        explicit Rationnel(float pNum, float pDen);
        explicit Rationnel(int pNum, float pDen);
        explicit Rationnel(const Rationnel& r);

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
        int arrondir(float f);
        int pgcd(int a, int b);
};

#endif // RATIONNEL_H
