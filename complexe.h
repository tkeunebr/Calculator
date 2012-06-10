#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include <cmath>

class Complexe : public Constante
{
    public:
        Complexe(float pRe = 0, float pIm = 0);

        // Getters
        float getRe() const {return mRe;}
        float getIm() const {return mIm;}
        virtual bool isDollarEntre() const { return mDollarEntre; }

        // Setters
        virtual void setDollarEntre(bool dollarEntre = true) {
            mDollarEntre = dollarEntre;
            nbChiffresApresVirgule = 0;
        }
        virtual void setVirguleEntree(bool virguleEntree = true) {
            if(virguleEntree) nbChiffresApresVirgule++;
            else nbChiffresApresVirgule = 0;
        }
        virtual void setSlashEntre(bool slashEntre = true){ }


        virtual void addChiffre(int chiffre);

        virtual const QString toString() const;

    private:
        float mRe;
        float mIm;
        bool mDollarEntre;
        int nbChiffresApresVirgule;
};

#endif // COMPLEXE_H
