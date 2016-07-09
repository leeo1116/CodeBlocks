#include <iostream>
#include "Leetcode.h"


using namespace std;
int findMedian_logn(int vec1[], int n1, int vec2[], int n2);
int maxCoinsDP(vector<int> &iNums);

int main(int argc, char **args)
{
    int courses = 2;
    pair<int, int> p1 = make_pair(1, 0);
    pair<int, int> p2 = make_pair(0, 1);
    vector<pair<int, int>> pre = {p1, p2};
    Solution s;
    cout << s.CanFinishBFS(courses, pre) << " " << endl;
    cout << s.CanFinishDFS(courses, pre) << " " << endl;
    WordDictionary wd;
    // wd.AddWord("a");
    cout << wd.Search("a") << endl;

    // cout << Solution::Add("109", "37") << endl;
    cout << s.IsAdditiveNumber("112358") << endl;
    vector<string> repeatDNA = s.FindRepeatedDNA_Sequences("AGT");
    for(auto seq : repeatDNA)
        cout << seq << " ";
    vector<int> nums = {4, 1, 3, 2, 3, 5, 3};
    cout << s.FindDuplicate(nums) << endl;
    vector<int> nums2 = {7,9,8,0,7,1,3,5};
    cout << s.MaxCoins(nums2) << endl;
    cout << maxCoinsDP(nums2) << endl;
//    int vec1[] = {3, 8};
//    int vec2[] = {4, 5};
//    int n1 = sizeof(vec1)/sizeof(1);
//    int n2 = sizeof(vec1)/sizeof(1);
//    int n3;
//     n3 = findMedian_logn(vec1, n1, vec2, n2);
//    cout << "Median: " << n3 << endl;
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
