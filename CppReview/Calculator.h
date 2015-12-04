#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

using namespace std;

class Calculator
{
public: // External code can call these methods
    Calculator();
    ~Calculator();

    float add(float a, float b); // Can also define method here inside class, in-line
    float divide(float numerator, float denominator);
    bool GetAllowNegative();
    void SetAllowNegative(bool doAllow);

protected: // External code cannot access these members
    bool allowNegative;
};

#endif // CALCULATOR_H_INCLUDED
