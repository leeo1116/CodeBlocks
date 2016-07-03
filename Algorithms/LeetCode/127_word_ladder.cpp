#include "Leetcode.h"

int Solution::LadderLength(string beginWord, string endWord, unordered_set<string>& wordList){
    wordList.insert(endWord);
    queue<string> toVisit;
    AddNextWords(beginWord, wordList, toVisit);
    int distance = 2;

    while(!toVisit.empty()){
            int initSize = toVisit.size();
        for(int i = 0; i < initSize; i++){
            string word = toVisit.front();
            toVisit.pop();
            if(word == endWord)
                return distance;
            AddNextWords(word, wordList, toVisit);
        }
        distance++;
    }
    return 0;
}


void Solution::AddNextWords(string beginWord, unordered_set<string> &wordsList, queue<string> &toVisit){
    wordsList.erase(beginWord);
    for(int i = 0; i < (int) beginWord.length(); i++){
        char letter = beginWord[i];
        for(int j = 0; j < 26; j++){
            beginWord[i] = 'a'+j;
            if(wordsList.find(beginWord) != wordsList.end()){
                toVisit.push(beginWord);
                wordsList.erase(beginWord);
            }
        }
        beginWord[i] = letter;
    }
}
