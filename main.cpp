////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#include <QApplication>
#include "complex_widget.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // make the QtApplication
    ComplexWidget widget; // make the widget

    widget.show(); // show it on the screen
    return app.exec(); // enter the event loop
}
