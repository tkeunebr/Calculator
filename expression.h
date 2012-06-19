#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "constante.h"
/**
 * Classe decrivant une constante de type expression. Reimplemente les mehtodes de Constante.
 */

class Expression : public Constante
{
public:
    Expression(QString exp = "");
    const QString toString() const{ return "\"" + mExp + "\""; }

    virtual void addChiffre(int chiffre){}

    // Setters
    virtual void setSlashEntre(bool slashEntre = true){}
    virtual void setDollarEntre(bool dollarEntre = true){}
    virtual void setVirguleEntree(bool virguleEntree = true){}

    // Getters
    virtual bool isDollarEntre() const{ return false;}
    QString getExp() const {return mExp;}
private:
    QString mExp;

};

#endif // EXPRESSION_H
