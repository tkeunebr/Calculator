/********************************************************************************
** Form generated from reading UI file 'calculatricepolonaise.ui'
**
** Created: Tue 19. Jun 00:13:54 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATRICEPOLONAISE_H
#define UI_CALCULATRICEPOLONAISE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatricePolonaise
{
public:
    QAction *actionA_propos;
    QAction *actionQuitter;
    QAction *actionA_propos_de_Qt;
    QAction *actionAnnuler;
    QAction *actionRetablir;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *affichageConstante;
    QCheckBox *checkBoxClavier;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *affichagePile;
    QVBoxLayout *layoutClavier;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_8;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonPush;
    QPushButton *pushButtonExp;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_5;
    QPushButton *pushButtonSwap;
    QPushButton *pushButtonSum;
    QPushButton *pushButtonMean;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonDup;
    QPushButton *pushButtonDrop;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_4;
    QPushButton *pushButtonPow;
    QPushButton *pushButtonMod;
    QPushButton *pushButtonSign;
    QPushButton *pushButtonSin;
    QPushButton *pushButtonCos;
    QPushButton *pushButtonTan;
    QPushButton *pushButtonSinh;
    QPushButton *pushButtonCosh;
    QPushButton *pushButtonTanh;
    QPushButton *pushButtonSqr;
    QPushButton *pushButtonCube;
    QPushButton *pushButtonEval;
    QGridLayout *gridLayout;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;
    QPushButton *pushButtonDiv;
    QPushButton *pushButton4;
    QPushButton *pushButton6;
    QPushButton *pushButton5;
    QPushButton *pushButton3;
    QPushButton *pushButton2;
    QPushButton *pushButton1;
    QPushButton *pushButton0;
    QPushButton *pushButtonVirgule;
    QPushButton *pushButtonMult;
    QPushButton *pushButtonMoins;
    QPushButton *pushButtonPlus;
    QPushButton *pushButtonDollar;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBoxNbElemPile;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonEntier;
    QRadioButton *radioButtonRationnel;
    QRadioButton *radioButtonReel;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButtonAvecComplexes;
    QRadioButton *radioButtonSansComplexes;
    QGroupBox *groupBox_6;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_9;
    QRadioButton *radioButtonDegres;
    QRadioButton *radioButtonRadians;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu;
    QMenu *menuEdition;

    void setupUi(QMainWindow *CalculatricePolonaise)
    {
        if (CalculatricePolonaise->objectName().isEmpty())
            CalculatricePolonaise->setObjectName(QString::fromUtf8("CalculatricePolonaise"));
        CalculatricePolonaise->resize(629, 827);
        actionA_propos = new QAction(CalculatricePolonaise);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        actionQuitter = new QAction(CalculatricePolonaise);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionA_propos_de_Qt = new QAction(CalculatricePolonaise);
        actionA_propos_de_Qt->setObjectName(QString::fromUtf8("actionA_propos_de_Qt"));
        actionAnnuler = new QAction(CalculatricePolonaise);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionRetablir = new QAction(CalculatricePolonaise);
        actionRetablir->setObjectName(QString::fromUtf8("actionRetablir"));
        centralWidget = new QWidget(CalculatricePolonaise);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        affichageConstante = new QLineEdit(centralWidget);
        affichageConstante->setObjectName(QString::fromUtf8("affichageConstante"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(9);
        affichageConstante->setFont(font);
        affichageConstante->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        affichageConstante->setReadOnly(true);

        verticalLayout_5->addWidget(affichageConstante);

        checkBoxClavier = new QCheckBox(centralWidget);
        checkBoxClavier->setObjectName(QString::fromUtf8("checkBoxClavier"));
        checkBoxClavier->setChecked(true);

        verticalLayout_5->addWidget(checkBoxClavier);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        affichagePile = new QTextEdit(centralWidget);
        affichagePile->setObjectName(QString::fromUtf8("affichagePile"));
        affichagePile->setFont(font);
        affichagePile->setReadOnly(true);

        verticalLayout->addWidget(affichagePile);


        horizontalLayout->addLayout(verticalLayout);

        layoutClavier = new QVBoxLayout();
        layoutClavier->setSpacing(6);
        layoutClavier->setObjectName(QString::fromUtf8("layoutClavier"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_8 = new QVBoxLayout(groupBox_4);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        pushButtonCancel = new QPushButton(groupBox_4);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        verticalLayout_8->addWidget(pushButtonCancel);

        pushButtonPush = new QPushButton(groupBox_4);
        pushButtonPush->setObjectName(QString::fromUtf8("pushButtonPush"));

        verticalLayout_8->addWidget(pushButtonPush);

        pushButtonExp = new QPushButton(groupBox_4);
        pushButtonExp->setObjectName(QString::fromUtf8("pushButtonExp"));

        verticalLayout_8->addWidget(pushButtonExp);


        horizontalLayout_4->addWidget(groupBox_4);


        layoutClavier->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(6);
        pushButtonSwap = new QPushButton(groupBox_3);
        pushButtonSwap->setObjectName(QString::fromUtf8("pushButtonSwap"));

        gridLayout_5->addWidget(pushButtonSwap, 0, 1, 1, 1);

        pushButtonSum = new QPushButton(groupBox_3);
        pushButtonSum->setObjectName(QString::fromUtf8("pushButtonSum"));

        gridLayout_5->addWidget(pushButtonSum, 1, 1, 1, 1);

        pushButtonMean = new QPushButton(groupBox_3);
        pushButtonMean->setObjectName(QString::fromUtf8("pushButtonMean"));

        gridLayout_5->addWidget(pushButtonMean, 2, 1, 1, 1);

        pushButtonClear = new QPushButton(groupBox_3);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        gridLayout_5->addWidget(pushButtonClear, 0, 0, 1, 1);

        pushButtonDup = new QPushButton(groupBox_3);
        pushButtonDup->setObjectName(QString::fromUtf8("pushButtonDup"));

        gridLayout_5->addWidget(pushButtonDup, 1, 0, 1, 1);

        pushButtonDrop = new QPushButton(groupBox_3);
        pushButtonDrop->setObjectName(QString::fromUtf8("pushButtonDrop"));

        gridLayout_5->addWidget(pushButtonDrop, 2, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_5);


        horizontalLayout_3->addWidget(groupBox_3);


        layoutClavier->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButtonPow = new QPushButton(groupBox_5);
        pushButtonPow->setObjectName(QString::fromUtf8("pushButtonPow"));

        gridLayout_4->addWidget(pushButtonPow, 0, 0, 1, 1);

        pushButtonMod = new QPushButton(groupBox_5);
        pushButtonMod->setObjectName(QString::fromUtf8("pushButtonMod"));

        gridLayout_4->addWidget(pushButtonMod, 0, 1, 1, 1);

        pushButtonSign = new QPushButton(groupBox_5);
        pushButtonSign->setObjectName(QString::fromUtf8("pushButtonSign"));

        gridLayout_4->addWidget(pushButtonSign, 0, 2, 1, 1);

        pushButtonSin = new QPushButton(groupBox_5);
        pushButtonSin->setObjectName(QString::fromUtf8("pushButtonSin"));

        gridLayout_4->addWidget(pushButtonSin, 1, 0, 1, 1);

        pushButtonCos = new QPushButton(groupBox_5);
        pushButtonCos->setObjectName(QString::fromUtf8("pushButtonCos"));

        gridLayout_4->addWidget(pushButtonCos, 1, 1, 1, 1);

        pushButtonTan = new QPushButton(groupBox_5);
        pushButtonTan->setObjectName(QString::fromUtf8("pushButtonTan"));

        gridLayout_4->addWidget(pushButtonTan, 1, 2, 1, 1);

        pushButtonSinh = new QPushButton(groupBox_5);
        pushButtonSinh->setObjectName(QString::fromUtf8("pushButtonSinh"));

        gridLayout_4->addWidget(pushButtonSinh, 2, 0, 1, 1);

        pushButtonCosh = new QPushButton(groupBox_5);
        pushButtonCosh->setObjectName(QString::fromUtf8("pushButtonCosh"));

        gridLayout_4->addWidget(pushButtonCosh, 2, 1, 1, 1);

        pushButtonTanh = new QPushButton(groupBox_5);
        pushButtonTanh->setObjectName(QString::fromUtf8("pushButtonTanh"));

        gridLayout_4->addWidget(pushButtonTanh, 2, 2, 1, 1);

        pushButtonSqr = new QPushButton(groupBox_5);
        pushButtonSqr->setObjectName(QString::fromUtf8("pushButtonSqr"));

        gridLayout_4->addWidget(pushButtonSqr, 3, 0, 1, 1);

        pushButtonCube = new QPushButton(groupBox_5);
        pushButtonCube->setObjectName(QString::fromUtf8("pushButtonCube"));

        gridLayout_4->addWidget(pushButtonCube, 3, 1, 1, 1);

        pushButtonEval = new QPushButton(groupBox_5);
        pushButtonEval->setObjectName(QString::fromUtf8("pushButtonEval"));

        gridLayout_4->addWidget(pushButtonEval, 3, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton7 = new QPushButton(groupBox_5);
        pushButton7->setObjectName(QString::fromUtf8("pushButton7"));

        gridLayout->addWidget(pushButton7, 0, 0, 1, 1);

        pushButton8 = new QPushButton(groupBox_5);
        pushButton8->setObjectName(QString::fromUtf8("pushButton8"));

        gridLayout->addWidget(pushButton8, 0, 1, 1, 1);

        pushButton9 = new QPushButton(groupBox_5);
        pushButton9->setObjectName(QString::fromUtf8("pushButton9"));

        gridLayout->addWidget(pushButton9, 0, 2, 1, 1);

        pushButtonDiv = new QPushButton(groupBox_5);
        pushButtonDiv->setObjectName(QString::fromUtf8("pushButtonDiv"));

        gridLayout->addWidget(pushButtonDiv, 0, 3, 1, 1);

        pushButton4 = new QPushButton(groupBox_5);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));

        gridLayout->addWidget(pushButton4, 1, 0, 1, 1);

        pushButton6 = new QPushButton(groupBox_5);
        pushButton6->setObjectName(QString::fromUtf8("pushButton6"));

        gridLayout->addWidget(pushButton6, 1, 2, 1, 1);

        pushButton5 = new QPushButton(groupBox_5);
        pushButton5->setObjectName(QString::fromUtf8("pushButton5"));

        gridLayout->addWidget(pushButton5, 1, 1, 1, 1);

        pushButton3 = new QPushButton(groupBox_5);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));

        gridLayout->addWidget(pushButton3, 2, 2, 1, 1);

        pushButton2 = new QPushButton(groupBox_5);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));

        gridLayout->addWidget(pushButton2, 2, 1, 1, 1);

        pushButton1 = new QPushButton(groupBox_5);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));

        gridLayout->addWidget(pushButton1, 2, 0, 1, 1);

        pushButton0 = new QPushButton(groupBox_5);
        pushButton0->setObjectName(QString::fromUtf8("pushButton0"));

        gridLayout->addWidget(pushButton0, 3, 0, 1, 1);

        pushButtonVirgule = new QPushButton(groupBox_5);
        pushButtonVirgule->setObjectName(QString::fromUtf8("pushButtonVirgule"));

        gridLayout->addWidget(pushButtonVirgule, 3, 2, 1, 1);

        pushButtonMult = new QPushButton(groupBox_5);
        pushButtonMult->setObjectName(QString::fromUtf8("pushButtonMult"));

        gridLayout->addWidget(pushButtonMult, 1, 3, 1, 1);

        pushButtonMoins = new QPushButton(groupBox_5);
        pushButtonMoins->setObjectName(QString::fromUtf8("pushButtonMoins"));

        gridLayout->addWidget(pushButtonMoins, 2, 3, 1, 1);

        pushButtonPlus = new QPushButton(groupBox_5);
        pushButtonPlus->setObjectName(QString::fromUtf8("pushButtonPlus"));

        gridLayout->addWidget(pushButtonPlus, 3, 3, 1, 1);

        pushButtonDollar = new QPushButton(groupBox_5);
        pushButtonDollar->setObjectName(QString::fromUtf8("pushButtonDollar"));

        gridLayout->addWidget(pushButtonDollar, 3, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout);


        horizontalLayout_5->addWidget(groupBox_5);


        layoutClavier->addLayout(horizontalLayout_5);

        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setEnabled(true);
        groupBox_7->setMaximumSize(QSize(16777215, 60));
        verticalLayout_2 = new QVBoxLayout(groupBox_7);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spinBoxNbElemPile = new QSpinBox(groupBox_7);
        spinBoxNbElemPile->setObjectName(QString::fromUtf8("spinBoxNbElemPile"));

        verticalLayout_2->addWidget(spinBoxNbElemPile);


        layoutClavier->addWidget(groupBox_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 101, 68));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButtonEntier = new QRadioButton(verticalLayoutWidget);
        radioButtonEntier->setObjectName(QString::fromUtf8("radioButtonEntier"));
        radioButtonEntier->setChecked(true);

        verticalLayout_3->addWidget(radioButtonEntier);

        radioButtonRationnel = new QRadioButton(verticalLayoutWidget);
        radioButtonRationnel->setObjectName(QString::fromUtf8("radioButtonRationnel"));

        verticalLayout_3->addWidget(radioButtonRationnel);

        radioButtonReel = new QRadioButton(verticalLayoutWidget);
        radioButtonReel->setObjectName(QString::fromUtf8("radioButtonReel"));

        verticalLayout_3->addWidget(radioButtonReel);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 181, 71));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        radioButtonAvecComplexes = new QRadioButton(verticalLayoutWidget_2);
        radioButtonAvecComplexes->setObjectName(QString::fromUtf8("radioButtonAvecComplexes"));

        verticalLayout_4->addWidget(radioButtonAvecComplexes);

        radioButtonSansComplexes = new QRadioButton(verticalLayoutWidget_2);
        radioButtonSansComplexes->setObjectName(QString::fromUtf8("radioButtonSansComplexes"));
        radioButtonSansComplexes->setChecked(true);

        verticalLayout_4->addWidget(radioButtonSansComplexes);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayoutWidget_3 = new QWidget(groupBox_6);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 101, 68));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        radioButtonDegres = new QRadioButton(verticalLayoutWidget_3);
        radioButtonDegres->setObjectName(QString::fromUtf8("radioButtonDegres"));
        radioButtonDegres->setChecked(true);

        verticalLayout_9->addWidget(radioButtonDegres);

        radioButtonRadians = new QRadioButton(verticalLayoutWidget_3);
        radioButtonRadians->setObjectName(QString::fromUtf8("radioButtonRadians"));

        verticalLayout_9->addWidget(radioButtonRadians);


        horizontalLayout_2->addWidget(groupBox_6);


        layoutClavier->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(layoutClavier);


        verticalLayout_5->addLayout(horizontalLayout);

        CalculatricePolonaise->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CalculatricePolonaise);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        CalculatricePolonaise->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(actionQuitter);
        menu->addAction(actionA_propos);
        menu->addAction(actionA_propos_de_Qt);
        menuEdition->addAction(actionAnnuler);
        menuEdition->addAction(actionRetablir);

        retranslateUi(CalculatricePolonaise);

        QMetaObject::connectSlotsByName(CalculatricePolonaise);
    } // setupUi

    void retranslateUi(QMainWindow *CalculatricePolonaise)
    {
        CalculatricePolonaise->setWindowTitle(QApplication::translate("CalculatricePolonaise", "CalculatricePolonaise", 0, QApplication::UnicodeUTF8));
        actionA_propos->setText(QApplication::translate("CalculatricePolonaise", "A propos", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("CalculatricePolonaise", "Quitter", 0, QApplication::UnicodeUTF8));
        actionA_propos_de_Qt->setText(QApplication::translate("CalculatricePolonaise", "A propos de Qt", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("CalculatricePolonaise", "Annuler", 0, QApplication::UnicodeUTF8));
        actionRetablir->setText(QApplication::translate("CalculatricePolonaise", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        checkBoxClavier->setText(QApplication::translate("CalculatricePolonaise", "Afficher le clavier", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CalculatricePolonaise", "Pile", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("CalculatricePolonaise", "Op\303\251rations g\303\251n\303\251rales", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("CalculatricePolonaise", "CANCEL", 0, QApplication::UnicodeUTF8));
        pushButtonPush->setText(QApplication::translate("CalculatricePolonaise", "PUSH", 0, QApplication::UnicodeUTF8));
        pushButtonExp->setText(QApplication::translate("CalculatricePolonaise", "EXPRESSION", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CalculatricePolonaise", "Op\303\251rations sur la pile", 0, QApplication::UnicodeUTF8));
        pushButtonSwap->setText(QApplication::translate("CalculatricePolonaise", "SWAP", 0, QApplication::UnicodeUTF8));
        pushButtonSum->setText(QApplication::translate("CalculatricePolonaise", "SUM", 0, QApplication::UnicodeUTF8));
        pushButtonMean->setText(QApplication::translate("CalculatricePolonaise", "MEAN", 0, QApplication::UnicodeUTF8));
        pushButtonClear->setText(QApplication::translate("CalculatricePolonaise", "CLEAR", 0, QApplication::UnicodeUTF8));
        pushButtonDup->setText(QApplication::translate("CalculatricePolonaise", "DUP", 0, QApplication::UnicodeUTF8));
        pushButtonDrop->setText(QApplication::translate("CalculatricePolonaise", "DROP", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("CalculatricePolonaise", "Op\303\251rations", 0, QApplication::UnicodeUTF8));
        pushButtonPow->setText(QApplication::translate("CalculatricePolonaise", "POW", 0, QApplication::UnicodeUTF8));
        pushButtonMod->setText(QApplication::translate("CalculatricePolonaise", "MOD", 0, QApplication::UnicodeUTF8));
        pushButtonSign->setText(QApplication::translate("CalculatricePolonaise", "SIGN", 0, QApplication::UnicodeUTF8));
        pushButtonSin->setText(QApplication::translate("CalculatricePolonaise", "SIN", 0, QApplication::UnicodeUTF8));
        pushButtonCos->setText(QApplication::translate("CalculatricePolonaise", "COS", 0, QApplication::UnicodeUTF8));
        pushButtonTan->setText(QApplication::translate("CalculatricePolonaise", "TAN", 0, QApplication::UnicodeUTF8));
        pushButtonSinh->setText(QApplication::translate("CalculatricePolonaise", "SINH", 0, QApplication::UnicodeUTF8));
        pushButtonCosh->setText(QApplication::translate("CalculatricePolonaise", "COSH", 0, QApplication::UnicodeUTF8));
        pushButtonTanh->setText(QApplication::translate("CalculatricePolonaise", "TANH", 0, QApplication::UnicodeUTF8));
        pushButtonSqr->setText(QApplication::translate("CalculatricePolonaise", "SQR", 0, QApplication::UnicodeUTF8));
        pushButtonCube->setText(QApplication::translate("CalculatricePolonaise", "CUBE", 0, QApplication::UnicodeUTF8));
        pushButtonEval->setText(QApplication::translate("CalculatricePolonaise", "EVAL", 0, QApplication::UnicodeUTF8));
        pushButton7->setText(QApplication::translate("CalculatricePolonaise", "7", 0, QApplication::UnicodeUTF8));
        pushButton8->setText(QApplication::translate("CalculatricePolonaise", "8", 0, QApplication::UnicodeUTF8));
        pushButton9->setText(QApplication::translate("CalculatricePolonaise", "9", 0, QApplication::UnicodeUTF8));
        pushButtonDiv->setText(QApplication::translate("CalculatricePolonaise", "/", 0, QApplication::UnicodeUTF8));
        pushButton4->setText(QApplication::translate("CalculatricePolonaise", "4", 0, QApplication::UnicodeUTF8));
        pushButton6->setText(QApplication::translate("CalculatricePolonaise", "6", 0, QApplication::UnicodeUTF8));
        pushButton5->setText(QApplication::translate("CalculatricePolonaise", "5", 0, QApplication::UnicodeUTF8));
        pushButton3->setText(QApplication::translate("CalculatricePolonaise", "3", 0, QApplication::UnicodeUTF8));
        pushButton2->setText(QApplication::translate("CalculatricePolonaise", "2", 0, QApplication::UnicodeUTF8));
        pushButton1->setText(QApplication::translate("CalculatricePolonaise", "1", 0, QApplication::UnicodeUTF8));
        pushButton0->setText(QApplication::translate("CalculatricePolonaise", "0", 0, QApplication::UnicodeUTF8));
        pushButtonVirgule->setText(QApplication::translate("CalculatricePolonaise", ",", 0, QApplication::UnicodeUTF8));
        pushButtonMult->setText(QApplication::translate("CalculatricePolonaise", "*", 0, QApplication::UnicodeUTF8));
        pushButtonMoins->setText(QApplication::translate("CalculatricePolonaise", "-", 0, QApplication::UnicodeUTF8));
        pushButtonPlus->setText(QApplication::translate("CalculatricePolonaise", "+", 0, QApplication::UnicodeUTF8));
        pushButtonDollar->setText(QApplication::translate("CalculatricePolonaise", "$", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("CalculatricePolonaise", "Nombre d'\303\251l\303\251ments de la pile \303\240 afficher", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CalculatricePolonaise", "Mode constante", 0, QApplication::UnicodeUTF8));
        radioButtonEntier->setText(QApplication::translate("CalculatricePolonaise", "Entier", 0, QApplication::UnicodeUTF8));
        radioButtonRationnel->setText(QApplication::translate("CalculatricePolonaise", "Rationnel", 0, QApplication::UnicodeUTF8));
        radioButtonReel->setText(QApplication::translate("CalculatricePolonaise", "R\303\251el", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CalculatricePolonaise", "Complexes", 0, QApplication::UnicodeUTF8));
        radioButtonAvecComplexes->setText(QApplication::translate("CalculatricePolonaise", "Avec", 0, QApplication::UnicodeUTF8));
        radioButtonSansComplexes->setText(QApplication::translate("CalculatricePolonaise", "Sans", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("CalculatricePolonaise", "Unit\303\251 des degr\303\251s", 0, QApplication::UnicodeUTF8));
        radioButtonDegres->setText(QApplication::translate("CalculatricePolonaise", "Degr\303\251s", 0, QApplication::UnicodeUTF8));
        radioButtonRadians->setText(QApplication::translate("CalculatricePolonaise", "Radians", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("CalculatricePolonaise", "Fichier", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("CalculatricePolonaise", "?", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("CalculatricePolonaise", "Edition", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CalculatricePolonaise: public Ui_CalculatricePolonaise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATRICEPOLONAISE_H
