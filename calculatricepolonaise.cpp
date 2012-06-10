#include "calculatricepolonaise.h"
#include "ui_calculatricepolonaise.h"

CalculatricePolonaise::CalculatricePolonaise(QWidget *parent) :
    QMainWindow(parent),
    maxAffichage(10),
    ui(new Ui::CalculatricePolonaise),
    modeConstante(CalculatricePolonaise::MODE_ENTIER),
    modeComplexes(CalculatricePolonaise::MODE_SANS_COMPLEXES),
    mFactory(new RationnelFactory)
{
    ui->setupUi(this);
    nombreCourant = mFactory->newInstance();
    setWindowTitle("Calculatrice Polonaise");
    setShortcuts();
    setConnections();
    this->setFixedSize(this->size());
    updateAffichage();

}

void CalculatricePolonaise::setConnections(){
    // Actions
    connect(ui->actionA_propos_de_Qt,SIGNAL(triggered()),this,SLOT(aProposDeQt()));
    connect(ui->actionA_propos,SIGNAL(triggered()),this,SLOT(aPropos()));
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
    connect(ui->pushButtonCancel,SIGNAL(clicked()),this,SLOT(buttonCancelPressed()));
    connect(ui->pushButtonExp, SIGNAL(clicked()), this, SLOT(buttonExpPressed()));
    connect(ui->pushButtonDollar, SIGNAL(clicked()), this, SLOT(buttonDollarPressed()));

    // Checks
    connect(ui->checkBoxClavier, SIGNAL(stateChanged(int)), this, SLOT(cacherClavier(int)));
    connect(ui->radioButtonEntier, SIGNAL(clicked()), this, SLOT(modeEntier()));
    connect(ui->radioButtonRationnel, SIGNAL(clicked()), this, SLOT(modeRationnel()));
    connect(ui->radioButtonReel, SIGNAL(clicked()), this, SLOT(modeReel()));
    connect(ui->radioButtonAvecComplexes, SIGNAL(clicked()), this, SLOT(modeAvecComplexes()));
    connect(ui->radioButtonSansComplexes, SIGNAL(clicked()), this, SLOT(modeSansComplexes()));
}

void CalculatricePolonaise::setShortcuts(){
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
    ui->pushButtonClear->setShortcut(Qt::Key_C);
    ui->pushButtonCancel->setShortcut(Qt::Key_Delete);
    ui->pushButtonExp->setShortcut(Qt::Key_E);
    ui->pushButtonDollar->setShortcut(Qt::Key_Dollar);
}

CalculatricePolonaise::~CalculatricePolonaise()
{
    delete ui;
}

void CalculatricePolonaise::aPropos(){
    QMessageBox::information(this,"A propos","Projet réalisé dans le cadre de l'UV LO21");
}

void CalculatricePolonaise::aProposDeQt(){
    QMessageBox::aboutQt(this);
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
    if(pile.size()<2){
        QMessageBox::warning(this,"Pas assez d'opérandes","Cette opérateur nécessite au moins deux opérandes");
        return;
    }
    Constante* op1 = pile.pop(), *op2 = pile.pop();
    pile.push(Addition(*op2, *op1).getValue());
    delete op1;
    delete op2;

    updateAffichage();
}
void CalculatricePolonaise::buttonExpPressed(){
    bool ok = false;
    QString exp = QInputDialog::getText(this, "Expression", "Entrez votre expression", QLineEdit::Normal, QString(), &ok);

    if (ok && !exp.isEmpty())
    {
        pile.push(new Expression(exp));
        updateAffichage();
    }
}

void CalculatricePolonaise::buttonMoinsPressed(){
//    if(pile.size()<2){
//        QMessageBox::warning(this,"Pas assez d'opérandes","Cette opérateur nécessite au moins deux opérandes");
//        return;
//    }
//    Constante* op1 = pile.pop(), *op2 = pile.pop();
//    //constanteCourante = new Entier();
    updateAffichage();
}
void CalculatricePolonaise::buttonMultPressed(){
//    if(pile.size()<2){
//        QMessageBox::warning(this,"Pas assez d'opérandes","Cette opérateur nécessite au moins deux opérandes");
//        return;
//    }
//    Constante* op1 = pile.pop(), *op2 = pile.pop();
//    //constanteCourante = new Entier();
//    updateAffichage();
}
void CalculatricePolonaise::buttonDivPressed(){
    if (modeConstante == CalculatricePolonaise::MODE_RATIONNEL) {
        nombreCourant->setSlashEntre();
        return;
    }
    if(pile.size()<2){
        QMessageBox::warning(this,"Pas assez d'opérandes","Cette opérateur nécessite au moins deux opérandes");
        return;
    }
//    Constante* op1 = pile.pop(), *op2 = pile.pop();
//    //constanteCourante = new Entier();
//    updateAffichage();
}
void CalculatricePolonaise::buttonVirgulePressed(){
    if (modeConstante == CalculatricePolonaise::MODE_REEL || (modeConstante == CalculatricePolonaise::MODE_RATIONNEL && modeComplexes == CalculatricePolonaise::MODE_AVEC_COMPLEXES))
        nombreCourant->setVirguleEntree();
        updateAffichage();
}
void CalculatricePolonaise::buttonPushPressed(){
    pile.push(nombreCourant);
    nombreCourant = mFactory->newInstance();
    updateAffichage();
}
void CalculatricePolonaise::buttonClearPressed(){
    if(!pile.empty()){
        Constante* e = pile.pop();
        delete e;
        updateAffichage();
    }
}
void CalculatricePolonaise::buttonCancelPressed(){
    delete nombreCourant;
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

void CalculatricePolonaise::modeEntier() {
    if (modeConstante == CalculatricePolonaise::MODE_REEL && modeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
        Constante* tmp = new Rationnel((int)(((Complexe*)nombreCourant)->getRe()));
        delete nombreCourant;
        nombreCourant = tmp;
        delete mFactory;
        mFactory = new RationnelFactory();
    }
    modeConstante = CalculatricePolonaise::MODE_ENTIER;
    updateAffichage();
}

void CalculatricePolonaise::modeRationnel() {
    if (modeConstante == CalculatricePolonaise::MODE_REEL && modeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
        Constante* tmp = new Rationnel((int)(((Complexe*)nombreCourant)->getRe()));
        delete nombreCourant;
        nombreCourant = tmp;
        delete mFactory;
        mFactory = new RationnelFactory();
    }
    modeConstante = CalculatricePolonaise::MODE_RATIONNEL;
    updateAffichage();
}

void CalculatricePolonaise::modeReel() {
    if ((modeConstante == CalculatricePolonaise::MODE_ENTIER || (modeConstante == CalculatricePolonaise::MODE_RATIONNEL)) && modeComplexes == CalculatricePolonaise::MODE_SANS_COMPLEXES) {
        Rationnel* ratCourant = (Rationnel*) nombreCourant;
        Constante* tmp = new Complexe(((float)ratCourant->getNum()/(float)ratCourant->getDen()));
        delete nombreCourant;
        nombreCourant = tmp;
        delete mFactory;
        mFactory = new ComplexeFactory();
    }
    modeConstante = CalculatricePolonaise::MODE_REEL;
    updateAffichage();
}

void CalculatricePolonaise::modeAvecComplexes() {
    if (modeConstante == CalculatricePolonaise::MODE_ENTIER || modeConstante == CalculatricePolonaise::MODE_RATIONNEL) {
        Rationnel* ratCourant = (Rationnel*) nombreCourant;
        Constante* tmp = new Complexe(((float)ratCourant->getNum()/(float)ratCourant->getDen()));
        delete nombreCourant;
        nombreCourant = tmp;
        delete mFactory;
        mFactory = new ComplexeFactory();
    }
    modeComplexes = CalculatricePolonaise::MODE_AVEC_COMPLEXES;
    updateAffichage();
}

void CalculatricePolonaise::modeSansComplexes() {
    if (modeConstante == CalculatricePolonaise::MODE_ENTIER || modeConstante == CalculatricePolonaise::MODE_RATIONNEL) {
        Complexe* complexeCourant = (Complexe*) nombreCourant;
        Constante* tmp = new Rationnel(1000000*complexeCourant->getRe(), 1000000);
        delete nombreCourant;
        nombreCourant = tmp;
        delete mFactory;
        mFactory = new RationnelFactory();
    }
    modeComplexes = CalculatricePolonaise::MODE_SANS_COMPLEXES;
    updateAffichage();
}

void CalculatricePolonaise::updateAffichage(){
    ui->affichageConstante->setText(nombreCourant->toString());
    QString s;

    int lim = std::min(pile.size(), maxAffichage);
    for(int i=0;i<lim;i++) s+=pile.at(i)->toString()+"\n";
    ui->affichagePile->setText(s);
}
