#include "savedstate.h"

SavedState::SavedState(Constante* constanteCourante, const QStack<Constante*> &stack, int modeConstante, int modeComplexe, int modeDegre)
    : mConstante(constanteCourante), mStack(stack), mModeConstante(modeConstante), mModeComplexe(modeComplexe), mModeDegre(modeDegre)
{
}
