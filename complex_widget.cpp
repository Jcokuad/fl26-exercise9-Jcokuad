////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#include "complex_widget.hpp"

#include <QGridLayouts>
#include <cmath>

ComplexWidget::ComplexWidget(QWidget *parent) : QWidget(parent) {
    realEntry = new QLineEdit;  // creates the real entry box
    imagEntry = new QLineEdit;  // creates the imaginary entry box
    showMagnitude = new QLabel("0.0"); // creates the magnitude display wirh a starting value of 0.0
    showPhase = new QLabel("0.0"); // creates the phase display with a startting value of 0.0
    buttonPress = new QPushButton("Update"); // creates the update button

    QGridLayout *layout = new QGridLayout;  // grid
}