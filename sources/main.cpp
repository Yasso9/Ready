#include <iostream>

#include <QtWidgets/QApplication>

#include "notepad.hpp"

int main( int argc, char ** argv )
{
    QApplication application { argc, argv };

    Notepad w {};
    w.show();

    return application.exec();
}