#include <iostream>
#include <string>
#include "Print.h"
#include "CoolSaying.h"
#include "SingSong.h"

using namespace std;

int main(int nargin, char** args)
{
    string hi = "how's it going";
    const char sex = 'F';
    const string printString = "See u next time";
    CoolSaying saying1(hi, sex, 180.1, 68.5);
    SingSong singing1;
    saying1.SayCoolThing();
    //singing1.SayCoolThing();
    PrintSomething(printString);  //no need to declare as a constant function, unless in a class
    return 0;
}



