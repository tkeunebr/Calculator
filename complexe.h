#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "rationnel.h"
#include <cmath>

/**
 * Classe definissant un complexe et ses methodes. Herite de la classe Constante et definit les methodes declarees virtuelles pures dans celle-ci.
 * Un complexe peut etre compose de reels ou de rationnels, d'ou les quatre attributs (une partie reelle et une imaginaire pour chaque type de complexe).
 * le booleen mIsFloat permet a quel type on a affaire. 
 */


class Complexe : public Constante
{
    public:
        Complexe(float pRe = 0, float pIm = 0);
        Complexe(Rationnel& pRe = Rationnel(), Rationnel& pIm = Rationnel());
        Complexe(const Rationnel& pRe = Rationnel(), const Rationnel& pIm = Rationnel());

        // Getters
        float getRe() const {return mRe;}
        float getIm() const {return mIm;}
        virtual bool isDollarEntre() const { return mDollarEntre; }
        bool isFloat() const { return mIsFloat; }
        const Rationnel& getReRationnel() const { return mReRationnel; }
        const Rationnel& getImRationnel() const { return mImRationnel; }

        // Setters
        virtual void setDollarEntre(bool dollarEntre = true) {
            mDollarEntre = dollarEntre;
            nbChiffresApresVirgule = 0;
        }
        virtual void setVirguleEntree(bool virguleEntree = true) {
            if(virguleEntree) nbChiffresApresVirgule++;
            else nbChiffresApresVirgule = 0;
        }
        virtual void setSlashEntre(bool slashEntre = true);
        void setIsFloat(bool isFloat = true) { mIsFloat = isFloat; }


        virtual void addChiffre(int chiffre);

        virtual const QString toString() const;
    private:
        float mRe;
        float mIm;
        Rationnel mReRationnel;
        Rationnel mImRationnel;
        bool mDollarEntre;
        int nbChiffresApresVirgule;
        bool mIsFloat;
};

#endif // COMPLEXE_H
