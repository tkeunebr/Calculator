#include <QtGui/QApplication>
#include "calculatricepolonaise.h"
#include <QTextStream>
#include <cstdio>

QTextStream cout(stdout, QIODevice::WriteOnly);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatricePolonaise w;
    w.show();
    
    return a.exec();
}
