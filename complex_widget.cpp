////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#include "complex_widget.hpp"

#include <QGridLayout>
#include <cmath> // sqrt
#include <complex> // std::complex and std::arg

ComplexWidget::ComplexWidget(QWidget *parent) : QWidget(parent) {
    realEntry = new QLineEdit;  // creates the real entry box
    imagEntry = new QLineEdit;  // creates the imaginary entry box
    showMagnitude = new QLabel("0.0"); // creates the magnitude display wirh a starting value of 0.0
    showPhase = new QLabel("0.0"); // creates the phase display with a startting value of 0.0
    updateButton = new QPushButton("Update"); // creates the update button

    QGridLayout *layout = new QGridLayout;  // grid of 4 columns and 3 rows
    layout->addWidget(new QLabel("Real:"), 0, 0); // row 0, col 0
    layout->addWidget(realEntry, 0, 1);
    layout->addWidget(new QLabel("Magnitude:"), 1, 0);
    layout->addWidget(showMagnitude, 1, 1);
    layout->addWidget(new QLabel("Imaginary"), 0, 2);
    layout->addWidget(imagEntry, 0, 3);
    layout->addWidget(new QLabel("Phase:"), 1, 2);
    layout->addWidget(showPhase, 1, 3);
    layout->addWidget(updateButton, 2, 3);
    setLayout(layout);
    setWindowTitle("Exercise 9"); // title
    
    // Provide a pushbutton of type QPushButton to update the display of the magnitude and phase. 
    // Each time the pushbutton is pressed, the display must be updated using the current 
    // values of the real and imaginary part.
    connect(updateButton, &QPushButton::clicked, this, &ComplexWidget::updateCalculation);
}

double ComplexWidget::getRealPart() {
    return realEntry->text().toDouble(); // convert box's text to a double
}
double ComplexWidget::getImaginaryPart() {
    return imagEntry->text().toDouble();
}
double ComplexWidget::getMagnitude() {
    double real = getRealPart();
    double imag = getImaginaryPart();
    return std::sqrt((real * real) + (imag * imag)); 
}
double ComplexWidget::getPhase() {
    std::complex<double> p(getRealPart(), getImaginaryPart());
    return std::arg(p);
}

void ComplexWidget::updateCalculation() {
    showMagnitude->setText(QString::number(getMagnitude())); // convert magnitude to text
    showPhase->setText(QString::number(getPhase())); // convert phase to text 
}