#include <QtGui/QApplication>
#include "calculatricepolonaise.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatricePolonaise w;
    w.show();
    
    return a.exec();
}
