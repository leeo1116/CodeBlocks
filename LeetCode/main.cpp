#include <iostream>

using namespace std;
int findMedian_logn(int vec1[], int n1, int vec2[], int n2);

int main()
{
    int vec1[] = {3, 8};
    int vec2[] = {4, 5};
    int n1 = sizeof(vec1)/sizeof(1);
    int n2 = sizeof(vec1)/sizeof(1);
    int n3;
    n3 = findMedian_logn(vec1, n1, vec2, n2);
    cout << "Median: " << n3 << endl;
    return 0;
}

int findMedian_logn(int vec1[], int n1, int vec2[], int n2)
{
    int m1 = (n1-1) / 2, m2 = (n2-1) / 2;
    if(n1 == 1)
    {//递归结束条件
        if(n2 == 1)
            return vec1[0] < vec2[0] ? vec1[0] : vec2[0];
        if(n2 % 2 == 0)
        {
            if(vec1[0] >= vec2[m2+1])
                return vec2[m2+1];
            else if(vec1[0] <= vec2[m2])
                return vec2[m2];
            else return vec1[0];
        }
        else
        {
            if(vec1[0] >= vec2[m2])
                return vec2[m2];
            else if(vec1[0] <= vec2[m2-1])
                return vec2[m2-1];
            else return vec1[0];
        }
    }
    else if(n2 == 1)
    {//递归结束条件
        if(n1 % 2 == 0)
        {
            if(vec2[0] >= vec1[m1+1])
                return vec1[m1+1];
            else if(vec2[0] <= vec1[m1])
                return vec1[m1];
            else return vec2[0];
        }
        else
        {
            if(vec2[0] >= vec1[m1])
                return vec1[m1];
            else if(vec2[0] <= vec1[m1-1])
                return vec1[m1-1];
            else return vec2[0];
        }
    }
    else
    {
        int cutLen = n1/2 > n2/2 ? n2/2 : n1/2;//注意每次减去短数组的一半，如果数组长度n是奇数，一半是指n-1/2
        if(vec1[m1] == vec2[m2])return vec1[m1];
        else if(vec1[m1] < vec2[m2])
            return findMedian_logn(&vec1[cutLen], n1-cutLen, vec2, n2-cutLen);
        else
            return findMedian_logn(vec1, n1-cutLen, &vec2[cutLen], n2-cutLen);
    }
}
