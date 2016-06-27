#include <iostream>
#include "Calculator.h"


Calculator::Calculator()
{
    cout << "Entering Calculator" << endl;
    allowNegative = false;
}


Calculator::~Calculator()
{
    // Nothing to do in terms of cleanup
    cout << "Exiting Calculator" << endl;
}


float Calculator::add(float a, float b)
{
    if (!allowNegative && (a < 0 || b < 0))
    {
        std::cout << "Illegal number" << endl;
        return 0;
    }
    return a+b;
}


float Calculator::divide(float numerator, float denominator)
{
    if ((!allowNegative && (numerator < 0 || numerator < 0)) || (denominator == 0))
    {
        std::cout << "Illegal number" << endl;
        return 0;
    }
    return (numerator/denominator);
}


bool Calculator::GetAllowNegative()
{
    return allowNegative;
}


void Calculator::SetAllowNegative(bool doAllow)
{
    allowNegative = doAllow;
}
