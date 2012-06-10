#ifndef CALCULATRICEPOLONAISE_H
#define CALCULATRICEPOLONAISE_H

#include <QMainWindow>
#include <QtGui>
#include <QStack>

#include "complexefactory.h"
#include "rationnelfactory.h"
#include "operationbinaire.h"
#include "expression.h"

namespace Ui {
class CalculatricePolonaise;
}

class CalculatricePolonaise : public QMainWindow
{
    Q_OBJECT
    
public:
    const static int MODE_ENTIER = 0;
    const static int MODE_RATIONNEL = 1;
    const static int MODE_REEL = 2;
    const static int MODE_AVEC_COMPLEXES = 3;
    const static int MODE_SANS_COMPLEXES = 4;

    explicit CalculatricePolonaise(QWidget *parent = 0);
    ~CalculatricePolonaise();
    
private:
    Ui::CalculatricePolonaise *ui;
    QStack<Constante*> pile;
    int maxAffichage;

    void setShortcuts();
    void setConnections();
    void buttonChiffrePressed(int valeurBouton);
    void updateAffichage();
    Constante *nombreCourant;
    ConstanteFactory* mFactory;

    int modeConstante;
    int modeComplexes;

    // Clavier Layout dimensions
    QRect dimOperationsGenerales;
    QRect dimOperationsPile;
    QRect dimOperations;

private slots:
    // Actions
    void aPropos();
    void aProposDeQt();

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
    void buttonCancelPressed();
    void buttonExpPressed();
    void buttonDollarPressed();

    // Checkboxs
    void cacherClavier(int newstate);
    void modeEntier();
    void modeRationnel();
    void modeReel();
    void modeAvecComplexes();
    void modeSansComplexes();

};

#endif // CALCULATRICEPOLONAISE_H
