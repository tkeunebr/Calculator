#include "logsystem.h"

LogSystem* LogSystem::mInstance = 0;

LogSystem* LogSystem::newInstance(const QString& cheminFichier) {
    if (mInstance == 0) {
        mInstance = new LogSystem(cheminFichier);
    }
    return mInstance;
}

LogSystem::LogSystem(const QString& cheminFichier) : mFichier(cheminFichier)
{
    mFichier.open(QIODevice::WriteOnly);
    mFichier.close();
}

void LogSystem::deleteInstance() {
    if (mInstance != 0) {
        delete mInstance;
    }
    mInstance = 0;
}

void LogSystem::addMessage(const LogMessage& lm) {
    mMessages.push(lm);
    qDebug(lm.toString().toStdString().c_str());
    mFichier.open(QIODevice::Append);
    mFichier.write(lm.toString().toStdString().c_str());
    mFichier.write("\n");
    mFichier.close();
}

void LogSystem::addMessage(const QString& message, int priorite) {
    LogMessage lm(message, priorite);
    addMessage(lm);
}
