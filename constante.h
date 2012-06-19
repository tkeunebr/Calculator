#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QString>


/**
 * Classe abstraite representant une Constante generique et les elements communs des Constantes de l'application
 * Les methodes sont virtuelles pures et permettent la manipulation de constantes en dehors de la classe sans
 * connaitre leur type exact
 */


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

    virtual ~Constante() {}
};

#endif // CONSTANTE_H
