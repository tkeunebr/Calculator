#ifndef CALCULATRICEPOLONAISE_H
#define CALCULATRICEPOLONAISE_H

#include <QMainWindow>
#include <QtGui>
#include <QStack>

#include "complexereelfactory.h"
#include "complexerationnelfactory.h"
#include "rationnelfactory.h"
#include "expression.h"
#include "calculatriceexception.h"
#include "evalexception.h"
#include "trigoexception.h"
#include "divexception.h"


#include "operationbinaire.h"
#include "operationunaire.h"

#include "savedstate.h"
#include "logsystem.h"


namespace Ui {
class CalculatricePolonaise;
}

/**
 * Classe principale de l'application. Comporte une pile de pointeurs sur Constante, ainsi qu'un pointeur sur ConstanteFactory instanciée selon le bon type
 * Les modes sont geres a l'aide de variables de classes statiques constantes.
 */


class CalculatricePolonaise : public QMainWindow
{
    Q_OBJECT
    
public:
    const static int MODE_ENTIER = 0;
    const static int MODE_RATIONNEL = 1;
    const static int MODE_REEL = 2;
    const static int MODE_AVEC_COMPLEXES = 3;
    const static int MODE_SANS_COMPLEXES = 4;
    const static int MODE_DEGRE = 5;
    const static int MODE_RADIAN = 6;

    explicit CalculatricePolonaise(QWidget *parent = 0);
    ~CalculatricePolonaise();

protected:
    // Events
    void closeEvent(QCloseEvent *event);
    
private:
    Ui::CalculatricePolonaise *ui;
    QStack<Constante*> pile;
    QStack<SavedState> mHistoryStackPrecedent;
    QStack<SavedState> mHistoryStackSuivant;
    int maxAffichage;

    void setShortcuts();
    void setConnections();
    void setContext();
    void setFactory();
    void buttonChiffrePressed(int valeurBouton);
    void updateAffichage();
    void showError(const QString& s);
    bool erreurOpUnaire();
    bool erreurOpBinaire();
    void saveSettings();
    void saveContext();

    Constante *nombreCourant;
    ConstanteFactory* mFactory;

    int modeConstante;
    int modeComplexes;
    int modeDeg;

    // Clavier Layout dimensions
    QRect dimOperationsGenerales;
    QRect dimOperationsPile;
    QRect dimOperations;

    // LogSystem
    LogSystem* mLogSys;
    // Settings
    QSettings* mSettings;

private slots:
    // Actions
    void aPropos();
    void aProposDeQt();
    void quitterCalculatrice();
    void undo();
    void redo();

    // PushButtons
    void button0Pressed();
    void button1Pressed();
    void button2Pressed();
    void button3Pressed();
    void button4Pressed();
    void button5Pressed();
    void button6Pressed();
    void button7Pressed();
    void button8Pressed();
    void button9Pressed();
    void buttonPlusPressed();
    void buttonMoinsPressed();
    void buttonMultPressed();
    void buttonDivPressed();
    void buttonVirgulePressed();
    void buttonPushPressed();
    void buttonClearPressed();
    void buttonDupPressed();
    void buttonDropPressed();
    void buttonSumPressed();
    void buttonMeanPressed();
    void buttonSwapPressed();
    void buttonCancelPressed();
    void buttonExpPressed();
    void buttonDollarPressed();
    void buttonEvalPressed();
    void buttonCosPressed();
    void buttonSinPressed();
    void buttonTanPressed();
    void buttonCoshPressed();
    void buttonSinhPressed();
    void buttonTanhPressed();

    // Checkboxs
    void cacherClavier(int newstate);
    void modeEntier();
    void modeRationnel();
    void modeReel();
    void modeAvecComplexes();
    void modeSansComplexes();
    void modeDegres();
    void modeRadians();

    // Spinboxs
    void setMaxAffichage(int max);
};

#endif // CALCULATRICEPOLONAISE_H
