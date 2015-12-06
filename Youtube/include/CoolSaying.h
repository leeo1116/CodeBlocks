#ifndef COOLSAYING_H
#define COOLSAYING_H

#include <string>
using namespace std;

class CoolSaying
{
    public:
        int age;
        CoolSaying(string initSaying, char s, double h, double w);
        virtual ~CoolSaying();
        void SayCoolThing() const;
    protected:
    private:
        char sex;
        double height;
        double weight;

};

#endif // COOLSAYING_H
