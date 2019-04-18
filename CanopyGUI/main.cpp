#include "SearchWindow.h"
#include "WelcomeWindow.h"
#include "StartWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    WelcomeWindow w;
    StartWindow w;
    w.show();

    return a.exec();
}
