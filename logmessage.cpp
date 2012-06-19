#include "logmessage.h"

LogMessage::LogMessage(const QString& message, int priorite) : mMessage(message), mPriorite(priorite)
{
}

const QString LogMessage::toString() const {
    QDateTime dateTime = QDateTime::currentDateTime();
    return "Date : " + dateTime.toString() + "\nPriorité : " + QString::number(mPriorite) + "\nMessage : " + mMessage + "\n";
}
