#ifndef SAVEDSTATE_H
#define SAVEDSTATE_H

#include "constante.h"
#include <QStack>

class SavedState
{
    private:
        Constante* mConstante;
        QStack<Constante*> mStack;
        int mModeConstante;
        int mModeComplexe;
        int mModeDegre;
    public:
        SavedState() {}
        SavedState(Constante* constanteCourante, const QStack<Constante*> &stack, int modeConstante, int modeComplexe, int modeDegre);
        Constante* getConstante() const { return mConstante; }
        const QStack<Constante*> getStack() const { return mStack; }
        int getModeConstante() const { return mModeConstante; }
        int getModeComplexe() const { return mModeComplexe; }
        int getModeDegre() const { return mModeDegre; }
};

#endif // SAVEDSTATE_H
