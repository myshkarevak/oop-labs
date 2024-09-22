#include "calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Calculator window;
    window.show();
    return application.exec();
}
