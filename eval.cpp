#include "operationunaire.h"
#include "operationbinaire.h"
#include "evalexception.h"
#include "divexception.h"

Eval::Eval(Constante &pc, int pModeConstante, int pModeComplexes, int pModeDegres) : OperationUnaire(pc, pModeConstante, pModeComplexes, pModeDegres)
{
}

Constante* Eval::getValue() const {
    Expression* exp = dynamic_cast<Expression*>(c);
    QStack<Constante*> p;
    if (exp != NULL){
        int i = 0;
        QString s = exp->getExp();
        Constante * result = 0;
        while(i<s.length()){
            //on passe les espaces;
            if(s[i] == ' '){
                if(result != 0){
                    p.push(result);
                    result = 0;
                }
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                if(result == 0)result = Addition(Rationnel(0),Rationnel(0),mModeConstante, mModeComplexes).getValue();
                result->addChiffre(s[i].toAscii() - '0');
            }
            else if(s[i] == '$'){
                if(result == 0) throw EvalException("$ mal placé");
                result->setDollarEntre();
            }
            else if(s[i] == '/'){
                if(result != 0){
                    result->setSlashEntre();
                }
                else{
                    if(p.size() < 2) throw EvalException("Pas assez d'opérandes pour /");
                    Constante *op2 = p.pop(),  *op1 = p.pop();
                    try{
                        result = Division(*op1,*op2,mModeConstante,mModeComplexes).getValue();
                    }
                    catch(DivException e){
                        throw EvalException("division par zéro");
                    }

                    delete op1;
                    delete op2;
                    p.push(result);
                    result = 0;
                }
            }
            else if(s[i] == ',' || s[i] == '.'){
                if(result == 0) throw EvalException(", ou . mal placé");
                result->setVirguleEntree();
            }
            else if(s[i] == '+'){
                if(result!=0){
                    p.push(result);
                    result = 0;
                }
                if(p.size() < 2) throw EvalException("Pas assez d'opérandes pour +");
                Constante *op1 = p.pop(),  *op2 = p.pop();
                result = Addition(*op1,*op2,mModeConstante,mModeComplexes).getValue();
                delete op1;
                delete op2;
                p.push(result);
                result = 0;
            }
            else if(s[i] == '-'){
                if(result!=0){
                    p.push(result);
                    result = 0;
                }
                if(p.size() < 2) throw EvalException("Pas assez d'opérandes pour -");
                Constante *op2 = p.pop(),  *op1 = p.pop();
                result = Soustraction(*op1,*op2,mModeConstante,mModeComplexes).getValue();
                delete op1;
                delete op2;
                p.push(result);
                result = 0;
            }
            else if(s[i] == '*'){
                if(result!=0){
                    p.push(result);
                    result = 0;
                }
                if(p.size() < 2) throw EvalException("Pas assez d'opérandes pour *");
                Constante *op2 = p.pop(),  *op1 = p.pop();
                result = Multiplication(*op1,*op2,mModeConstante,mModeComplexes).getValue();
                delete op1;
                delete op2;
                p.push(result);
                result = 0;
            }
            else{
                throw EvalException("Caractère inconnu");
            }
            i++;
        }
        if(result!=0)p.push(result);
        if(p.size() > 1) throw EvalException("Il manque un opérateur.");
        if(p.size() < 1) throw EvalException("Pile d'évaluation vide.");
        return p.at(0);
    }
    else throw TypeConstanteException("Ceci n'est pas une expression");
}

