#include "Leetcode.h"


vector<vector<string>> Solution::FindLadders(string beginWord, string endWord, unordered_set<string> &wordList){
    vector<vector<string>> ladders;
    vector<string> ladder;
    ladder.push_back(beginWord);
    unordered_set<string> startWords, endWords;
    startWords.insert(beginWord);
    endWords.insert(endWord);
    unordered_map<string, vector<string>> children;
    bool flip = true;
    if(SearchLadders(startWords, endWords, wordList, children, flip))
        GenLadders(beginWord, endWord, children, ladder, ladders);
    return ladders;
}


bool Solution::SearchLadders(unordered_set<string> &startWords, unordered_set<string> &endWords,
                   unordered_set<string> &wordList, unordered_map<string, vector<string>> &children, bool flip){
    flip = !flip;
    if(startWords.empty())
        return false;
    if(startWords.size() > endWords.size())
        return SearchLadders(endWords, startWords, wordList, children, flip);
    for(string word : startWords)
        wordList.erase(word);
    for(string word : endWords)
        wordList.erase(word);
    unordered_set<string> intermediate;
    bool done = false;
    for(string word : startWords){
        int n = word.length();
        string temp = word;
        for(int p = 0; p < n; p++){
            char letter = word[p];
            for(int i = 0; i < 26; i++){
                word[p] = 'a'+i;
                if(endWords.find(word) != endWords.end()){
                    done = true;
                    flip ? children[word].push_back(temp) : children[temp].push_back(word);
                }
                else if(!done && wordList.find(word) != wordList.end()){
                    intermediate.insert(word);
                    flip ? children[word].push_back(temp) : children[temp].push_back(word);
                }
            }
            word[p] = letter;
        }
    }
    return done || SearchLadders(endWords, intermediate, wordList, children, flip);
}


void Solution::GenLadders(string &beginWord, string &endWord, unordered_map<string, vector<string>> &children,
                          vector<string> &ladder, vector<vector<string>> &ladders){
    if(beginWord == endWord){
        ladders.push_back(ladder);
        return;
    }
    for(string child : children[beginWord]){
        ladder.push_back(child);
        GenLadders(child, endWord, children, ladder, ladders);
        ladder.pop_back();
    }
}
