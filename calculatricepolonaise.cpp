#include "calculatricepolonaise.h"
#include "ui_calculatricepolonaise.h"

CalculatricePolonaise::CalculatricePolonaise(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatricePolonaise),
    mSettings(new QSettings("LO21", "Calculatrice Polonaise")),
    mLogSys(LogSystem::newInstance())
{
    mLogSys->addMessage("Création de l'application", 4);
    ui->setupUi(this);
    setWindowTitle("Calculatrice Polonaise");
    this->setFixedSize(this->size());

    mLogSys->addMessage("Récupération et restauration du contexte", 2);
    modeConstante = mSettings->value("Mode_Constante", CalculatricePolonaise::MODE_ENTIER).toInt();
    modeComplexes = mSettings->value("Mode_Complexe", CalculatricePolonaise::MODE_SANS_COMPLEXES).toInt();
    modeDeg = mSettings->value("Mode_Degres", CalculatricePolonaise::MODE_DEGRE).toInt();
    maxAffichage = mSettings->value("Max_affichage", 10).toInt();

    setFactory();

    mLogSys->addMessage("Initialisation du nombre courant", 5);
    nombreCourant = mFactory->newInstance();

    setShortcuts();
    setConnections();
    setContext();

    updateAffichage();
}

void CalculatricePolonaise::setConnections(){
    mLogSys->addMessage("Connexion des slots", 1);

    // Actions
    connect(ui->actionA_propos_de_Qt,SIGNAL(triggered()),this,SLOT(aProposDeQt()));
    connect(ui->actionA_propos,SIGNAL(triggered()),this,SLOT(aPropos()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(quitterCalculatrice()));
    connect(ui->actionRetablir, SIGNAL(triggered()), this, SLOT(undo()));
    connect(ui->actionAnnuler, SIGNAL(triggered()), this, SLOT(redo()));

     // PushButton
    connect(ui->pushButton0,SIGNAL(clicked()),this,SLOT(button0Pressed()));
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(button1Pressed()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(button2Pressed()));
    connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(button3Pressed()));
    connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(button4Pressed()));
    connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(button5Pressed()));
    connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(button6Pressed()));
    connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(button7Pressed()));
    connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(button8Pressed()));
    connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(button9Pressed()));
    connect(ui->pushButtonPlus,SIGNAL(clicked()),this,SLOT(buttonPlusPressed()));
    connect(ui->pushButtonMoins,SIGNAL(clicked()),this,SLOT(buttonMoinsPressed()));
    connect(ui->pushButtonMult,SIGNAL(clicked()),this,SLOT(buttonMultPressed()));
    connect(ui->pushButtonDiv,SIGNAL(clicked()),this,SLOT(buttonDivPressed()));
    connect(ui->pushButtonVirgule,SIGNAL(clicked()),this,SLOT(buttonVirgulePressed()));
    connect(ui->pushButtonPush,SIGNAL(clicked()),this,SLOT(buttonPushPressed()));
    connect(ui->pushButtonClear,SIGNAL(clicked()),this,SLOT(buttonClearPressed()));
    connect(ui->pushButtonDup, SIGNAL(clicked()), this, SLOT(buttonDupPressed()));
    connect(ui->pushButtonDrop, SIGNAL(clicked()), this, SLOT(buttonDropPressed()));
    connect(ui->pushButtonCancel,SIGNAL(clicked()),this,SLOT(buttonCancelPressed()));
    connect(ui->pushButtonSum, SIGNAL(clicked()), this, SLOT(buttonSumPressed()));
    connect(ui->pushButtonMean, SIGNAL(clicked()), this, SLOT(buttonMeanPressed()));
    connect(ui->pushButtonSwap, SIGNAL(clicked()), this, SLOT(buttonSwapPressed()));
    connect(ui->pushButtonExp, SIGNAL(clicked()), this, SLOT(buttonExpPressed()));
    connect(ui->pushButtonDollar, SIGNAL(clicked()), this, SLOT(buttonDollarPressed()));
    connect(ui->pushButtonEval, SIGNAL(clicked()), this, SLOT(buttonEvalPressed()));
    connect(ui->pushButtonCos, SIGNAL(clicked()), this, SLOT(buttonCosPressed()));
    connect(ui->pushButtonSin, SIGNAL(clicked()), this, SLOT(buttonSinPressed()));
    connect(ui->pushButtonTan, SIGNAL(clicked()), this, SLOT(buttonTanPressed()));
    connect(ui->pushButtonCosh, SIGNAL(clicked()), this, SLOT(buttonCoshPressed()));
    connect(ui->pushButtonSinh, SIGNAL(clicked()), this, SLOT(buttonSinhPressed()));
    connect(ui->pushButtonTanh, SIGNAL(clicked()), this, SLOT(buttonTanhPressed()));

    // Checks
    connect(ui->checkBoxClavier, SIGNAL(stateChanged(int)), this, SLOT(cacherClavier(int)));
    connect(ui->radioButtonEntier, SIGNAL(clicked()), this, SLOT(modeEntier()));
    connect(ui->radioButtonRationnel, SIGNAL(clicked()), this, SLOT(modeRationnel()));
    connect(ui->radioButtonReel, SIGNAL(clicked()), this, SLOT(modeReel()));
    connect(ui->radioButtonAvecComplexes, SIGNAL(clicked()), this, SLOT(modeAvecComplexes()));
    connect(ui->radioButtonSansComplexes, SIGNAL(clicked()), this, SLOT(modeSansComplexes()));
    connect(ui->radioButtonDegres, SIGNAL(clicked()), this, SLOT(modeDegres()));
    connect(ui->radioButtonRadians, SIGNAL(clicked()), this, SLOT(modeRadians()));

    // Spins
    connect(ui->spinBoxNbElemPile, SIGNAL(valueChanged(int)), this, SLOT(setMaxAffichage(int)));
}

void CalculatricePolonaise::setShortcuts(){
    ui->actionRetablir->setShortcut(tr("Ctrl+Z"));
    ui->actionAnnuler->setShortcut(tr("Ctrl+Y"));
    ui->pushButton0->setShortcut(Qt::Key_0);
    ui->pushButton1->setShortcut(Qt::Key_1);
    ui->pushButton2->setShortcut(Qt::Key_2);
    ui->pushButton3->setShortcut(Qt::Key_3);
    ui->pushButton4->setShortcut(Qt::Key_4);
    ui->pushButton5->setShortcut(Qt::Key_5);
    ui->pushButton6->setShortcut(Qt::Key_6);
    ui->pushButton7->setShortcut(Qt::Key_7);
    ui->pushButton8->setShortcut(Qt::Key_8);
    ui->pushButton9->setShortcut(Qt::Key_9);
    ui->pushButtonVirgule->setShortcut(Qt::Key_Comma);
    ui->pushButtonPlus->setShortcut(Qt::Key_Plus);
    ui->pushButtonMoins->setShortcut(Qt::Key_Minus);
    ui->pushButtonDiv->setShortcut(Qt::Key_Slash);
    ui->pushButtonMult->setShortcut(Qt::Key_Asterisk);
    ui->pushButtonPush->setShortcut(Qt::Key_Enter);
    ui->pushButtonClear->setShortcut(tr("Ctrl+C"));
    ui->pushButtonCancel->setShortcut(Qt::Key_Delete);
    ui->pushButtonExp->setShortcut(Qt::Key_E);
    ui->pushButtonDollar->setShortcut(Qt::Key_Dollar);
}

void CalculatricePolonaise::setContext() {
    ui->radioButtonEntier->setChecked(modeConstante == CalculatricePolonaise::MODE_ENTIER);
    ui->radioButtonRationnel->setChecked(modeConstante == CalculatricePolonaise::MODE_RATIONNEL);
    ui->radioButtonReel->setChecked(modeConstante == CalculatricePolonaise::MODE_REEL);

    ui->radioButtonAvecComplexes->setChecked(modeComplexes == CalculatricePolonaise::MODE_AVEC_COMPLEXES);
    ui->radioButtonSansComplexes->setChecked(modeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES);

    ui->radioButtonDegres->setChecked(modeDeg == CalculatricePolonaise::MODE_DEGRE);
    ui->radioButtonRadians->setChecked(modeDeg == CalculatricePolonaise::MODE_RADIAN);

    // Restauration de la pile
    int pileSize = mSettings->value("Taille_pile", 0).toInt();
    for(int i=0;i<pileSize;i++) {
        QString s = mSettings->value("Constante " + QString::number(i), "0").toString();
        if (s[0] == '\"') {
            // c'est une expression
            pile.push(new Expression(s.remove(QChar('"'), Qt::CaseInsensitive)));
        }
        else {
            try {
                Constante* c = Eval(Expression(s), modeConstante, modeComplexes, modeDeg).getValue();
                pile.push(c);
            }
            catch (TypeConstanteException e) {
                showError(e.getErrorMessage());
            }
            catch(EvalException e){
                showError(e.getErrorMessage());
            }
        }
    }

    for(int i=0;i<pileSize;i++) {
        mSettings->remove("Constante " + QString::number(i));
    }

    // Restauration de la constante courante
    QString s = mSettings->value("Constante_Courante", "").toString();
    if (s == "") {
        nombreCourant = mFactory->newInstance();
    }
    else {
        nombreCourant = Eval(Expression(s), modeConstante, modeComplexes, modeDeg).getValue();
    }

    // Max affichage
    ui->spinBoxNbElemPile->setValue(maxAffichage);
}

void CalculatricePolonaise::setFactory() {
    mLogSys->addMessage("Initialisation de la Factory", 5);
    if (modeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
        if (modeConstante == CalculatricePolonaise::MODE_ENTIER || modeConstante == CalculatricePolonaise::MODE_RATIONNEL) {
            mFactory = new RationnelFactory();
        }
        else {
            mFactory = new ComplexeReelFactory();
        }
    }
    else {
        if (modeConstante == CalculatricePolonaise::MODE_ENTIER || modeConstante == CalculatricePolonaise::MODE_RATIONNEL) {
            mFactory = new ComplexeRationnelFactory();
        }
        else {
            mFactory = new ComplexeReelFactory();
        }
    }
}

void CalculatricePolonaise::saveContext() {
    mHistoryStackPrecedent.push(SavedState(nombreCourant, pile, modeConstante, modeComplexes, modeDeg)); // Il ne faut plus delete nombreCourant...
}

CalculatricePolonaise::~CalculatricePolonaise() {
    delete mSettings;
    mLogSys->deleteInstance();
    delete ui;
}

void CalculatricePolonaise::aPropos(){
    QMessageBox::information(this,"A propos","Projet réalisé dans le cadre de l'UV LO21");
}

void CalculatricePolonaise::aProposDeQt(){
    QMessageBox::aboutQt(this);
}

void CalculatricePolonaise::undo() {
    mLogSys->addMessage("Ctrl+Z détecté");
    if (mHistoryStackPrecedent.size() == 0) {
        return;
    }

    mHistoryStackSuivant.push(SavedState(nombreCourant, pile, modeConstante, modeComplexes, modeDeg));

    //if (historyPosition <= 0) return;
    //historyPosition--;
    SavedState s = mHistoryStackPrecedent.pop();
    pile = s.getStack();
    nombreCourant = s.getConstante();
    modeConstante = s.getModeConstante();
    modeComplexes = s.getModeComplexe();
    modeDeg = s.getModeDegre();



    updateAffichage();
}

void CalculatricePolonaise::redo() {
    mLogSys->addMessage("Ctrl+Y détecté");
    if (mHistoryStackSuivant.size() == 0) {
        return;
    }

    mHistoryStackPrecedent.push(SavedState(nombreCourant, pile, modeConstante, modeComplexes, modeDeg));

    SavedState s = mHistoryStackSuivant.pop();
    pile = s.getStack();
    nombreCourant = s.getConstante();
    modeConstante = s.getModeConstante();
    modeComplexes = s.getModeComplexe();
    modeDeg = s.getModeDegre();

    updateAffichage();
}

void CalculatricePolonaise::quitterCalculatrice() {
    saveSettings();
    mLogSys->addMessage("Fermeture de l'application");
    qApp->quit();
}

void CalculatricePolonaise::cacherClavier(int newstate){
    QList<QObject*> objlist = ui->layoutClavier->children();
    if(newstate == Qt::Unchecked){
        dimOperationsGenerales = ((QLayout*)objlist.at(0))->geometry();
        dimOperationsPile = ((QLayout*)objlist.at(1))->geometry();
        dimOperations = ((QLayout*)objlist.at(2))->geometry();
        ((QLayout*)objlist.at(0))->setGeometry(QRect(0, 0, 0, 0));
        ((QLayout*)objlist.at(1))->setGeometry(QRect(0, 0, 0, 0));
        ((QLayout*)objlist.at(2))->setGeometry(QRect(0, 0, 0, 0));
    }
    else{
        ((QLayout*)objlist.at(0))->setGeometry(dimOperationsGenerales);
        ((QLayout*)objlist.at(1))->setGeometry(dimOperationsPile);
        ((QLayout*)objlist.at(2))->setGeometry(dimOperations);
    }
}

void CalculatricePolonaise::button0Pressed(){
    buttonChiffrePressed(0);
}
void CalculatricePolonaise::button1Pressed(){
    buttonChiffrePressed(1);
}
void CalculatricePolonaise::button2Pressed(){
    buttonChiffrePressed(2);
}
void CalculatricePolonaise::button3Pressed(){
    buttonChiffrePressed(3);
}
void CalculatricePolonaise::button4Pressed(){
    buttonChiffrePressed(4);
}
void CalculatricePolonaise::button5Pressed(){
    buttonChiffrePressed(5);
}
void CalculatricePolonaise::button6Pressed(){
    buttonChiffrePressed(6);
}
void CalculatricePolonaise::button7Pressed(){
    buttonChiffrePressed(7);
}
void CalculatricePolonaise::button8Pressed(){
    buttonChiffrePressed(8);
}
void CalculatricePolonaise::button9Pressed(){
    buttonChiffrePressed(9);
}
void CalculatricePolonaise::buttonPlusPressed(){
    if (erreurOpBinaire()) {
        return;
    }

    saveContext();
    Constante* op1 = pile.pop(), *op2 = pile.pop();
    pile.push(Addition(*op2, *op1, modeConstante, modeComplexes).getValue());

    updateAffichage();
}

void CalculatricePolonaise::buttonExpPressed(){
    bool ok = false;
    QString exp = QInputDialog::getText(this, "Expression", "Entrez votre expression", QLineEdit::Normal, QString(), &ok);

    if (ok && !exp.isEmpty())
    {
        saveContext();
        pile.push(new Expression(exp));
        updateAffichage();
    }
}

void CalculatricePolonaise::buttonMoinsPressed(){
    if (erreurOpBinaire()) {
        return;
    }

    saveContext();
    Constante* op1 = pile.pop(), *op2 = pile.pop();
    pile.push(Soustraction(*op2, *op1, modeConstante, modeComplexes).getValue());

    updateAffichage();
}

void CalculatricePolonaise::buttonMultPressed(){
    if (erreurOpBinaire()) {
        return;
    }

    saveContext();
    Constante* op1 = pile.pop(), *op2 = pile.pop();
    pile.push(Multiplication(*op2, *op1, modeConstante, modeComplexes).getValue());

    updateAffichage();
}

void CalculatricePolonaise::buttonDivPressed(){
    if (modeConstante == CalculatricePolonaise::MODE_RATIONNEL) {
        nombreCourant->setSlashEntre();
        return;
    }

    if (erreurOpBinaire()) {
        return;
    }

    saveContext();
    Constante* op1 = pile.pop(), *op2 = pile.pop();
    try{
        pile.push(Division(*op2, *op1, modeConstante, modeComplexes).getValue());
    }
    catch(DivException e){
        showError(e.getErrorMessage());
        pile.push(op2);
        pile.push(op1);
    }

    updateAffichage();

}

void CalculatricePolonaise::buttonVirgulePressed(){
    if (modeConstante == CalculatricePolonaise::MODE_REEL || (modeConstante == CalculatricePolonaise::MODE_RATIONNEL && modeComplexes == CalculatricePolonaise::MODE_AVEC_COMPLEXES)) {
        nombreCourant->setVirguleEntree();
        updateAffichage();
    }
}

void CalculatricePolonaise::buttonPushPressed(){
    mLogSys->addMessage("Nombre ajouté dans la pile : " + nombreCourant->toString(), 3);
    saveContext();
    pile.push(nombreCourant);
    nombreCourant = mFactory->newInstance();
    updateAffichage();
}

void CalculatricePolonaise::buttonClearPressed(){
    while (!pile.empty()) {
        saveContext();
        pile.pop();
        updateAffichage();
    }
}

void CalculatricePolonaise::buttonDupPressed() {
    if (!pile.empty()) {
        saveContext();
        pile.push(pile.at(pile.size()-1));
        updateAffichage();
    }
}

void CalculatricePolonaise::buttonDropPressed() {
    if (!pile.empty()) {
        saveContext();
        pile.pop();
        updateAffichage();
    }
}

void CalculatricePolonaise::buttonSumPressed() {
    if (pile.size() > 2) {
        saveContext();
        int arg = pile.pop()->toString().toInt();
        if (arg <= pile.size()) {
            int i = 0;
            Constante* sum = new Complexe(0, 0);
            saveContext();
            while (i < arg) {
                sum = Addition(*sum, *pile.pop(), modeConstante, modeComplexes).getValue();
                i++;
            }
            pile.push(sum);
            updateAffichage();
        }
    }
}

void CalculatricePolonaise::buttonMeanPressed() {
    if (pile.size() > 2) {
        saveContext();
        int arg = pile.pop()->toString().toInt();
        if (arg <= pile.size()) {
            int i = 0;
            Constante* sum = new Complexe(0, 0);
            saveContext();
            while (i < arg) {
                sum = Addition(*sum, *pile.pop(), modeConstante, modeComplexes).getValue();
                i++;
            }
            try {
                sum = Division(*sum, Rationnel(i), modeConstante, modeComplexes).getValue();
                pile.push(sum);
                updateAffichage();
            }
            catch (DivException e) {
                showError(e.getErrorMessage());
            }
        }
    }
}

void CalculatricePolonaise::buttonSwapPressed() {
    if (pile.size() > 3) {
        saveContext();
        int arg1 = pile.pop()->toString().toInt();
        saveContext();
        int arg2 = pile.pop()->toString().toInt();
        if (arg1 < pile.size() && arg2 < pile.size()) {
            Constante* tmp = pile.at(arg1);
            saveContext();
            pile.remove(arg1);
            pile.insert(arg1, pile.at(arg2));
            pile.remove(arg2);
            pile.insert(arg2, tmp);
            updateAffichage();
        }
    }
}

void CalculatricePolonaise::buttonCancelPressed(){
    saveContext();
    nombreCourant = mFactory->newInstance();
    updateAffichage();
}

void CalculatricePolonaise::buttonDollarPressed(){
    if (modeComplexes == CalculatricePolonaise::MODE_AVEC_COMPLEXES)
        nombreCourant->setDollarEntre();
}

void CalculatricePolonaise::buttonChiffrePressed(int valeurBouton){
    nombreCourant->addChiffre(valeurBouton);
    updateAffichage();
}

void CalculatricePolonaise::buttonEvalPressed() {
    if (erreurOpUnaire()) return;

    saveContext();
    Constante* op = pile.pop();
    mLogSys->addMessage("Evaluation de " + op->toString(), 3);
    try {
        pile.push(Eval(*op, modeConstante, modeComplexes, modeDeg).getValue());
    }
    catch (TypeConstanteException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }
    catch(EvalException e){
        showError(e.getErrorMessage());
    }

    updateAffichage();
}

void CalculatricePolonaise::buttonCosPressed() {
    if (erreurOpUnaire()) {
        return;
    }

    saveContext();
    Constante* op = pile.pop();
    try {
        pile.push(Cos(*op, modeConstante, modeComplexes, modeDeg).getValue());
    }
    catch (TypeConstanteException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }

    updateAffichage();
}

void CalculatricePolonaise::buttonSinPressed() {
    if (erreurOpUnaire()) {
        return;
    }

    saveContext();
    Constante* op = pile.pop();
    try {
        pile.push(Sin(*op, modeConstante, modeComplexes, modeDeg).getValue());
    }
    catch (TypeConstanteException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }

    updateAffichage();
}

void CalculatricePolonaise::buttonTanPressed() {
    if (erreurOpUnaire()) {
        return;
    }

    saveContext();
    Constante* op = pile.pop();
    try {
        pile.push(Tan(*op, modeConstante, modeComplexes, modeDeg).getValue());
    }
    catch (TypeConstanteException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }
    catch (TrigoException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }

    updateAffichage();
}

void CalculatricePolonaise::buttonCoshPressed() {
    if (erreurOpUnaire()) {
        return;
    }

    saveContext();
    Constante* op = pile.pop();
    try {
        pile.push(Cosh(*op, modeConstante, modeComplexes, modeDeg).getValue());
    }
    catch (TypeConstanteException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }

    updateAffichage();
}

void CalculatricePolonaise::buttonSinhPressed() {
    if (erreurOpUnaire()) {
        return;
    }

    saveContext();
    Constante* op = pile.pop();
    try {
        pile.push(Sinh(*op, modeConstante, modeComplexes, modeDeg).getValue());
    }
    catch (TypeConstanteException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }

    updateAffichage();
}

void CalculatricePolonaise::buttonTanhPressed() {
    if (erreurOpUnaire()) {
        return;
    }

    saveContext();
    Constante* op = pile.pop();
    try {
        pile.push(Tanh(*op, modeConstante, modeComplexes, modeDeg).getValue());
    }
    catch (TypeConstanteException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }
    catch (TrigoException e) {
        pile.push(op);
        showError(e.getErrorMessage());
    }

    updateAffichage();
}

void CalculatricePolonaise::modeEntier() {
    if (modeConstante == CalculatricePolonaise::MODE_ENTIER) return;
    Constante* tmp;

    if (modeComplexes == CalculatricePolonaise::MODE_AVEC_COMPLEXES) {
        Complexe* complexeCourant = (Complexe*) nombreCourant;
        if (modeConstante == CalculatricePolonaise::MODE_REEL) {
            delete mFactory;
            mFactory = new ComplexeRationnelFactory();
            tmp = new Complexe(Rationnel(complexeCourant->getRe()), Rationnel(complexeCourant->getIm()));
        }
        else {
            // On vient du mode rationnel
            tmp = new Complexe(Rationnel(complexeCourant->getReRationnel().getNum()/complexeCourant->getReRationnel().getDen()), Rationnel(complexeCourant->getImRationnel().getNum()/complexeCourant->getImRationnel().getDen()));
        }
    }
    else {
        if (modeConstante == CalculatricePolonaise::MODE_REEL) {
            Complexe* complexeCourant = (Complexe*) nombreCourant;
            delete mFactory;
            mFactory = new RationnelFactory();
            tmp = new Rationnel(complexeCourant->getRe());
        }
        else {
            // On vient du mode rationnel
            Rationnel* ratCourant = (Rationnel*) nombreCourant;
            if (ratCourant->getDen() != 0) tmp = new Rationnel(ratCourant->getNum()/ratCourant->getDen());
            else tmp = new Rationnel(ratCourant->getNum());
        }
    }

    delete nombreCourant;
    nombreCourant = tmp;

    modeConstante = CalculatricePolonaise::MODE_ENTIER;
    updateAffichage();
}

void CalculatricePolonaise::modeRationnel() {
    if (modeConstante == CalculatricePolonaise::MODE_RATIONNEL) return;
    Constante* tmp;

    if (modeComplexes == CalculatricePolonaise::MODE_AVEC_COMPLEXES) {
        Complexe* complexeCourant = (Complexe*) nombreCourant;
        if (modeConstante == CalculatricePolonaise::MODE_REEL) {
            delete mFactory;
            mFactory = new ComplexeRationnelFactory();
            tmp = new Complexe(Rationnel(complexeCourant->getRe()*1000000, 1000000), Rationnel(complexeCourant->getIm()*1000000, 1000000));

            delete nombreCourant;
            nombreCourant = tmp;
        }
    }
    else {
        if (modeConstante == CalculatricePolonaise::MODE_REEL) {
            Complexe* complexeCourant = (Complexe*) nombreCourant;
            delete mFactory;
            mFactory = new RationnelFactory();
            tmp = new Rationnel(complexeCourant->getRe()*1000000, 1000000);

            delete nombreCourant;
            nombreCourant = tmp;
        }
    }

    modeConstante = CalculatricePolonaise::MODE_RATIONNEL;
    updateAffichage();
}

void CalculatricePolonaise::modeReel() {
    if (modeConstante == CalculatricePolonaise::MODE_REEL) return;
    Constante* tmp;
    delete mFactory;
    mFactory = new ComplexeReelFactory();

    if (modeComplexes == CalculatricePolonaise::MODE_AVEC_COMPLEXES) {
        Complexe* complexeCourant = (Complexe*) nombreCourant;
        tmp = new Complexe((float)complexeCourant->getReRationnel().getNum()/(float)complexeCourant->getReRationnel().getDen(), (float)complexeCourant->getImRationnel().getNum()/(float)complexeCourant->getImRationnel().getDen());
    }
    else {
        Rationnel* ratCourant = (Rationnel*) nombreCourant;
        tmp = new Complexe((float)ratCourant->getNum()/(float)ratCourant->getDen());
    }

    delete nombreCourant;
    nombreCourant = tmp;

    modeConstante = CalculatricePolonaise::MODE_REEL;
    updateAffichage();
}

void CalculatricePolonaise::modeAvecComplexes() {
    if (modeComplexes == CalculatricePolonaise::MODE_AVEC_COMPLEXES) return;
    Constante* tmp;

    if (modeConstante == CalculatricePolonaise::MODE_ENTIER || modeConstante == CalculatricePolonaise::MODE_RATIONNEL) {
        delete mFactory;
        mFactory = new ComplexeRationnelFactory();

        Rationnel* ratCourant = (Rationnel*) nombreCourant;
        tmp = new Complexe(*ratCourant);

        delete nombreCourant;
        nombreCourant = tmp;
    }

    modeComplexes = CalculatricePolonaise::MODE_AVEC_COMPLEXES;
    updateAffichage();
}

void CalculatricePolonaise::modeSansComplexes() {
    if (modeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) return;
    Constante* tmp;
    Complexe* complexeCourant = (Complexe*) nombreCourant;

    if (modeConstante == CalculatricePolonaise::MODE_ENTIER || modeConstante == CalculatricePolonaise::MODE_RATIONNEL) {
        delete mFactory;
        mFactory = new RationnelFactory();

        tmp = new Rationnel(complexeCourant->getReRationnel());

        delete nombreCourant;
        nombreCourant = tmp;
    }
    else {
        // Je suis en mode réel
        tmp = new Complexe(complexeCourant->getRe());

        delete nombreCourant;
        nombreCourant = tmp;
    }

    modeComplexes = CalculatricePolonaise::MODE_SANS_COMPLEXES;
    updateAffichage();
}

void CalculatricePolonaise::modeDegres() {
    modeDeg = CalculatricePolonaise::MODE_DEGRE;
}

void CalculatricePolonaise::modeRadians() {
    modeDeg = CalculatricePolonaise::MODE_RADIAN;
}

void CalculatricePolonaise::setMaxAffichage(int max) {
    maxAffichage = max;
    updateAffichage();
}

void CalculatricePolonaise::showError(const QString& s) {
    QMessageBox::warning(this,"Erreur", s);
}

bool CalculatricePolonaise::erreurOpUnaire() {
    if(pile.size()<1){
        QMessageBox::warning(this,"Pas assez d'opérandes","Cette opérateur nécessite au moins 1 opérande");
        return true;
    }
    return false;
}

bool CalculatricePolonaise::erreurOpBinaire() {
    if(pile.size()<2){
        QMessageBox::warning(this,"Pas assez d'opérandes","Cette opérateur nécessite au moins deux opérandes");
        return true;
    }
    return false;
}

void CalculatricePolonaise::saveSettings() {
    mLogSys->addMessage("Sauvegarde du contexte");
    mSettings->setValue("Mode_Constante", modeConstante);
    mSettings->setValue("Mode_Complexe", modeComplexes);
    mSettings->setValue("Mode_Degres", modeDeg);
    mSettings->setValue("Max_affichage", maxAffichage);
    mSettings->setValue("Constante_Courante", nombreCourant->toString());

    // Sauvegarde de l'état de la pile
    mSettings->setValue("Taille_pile", pile.size());
    for(int i=0;i<pile.size();i++) {
        mSettings->setValue("Constante " + QString::number(i), pile.at(i)->toString());
    }
}

void CalculatricePolonaise::updateAffichage(){
    ui->affichageConstante->setText(nombreCourant->toString());
    QString s;

    int lim = std::min(pile.size(), maxAffichage);
    for(int i=0;i<lim;i++) s+=pile.at(i)->toString()+"\n";
    int nbRestant = pile.size() - lim;
    if (nbRestant > 1) s+= "\n...\n(" + QString::number(nbRestant) + " nombres restants dans la pile)\n";
    else if (nbRestant == 1) s+= "\n...\n(" + QString::number(nbRestant) + " nombre restant dans la pile)\n";
    ui->affichagePile->setText(s);
}

// Events

void CalculatricePolonaise::closeEvent(QCloseEvent *event) {
    saveSettings();
    mLogSys->addMessage("Fermeture de l'application");
    event->accept();
}
