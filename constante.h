#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QString>

class Constante
{
public:
    virtual void addChiffre(int chiffre) = 0;
    virtual const QString toString() const = 0;

    // Setters
    virtual void setSlashEntre(bool slashEntre = true) = 0;
    virtual void setDollarEntre(bool dollarEntre = true) = 0;
    virtual void setVirguleEntree(bool virguleEntree = true) = 0;

    // Getters
    virtual bool isDollarEntre() const = 0;
};

#endif // CONSTANTE_H
