#ifndef LEETCODE_H_INCLUDED
#define LEETCODE_H_INCLUDED

#include <algorithm>
#include <cctype>
#include <climits>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


using namespace std;


class Solution {
private:
    struct TreeLinkNode{
        int val;
        TreeLinkNode *left, *right, *next;
        TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){};
    };
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL){}
    };
    TreeNode *first = NULL, *second = NULL, *prev = new TreeNode(INT_MIN);
    bool HasCycleDFS(unordered_map<int, unordered_set<int>> &graph, int startVertex, vector<bool> &visited, vector<bool> &onPath);
    bool HasCycleDFS_II(unordered_map<int, unordered_set<int>> &graph, int startVertex, vector<bool> &visited, vector<bool> &onPath, vector<int> &courseOrder);
    string IntToString(int i);
    void AddNextWords(string beginWord, unordered_set<string> &wordsList, queue<string> &toVisit);
    int GCD(int a, int b);
    bool Check(string num1, string num2, string num);
    int Str2Int(string s);
    void N_QueensDFS(unsigned i, int &cnt, vector<bool> &col, vector<bool> &diag, vector<bool> &offDiag);
    int PowMod(int a, int k, const int base);
    bool SearchLadders(unordered_set<string> &startWords, unordered_set<string> &endWords, unordered_set<string> &wordList,
                       unordered_map<string, vector<string>> &children, bool flip);
    void GenLadders(string &startWord, string &endWord, unordered_map<string, vector<string>> &children,
                    vector<string> &ladder, vector<vector<string>> &ladders);
    static bool CompareFirst(const pair<int, int> &i, const pair<int, int> &j);
    void InorderTraversal(TreeNode *root);
    void AddOperatorsDFS(vector<string> &exps, const string &num, const int target, string cur,
                         int pos, const long cv, const long pv, const char op);
    // 374. guess number higher or lower
    int Guess(int num);
    int GuessHelper(int num, int low, int high);


public:
    bool CanFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites);
    bool CanFinishDFS(int numCourses, vector<pair<int, int>>& prerequisites);
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
    bool ContainsDuplicatesIII(vector<int>& nums, int k, int t);
    string LargestNumber(vector<int> &nums);
    int LadderLength(string beginWord, string endWord, unordered_set<string>& wordList);
    bool CanMeasureWater(int x, int y, int z);
    vector<vector<int>> FourSum(vector<int> &nums, int target);
    bool IsAdditiveNumber(string num);
    static string Add(string s1, string s2);
    vector<string> FindRepeatedDNA_Sequences(string s);
    bool IsPerfectSquare(int num);
    vector<int> FindMinHeightTree(int n, vector<pair<int, int>> &edges);
    vector<int> LargestDivisibleSubset(vector<int> &nums);
    int TotalN_Queens(int n);
    int FindDuplicate(vector<int> &nums);
    int MaxCoins(vector<int> &nums);
    string NumToWords(int num);
    string IntToStr(int n, const char * const below20[], const char * const below100[]);
    int Calculate(string s);
    int SuperPow(int a, vector<int> &b);
    int CountDigitOne(int n);
    int FindMinII(vector<int> &nums);
    int LongestConsecutive(vector<int> &nums);
    vector<vector<string>> FindLadders(string beginWord, string endWord, unordered_set<string> &wordList);
    int DistinctNum(string s, string t);
    bool IsScramble(string s1, string s2);
    void Connect(TreeLinkNode *root);
    vector<int> MaxSlideWindow(vector<int> &nums, int k);
    int MaxSumSubmatrix(vector<vector<int>> &matrix, int k);
    int MaxEnvelopes(vector<pair<int, int>> &envelopes);
    int MaxGap(vector<int> &nums);
    void RecoverTree(TreeNode *root);
    // 282. expression add operator
    vector<string> AddOperators(string num, int target);
    // 188. best time to buy and sell stock IV
    int MaxProfit(int k, vector<int>& prices);
    bool IsInterleave(string s1, string s2, string s3);
    // 132. palindrome partitioning II
    int MinCut(string s);
    // 174. dungeon game
    int CalculateMinimumHP(vector<vector<int>> &dungeon);
    // 214. shortest palindrome
    string ShortestPalindrome(string s);
    // 371. sum of two integers
    int GetSum(int a, int b);
    // 374. guess number higher or lower
    int GuessNumber(int n);
    int MaxWiggleLength(vector<int> &nums);
};


class TrieNode{
public:
    bool isKey;     // is complete word from root to current node
    TrieNode *children[26];

    TrieNode(): isKey(false){
        memset(children, 0, sizeof(TrieNode *)*26);
    }

};


// 211. add and search word
class WordDictionary{
private:
    TrieNode *root;
    bool Query(const char *word, TrieNode *root);

public:
    WordDictionary(){
        root = new TrieNode();
    }
    void AddWord(string word);
    bool Search(string word);
};


class NumMatrix {
private:
    int row, col;
    vector<vector<int>> sums;

public:
    NumMatrix(vector<vector<int>> &matrix);
    int SumRegion(int row1, int col1, int row2, int col2);
};



struct UndirectedGraphNode {
private:
    int label;
    vector<UndirectedGraphNode *> neighbors;
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> graphMap;
public:
    UndirectedGraphNode(int x) : label(x) {};
    UndirectedGraphNode *CloneGraphBFS(UndirectedGraphNode *startNode);
    UndirectedGraphNode *CloneGraphDFS(UndirectedGraphNode *startNode);
};


struct Interval{
    int start;
    int stop;
    Interval() : start(0), stop(0) {}
    Interval(int s, int e) : start(s), stop(e) {}
};


class SummaryRanges{
public:
    SummaryRanges(){};
    void AddNum(int val);
    vector<Interval> GetIntervals();

private:
    vector<Interval> intervalVec;

};


// 295. find median from data stream
class MedianFinder{
private:
    priority_queue<long> smallHeap, largeHeap;

public:
    void AddNum(int num);
    double FindMedian();
};


#endif // LEETCODE_H_INCLUDED
