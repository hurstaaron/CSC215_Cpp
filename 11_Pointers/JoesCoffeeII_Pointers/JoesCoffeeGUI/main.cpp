#include "JoesCoffeeGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    JoesCoffeeGUI window;
    window.show();
    return app.exec();
}
