#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QString>
#include <QDateTime>
/**
 * Classe representant un message de log. Contient un message et une priorite, la plus haute etant la plus forte.
 */
class LogMessage
{
    private:
        QString mMessage;
        int mPriorite;
    public:
        LogMessage(const QString& message = "", int priorite = 1);

        // Getters
        const QString getMessage() const { return mMessage; }
        int getPriorite() const { return mPriorite; }

        const QString toString() const;
};

#endif // LOGMESSAGE_H
