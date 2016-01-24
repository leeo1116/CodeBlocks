#include <iostream>
#include <cstddef>
#include <stdlib.h>


using namespace std;


struct fraction
{
    int num;
    int denum;
};


void Swap(void *p1, void *p2, int typeSize);


int main(int argc, char **argv)
{
    // Dynamically allocate matrix using malloc and new
    int row = 3, col = 2;
    int **pNewMatrix0 = new int *[row];
    int **pNewMatrix1 = (int **)malloc(row*sizeof(int));

    // Initialization for matrix
    for(int i = 0; i < row; i++)
    {
        pNewMatrix0[i] = new int [col];
        pNewMatrix1[i] = (int *)malloc(col*sizeof(int));
        for(int j = 0; j < col; j++)
        {
            pNewMatrix0[i][j] = i+j;
            pNewMatrix1[i][j] = i+j;
        }
    }

    // Print matrix
    for(int i = 0; i < row; i++)
    {
        cout << endl;
        for(int j = 0; j < col; j++)
        {
            cout << pNewMatrix0[i][j] << " ";
            cout << pNewMatrix1[i][j] << " ";
        }
    }
    cout << endl;

    // Type conversion between int and float, short and float
    int i = 37;
    float f0 = *(float *)&i;

    float f1 = 7.0;
    short s = *(short *)&f1;  // s should be non-zero for big-endian machine

    cout << f0 << endl << s << endl;
    fraction pi;
    pi.num = 22;
    pi.denum = 7;

    fraction *pi0 = ((fraction *)&(pi.denum));
    pi0->num = 12;
    pi0->denum = 33;
    cout << &pi << " " << pi0 << endl;
    cout << pi.denum << " " << pi0->num << endl;
    cout << pi0->num << " " << pi0->denum << endl;
    cout << pi0[0].denum << endl;
    cout << (&pi)[1].num << endl;  // add 1 unit to address of pi
    return 0;

    // Array
    int a[10];
    a[0] = 44;
    a[9] = 100;
    a[10] = 1;
    a[25] = 9;
    a[-4] = 6;


}


// Pointer
void Swap(void *p1, void *p2, int typeSize)
{
    char *pBuffer = (char *)malloc(sizeof(char)*typeSize);
    memcpy(pBuffer, p1, typeSize);
}
