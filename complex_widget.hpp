////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#ifndef COMPLEX_WIDGET_H
#define COMPLEX_WIDGET_H

#include <QWidget> // base class for Qt elements
#include <QLineEdit> // text entry box
#include <QLabal> // text display box
#include <QPushButton> // button

// class ComplexWidget in complex_widget.hpp that inherits from class QWidget and models a complex number
class ComplexWidget : public QWidget { 
    Q_OBJECT

public:
    ComplexWidget(QWidget *parent = nullptr); // constructor that builds the window

// The class should have public member functions getRealPart, getImaginaryPart, getMagnitude, and getPhase, 
// returning a double in each case. 
    double getRealPart(); // returns the num typed in the real part box
    double getImagPart(); // returns the num typed in the imaginary part box
    double getMagnitude(); // returns the magnitude of the complex num
    double getPhase(); // returns the phase of the complex num

private slots:
    void updateCalculation();  // runs when the user clicks the update button


private:
    QLineEdit *realEntry; // real entry box
    QLineEdit *imagEntry; // imaginary entry box
    QLabel *showMagnitude; // shows the magnitude
    QLabel *showPhase; // shows the phase
    QPushButton *buttonPress; // Update button
}


#endif
