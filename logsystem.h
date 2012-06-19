#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QStack>
#include <QFile>
#include <QDebug>
#include "logmessage.h"
/**
 * Classe implementant le design pattern Singleton. Permet de gerer l'ecriture d'un log dans la console et dans un fichier. Utilise pour cela des LogMessage.
 */
class LogSystem
{
    private:
        LogSystem(const QString& cheminFichier);
        static LogSystem* mInstance;
        QStack<LogMessage> mMessages;
        QFile mFichier;
    public:
        static LogSystem* newInstance(const QString& cheminFichier = "file.log");
        void deleteInstance();
        void addMessage(const LogMessage& lm);
        void addMessage(const QString& message = "", int priorite = 1);
};

#endif // LOGSYSTEM_H
