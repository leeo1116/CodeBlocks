#include "CoolSaying.h"
#include <iostream>
#include <string>

using namespace std;

CoolSaying::CoolSaying(string initSaying, char s, double h, double w)
: sex(s),
height(h),
weight(w)

{
    //ctor
    cout << initSaying << endl;
    cout << "sex is : " << s << endl;
    cout << "height is : " << height << endl;
    cout << "weight is : " << weight << endl;
}

CoolSaying::~CoolSaying()
{
    //dtor
    cout << "Execute deconstructor at the end of the program" << endl;
}

void CoolSaying::SayCoolThing() const
{
    cout << "Say cool thing" << endl;
}
